#include <string.h>
#include <stdio.h>

#define MAX_LENGTH 32

void invertir(char arreglo[MAX_LENGTH], char arreglo2[MAX_LENGTH])
{
    int i=0;
    int d=strlen(arreglo);
    int tope=d;

    while(i<tope)
    {
        arreglo2[i]=arreglo[d-1];
        i++;
        d--;
    }

    arreglo2[i]='\0';
}

int main(void)
{
    char cadena[MAX_LENGTH], final[MAX_LENGTH];
    int len=0;
    int op = 0;

    do {
        printf(".:********REVISOR DE PALABRAS********:.\n\n");
        printf("Seleccione una opcion:\n\n");
        printf("1 - .:Verificar si es palindromo:.\n\n");
        printf("2 - .:Salir:.\n\n");
        scanf("%d", &op);

        if (op == 1) {
            printf(".:Dame cadena con todas minusculas o todas mayusculas:.\n\n");
            scanf("%s", cadena);

            // Crear cola doble para almacenar la cadena original y su reverso
            char deque[MAX_LENGTH * 2];
            int front = MAX_LENGTH, rear = MAX_LENGTH;
            int i;

            for (i = 0; cadena[i] != '\0'; i++) {
                deque[rear++] = cadena[i];
            }
            invertir(cadena, final);
            for (i = 0; final[i] != '\0'; i++) {
                deque[--front] = final[i];
            }

            // Comparar los caracteres de cada extremo de la cola doble
            int es_palindromo = 1;
            while (front < rear) {
                if (deque[front++] != deque[--rear]) {
                    es_palindromo = 0;
                    break;
                }
            }

            if (es_palindromo) {
                printf("La cadena ES un palindromo\n\n");
            } else {
                printf("La cadena NO es un palindromo\n\n");
            }
        } else if (op != 2) {
            printf("Opcion invalida\n");
        }
    } while (op != 2);

    return 0;
}