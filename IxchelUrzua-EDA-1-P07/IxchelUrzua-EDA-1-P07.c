#include <stdio.h>
#include <stdlib.h>

//Se define la estructura del nodo
typedef struct Nodo {
    int dato;
    struct Nodo* next;
} Nodo;

//Se define la función insertar
void insertar(Nodo** head, int dato) {
    Nodo* newNode = (Nodo*) malloc(sizeof(Nodo));
    newNode->dato = dato;
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        newNode->next = (*head)->next;
        (*head)->next = newNode;
        *head = newNode;
    }
}

//Se define la función buscar
int buscar(Nodo* head, int elemento_base) {
    Nodo* actual = head;
    int encontrado = 0;
    if (head != NULL) {
        do {
            if (actual->dato == elemento_base) {
                encontrado = 1;
                break;
            }
            actual = actual->next;
        } while (actual != head);
    }
    return encontrado;
}

//Función que imprime valores de cada nodo
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

//Función que se encarga de liberar la memoria
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

    printf("Ingrese el valor: ");
    scanf("%d", &elemento_base);

    printf("\nMostrando estructura:\n");
    mostrar(head);

    encontrado = buscar(head, elemento_base);

    if (encontrado) {
        printf("\n%d se encuentra en la estructura.\n", elemento_base);
    } else {
        printf("\n%d no se encuentra en la estructura.\n", elemento_base);
    }

    liberar(&head);

    return 0;
}
