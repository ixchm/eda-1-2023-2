#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo* next;
    struct Nodo* prev;
} Nodo;
 void ordenar(Nodo** head) {
    Nodo* actual = *head;
    int temp;
    do {
        Nodo* siguiente = actual->next;
        while (siguiente != *head) {
            if (actual->dato > siguiente->dato) {
                temp = actual->dato;
                actual->dato = siguiente->dato;
                siguiente->dato = temp;
            }
            siguiente = siguiente->next;
        }
        actual = actual->next;
    } while (actual != *head);
}

void insertar(Nodo** head, int dato) {
    Nodo* newNode = (Nodo*) malloc(sizeof(Nodo));
    newNode->dato = dato;
    if (*head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        *head = newNode;
    } else {
        Nodo* actual = *head;
        while (actual->next != *head && actual->next->dato < newNode->dato) {
            actual = actual->next;
        }
        newNode->next = actual->next;
        newNode->prev = actual;
        actual->next->prev = newNode;
        actual->next = newNode;
    }
    ordenar(head);
}

void insertar_en_posicion(Nodo** head, int dato, int posicion) {
    if (posicion < 1) {
        printf("La posición debe ser mayor o igual a 1.\n");
        return;
    }
    Nodo* actual = *head;
    Nodo* newNode = (Nodo*) malloc(sizeof(Nodo));
    newNode->dato = dato;
    int i = 1;
    while (actual != NULL && i < posicion) {
        actual = actual->next;
        i++;
    }
    if (actual == NULL) {
        printf("ERROR.\n");
        return;
    }
    newNode->prev = actual->prev;
    newNode->next = actual;
    actual->prev->next = newNode;
    actual->prev = newNode;
    if (posicion == 1) {
        *head = newNode;
    }
}

void eliminar(Nodo** head, int dato) {
    if (*head == NULL) {
        printf("La lista está vacía.\n");
        return;
    }
    Nodo* actual = *head;
    int encontrado = 0;
    do {
        if (actual->dato == dato) {
            encontrado = 1;
            break;
        }
        actual = actual->next;
    } while (actual != *head);
    if (!encontrado) {
        printf("El dato no está en la lista.\n");
        return;
    }
    if (actual == *head) {
        *head = (*head)->next;
    }
    actual->prev->next = actual->next;
    actual->next->prev = actual->prev;
    free(actual);
    ordenar(head);
}


void mostrar(Nodo* head) {
    Nodo* actual = head;
    if (head != NULL) {
        do {
            printf("%d ", actual->dato);
            actual = actual->next;
        } while (actual != head);
        printf("\n");
    }
}

void liberar(Nodo** head) {
    Nodo* actual = (*head)->next;
    Nodo* temp;
    while (actual != *head) {
        temp = actual;
        actual = actual->next;
        free(temp);
    }
    free(*head);
    *head = NULL;
}
   
int main() {
    Nodo* head = NULL;
    int arreglo[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arreglo) / sizeof(int);
    int elemento_base, encontrado = 0;

    for (int i = 0; i < n; i++) {   
        insertar(&head, arreglo[i]);
        
    }

  
    printf("\nSeleccione una opcion:\n");
    printf("1. Insertar\n");
    printf("2. Eliminar\n");
    int opcion;
    scanf("%d", &opcion);

    if (opcion == 1) {
        int dato, posicion;
        printf("\nINSERTAR ELEMENTO\n");
        printf("\nIngrese el dato que desea añadir: ");
        scanf("%d", &dato);
        printf("\nIngrese la posicion en la que lo desea insertar: ");
        scanf("%d", &posicion);
        insertar_en_posicion(&head, dato, posicion);
    } else if (opcion == 2) {
        int dato;
        printf("\nELIMINAR ELEMENTO \n");
        printf("\nIngrese la posicion del elemento que desea eliminar: ");
        scanf("%d", &dato);
        eliminar(&head, dato);
    } else {
        printf("Opcion invalida.\n");
        liberar(&head);
        return 0;
    }

    printf("\nEstructura resultante:\n");
    mostrar(head);

    liberar(&head);

    return 0;
}