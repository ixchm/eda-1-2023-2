#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10//Tamaño maximo de la pila y cola

// define cÛmo se almacenan y acceden los elementos de una pila en la memoria de la computadora.
typedef struct {
    int items[MAX_SIZE];//Almacenar· elementos de la pila 
    int top;//representa posicion topede la pila en el arreglo items
} Stack;

//define un nodo de una lista enlazada
typedef struct node {
    int item;
    struct node* next;//puntero al siguiente nodo en la lista
} Node;

//Define una cola
typedef struct {
    Node* front;//apunta al primer nodo
    Node* rear;//apunta al ultimo nodo de la cola
} Queue;

// inserta un elemento en la pila
void push(Stack* s, int item) {
    if (s->top == 0) { //verifica si la pila esta llena
        printf("Stack overflow\n");
    } else {
        s->top--;//Si la pila no est· llena, decrementa el valor del tope de la pila
        s->items[s->top] = item;
    }
}

//implementa la operacion de eliminacion en la pila
int pop(Stack* s) {
    if (s->top == MAX_SIZE) { // verifica si el tope de la pila ha alcanzado el tamaÒo m·ximo
        printf("Stack underflow\n");
        return -1;
    } else {
        int item = s->items[s->top];
        s->top++;// se incrementa tope de la pila
        return item;
    }
}

//agrega nuevo elemento a la cola
void enqueue(Queue* q, int item) {
    Node* newNode = (Node*)malloc(sizeof(Node));//nuevo nodo
    newNode->item = item;
    newNode->next = NULL;
    if (q->rear == NULL) { // verifica cola esta vacia
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// elimina y devuelve el elemento del frente de la cola
int dequeue(Queue* q) {
    if (q->front == NULL) { //verifica que la cola esta vacia
        printf("Queue is empty\n");
        return -1;
    } else {
        Node* temp = q->front;// se crea puntero temporal
        int item = temp->item;//almacena el valor de item del nodo en una variable item
        q->front = q->front->next;
        if (q->front == NULL) {
            q->rear = NULL;
        }
        free(temp);
        return item;
    }
}

//imprime el ultimo elemento agregado a la cola.
void print_queue(Queue* q) {
    printf("Ultimo elemento formado en la cola: ");
    if (q->rear != NULL) {
        printf("%d\n", q->rear->item);
    } else {
        printf("La cola esta vacia\n");
    }
}
//valor tope es 1(primer elemento de la pila)
void print_stack(Stack* s) {
    printf("Ultimo elemento tope de la pila: ");
    if (s->top == MAX_SIZE) {
        printf("La pila esta vacia\n");
    } else {
        printf("%d\n", s->items[s->top]);
    }
}

int main() {
    
    //se est· creando una pila que contiene los n˙meros del MAX_SIZE hasta 1, en orden descendente.
    Stack s;
    s.top = MAX_SIZE;
    for (int i = MAX_SIZE; i >= 1; i--) {
        push(&s, i);
    }
    Queue q;
    q.front = NULL;
    q.rear = NULL;
    int choice, item;
    while (1) {
        printf("1. Formarse\n");
        printf("2. Salir\n");
        printf("Ingrese su eleccion: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                item = pop(&s);
                if (item == -1) {
                    printf("ya no hay turnos disponibles\n");
                } else {
                    enqueue(&q, item);
                    printf("El elemento se encuentra formadonen la cola con el turno %d\n", item);
                }
                break;
            case 2:
                print_queue(&q);
                print_stack(&s);
                exit(0);
            default:
                printf("Opcion invalida\n");
        }
    }
    return 0;
}