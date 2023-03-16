#include <stdio.h>
#include <stdlib.h>
//Variables globales
int i,j,x,y;
char X='x',Y='y';

//Menu
int pedirOpcion(int opMax)
{
    int op;
    char opChar[10];
    
    fflush(stdin);//Vaciando buffer
    do                                                                                                                                               
    {
        printf("-> "); gets(opChar);//gets no tiene limitante en cuanto al tamaño de la cadena(lee)
        op = atoi(opChar);//Convirtiendo el string a entero
        if(op < 1)//Comprobando que la opcion sea valida
        printf("Opcion invalida\n");
        else if(op > opMax)
        printf("Opcion invalida. El maximo es %d\n", opMax);
        printf("\n");
    } while (op<1 || op > opMax);//ejecutar en bucle hasta que se cumpla una condicion
    fflush(stdin);

    return op;
}
int menuPrincipal()
{
    system("cls");//Limpiando la pantalla de la terminal
    printf("*******MENU PRINCIPAL*******\n");
    printf(".:Simulador de movimiento para la torre, el alfil, la reina, el rey y el caballo:.\n");
    printf("1)Simulador del alfil\n");
    printf("2)Simulador de la torre\n");
    printf("3)Simulador de la reina\n");
    printf("4)Simulador del rey\n");
    printf("5)Simulador del caballo\n");
    printf("6)Salir\n\n");

    printf(".:Seleccione una opcion:.\n");
    return pedirOpcion(6);//El numero maximo de opciones es 3 (en este caso)
}
int menuRetorno()
{
printf("\n*******MENU DE RETORNO*******\n");
printf("1)Repetir simulacion\n");
printf("2)Volver al menu principal\n");
printf("3)Salir\n\n");

printf(".:Seleccione una opcion:.\n");
return pedirOpcion(3);
}

struct Alfil {
    int x;
    int y;
};



void movimientoAlfil() {
int tablero[9][9];
struct Alfil alfil;
printf("\nIngrese la posicion del alfil en este formato -> x,y:");
scanf("%d,%d", &alfil.x, &alfil.y);
printf("El alfil esta en %d,%d\n", alfil.x, alfil.y);

    // crear toda la matriz
    for (i=1; i<9; i++){
    for (j=1; j<9; j++){ 
    tablero[i][j]=0; 
        }
    }

    
	//inferior izquierda
	for ( i = alfil.x, j = alfil.y; (j<9&&i>=1); i--, j++) {
    	tablero[i][j]=1;                
	}

	//inferior derecha
	for (i = alfil.x, j = alfil.y; (i>=1&&j<9); i++, j++){
    	tablero[i][j]=1; 
	}

	//superior derecha
	for (i = alfil.x, j = alfil.y; (i>1&&j>=1); i++, j--){
   		tablero[i][j]=1; 
	}

	//superior izquierda
	for (i = alfil.x, j = alfil.y; (i>=1&&j>=1); i--, j--){
    	tablero[i][j]=1; 
	}
    	

    tablero[alfil.x][alfil.y] = 9; // la posicion del alfil
    
    for (j=1; j<9; j++)
	{
        for (i=1; i<9; i++){ 
                if(tablero[i][j]==0){
                    printf("*\t"); 
                } 
                if(tablero[i][j]==1){
                    printf("P\t");
                } 
                if(tablero[i][j]==9){
                    printf("A\t");
                } 
        }
            printf("\n\n"); 
    }
}
struct Torre {
    int x;
    int y;
};
void movimientoTorre() {
    int tablero[9][9];
    struct Torre torre;
    printf("\nIngrese la posicion de la torre en este formato -> x,y:");
    scanf("%d,%d", &torre.x, &torre.y);

    // crear toda la matriz
    for (int i = 1; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            tablero[i][j] = 0;
        }
    }

    // Arriba
    for (int i = torre.x, j = torre.y; (i < 9 && j >= 0); j--) {
        tablero[i][j] = 1;
    }

    // Derecha
    for (int i = torre.x, j = torre.y; (i < 9 && j >= 0); i++) {
        tablero[i][j] = 1;
    }

    // Izquierda
    for (int i = torre.x, j = torre.y; (i > 0 && j >= 1); i--) {
        tablero[i][j]=1;
    }
        // Abajo
for (int i = torre.x, j = torre.y; (i > 0 && j < 9); j++) {
    tablero[i][j] = 1;
}

tablero[torre.x][torre.y] = 8; // la posicion de la torre

printf("La torre esta en %d,%d\n", torre.x, torre.y);
for (int j = 1; j < 9; j++) {
    for (int i = 1; i < 9; i++) {
        if (tablero[i][j] == 0) {
            printf("*\t");
        }
        if (tablero[i][j] == 1) {
            printf("P\t");
        }
        if (tablero[i][j] == 8) {
            printf("T\t");
        }
    }
    printf("\n\n");
}
}
struct tablero {
    char pieza;
    char espacio;
    char fin;
};

void movimientoReina(int *x, int *y)
{
    int i,j;
    struct tablero tablero[9][9];
    printf("\nIngrese la posicion de la torre en este formato -> x,y:"); 
    scanf("%d,%d",x,y); 
    printf("La reina esta en %d,%d\n",*x,*y); 

    //Inicializar el tablero con asteriscos
    for(i=1; i<9; i++)
    {
        for(j=1; j<9; j++)
        {
            tablero[i][j].pieza = '*';
            tablero[i][j].espacio = '\t';
            tablero[i][j].fin = '\0';
        }
    }

    //Colocar la reina en el tablero
    tablero[*x][*y].pieza = 'Q';

    // horizontal y vertical
    for(i=1; i<9; i++)
    {
        if(tablero[*x][i].pieza != 'Q')
        {
            tablero[*x][i].pieza = 'X';
        }
        if(tablero[i][*y].pieza != 'Q')
        {
            tablero[i][*y].pieza = 'X';
        }
    }

    //izquierda arriba
    i = *x - 1;
    j = *y - 1;
    while(i > 0 && j > 0)
    {
        if(tablero[i][j].pieza != 'Q')
        {
            tablero[i][j].pieza = 'X';
        }
        i--;
        j--;
    }

    // diagonal izquierda abajo
    i = *x - 1;
    j = *y + 1;
    while(i > 0 && j < 9)
    {
        if(tablero[i][j].pieza != 'Q')
        {
            tablero[i][j].pieza = 'X';
        }
        i--;
        j++;
    }

    // diagonal derecha arriba
    i = *x + 1;
    j = *y - 1;
    while(i < 9 && j > 0)
    {
        if(tablero[i][j].pieza != 'Q')
        {
            tablero[i][j].pieza = 'X';
        }
        i++;
        j--;
    }

    //diagonal derecha abajo
    i = *x + 1;
    j = *y + 1;
    while(i < 9 && j < 9)
    {
        if(tablero[i][j].pieza != 'Q')
        {
            tablero[i][j].pieza = 'X';
        }
        i++;
        j++;
    }

    //Mostrar el tablero 
    for(i=1; i<9; i++)
    {
        printf("\n\n");
        for(j=1; j<9; j++)
        {
            printf("%c%c%c", tablero[j][i].pieza, tablero[j][i].espacio, tablero[j][i].fin);
        }
    }
}

void movimientoRey(int* x, int* y)
{
    int i,j;
    struct tablero tablero[9][9];
    printf("\nIngrese la posicion de el rey en este formato -> x,y:"); 
    scanf("%d,%d",x,y); 
    printf("El rey esta en %d,%d\n",*x,*y); 

    // Inicializar el tablero con asteriscos
    for(i=1; i<9; i++)
    {
        for(j=1; j<9; j++)
        {
            tablero[i][j].pieza = '*';
            tablero[i][j].espacio = '\t';
            tablero[i][j].fin = '\0';
        }
    }

    // Colocar el rey en el tablero
    tablero[*x][*y].pieza = 'K';

    // Horizontal y vertical
    for(i=*x-1; i<=*x+1; i++)
    {
        for(j=*y-1; j<=*y+1; j++)
        {
            if(i>=1 && i<=8 && j>=1 && j<=8 && tablero[i][j].pieza != 'K')
            {
                tablero[i][j].pieza = 'X';
            }
        }
    }

    // Mostrar el tablero 
    for(i=1; i<9; i++)
    {
        printf("\n\n");
        for(j=1; j<9; j++)
        {
            printf("%c%c%c", tablero[j][i].pieza, tablero[j][i].espacio, tablero[j][i].fin);
        }
    }
}
struct Caballo {
    int x;
    int y;
};

void movimientoCaballo() {
    int tablero[9][9];
    struct Caballo caballo;
    printf("\nIngrese la posicion del caballo en este formato -> x,y:");
    scanf("%d,%d", &caballo.x, &caballo.y);

    // Crear toda la matriz
    for (int i = 1; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            tablero[i][j] = 0;
        }
    }

    // Movimientos del caballo
    if (caballo.x + 2 < 9 && caballo.y + 1 < 9) {
        tablero[caballo.x + 2][caballo.y + 1] = 1;
    }

    if (caballo.x + 2 < 9 && caballo.y - 1 > 0) {
        tablero[caballo.x + 2][caballo.y - 1] = 1;
    }

    if (caballo.x - 2 > 0 && caballo.y + 1 < 9) {
        tablero[caballo.x - 2][caballo.y + 1] = 1;
    }

    if (caballo.x - 2 > 0 && caballo.y - 1 > 0) {
        tablero[caballo.x - 2][caballo.y - 1] = 1;
    }

    if (caballo.x + 1 < 9 && caballo.y + 2 < 9) {
        tablero[caballo.x + 1][caballo.y + 2] = 1;
    }

    if (caballo.x + 1 < 9 && caballo.y - 2 > 0) {
        tablero[caballo.x + 1][caballo.y - 2] = 1;
    }

    if (caballo.x - 1 > 0 && caballo.y + 2 < 9) {
        tablero[caballo.x - 1][caballo.y + 2] = 1;
    }

    if (caballo.x - 1 > 0 && caballo.y - 2 > 0) {
        tablero[caballo.x - 1][caballo.y - 2] = 1;
    }

    tablero[caballo.x][caballo.y] = 8; // la posicion del caballo

    printf("El caballo esta en %d,%d\n", caballo.x, caballo.y);
    for (int j = 1; j < 9; j++) {
        for (int i = 1; i < 9; i++) {
            if (tablero[i][j] == 0) {
                printf("*\t");
            }
            if (tablero[i][j] == 1) {
                printf("P\t");
            }
            if (tablero[i][j] == 8) {
                printf("C\t");
            }
        }
        printf("\n\n");
    }
}
int main()//inicio de la ejecución del programa
{
	int opcion;
	
	inicio://te lleva al menu principal
		opcion= menuPrincipal();//la funcion menuPrincipal imprime el menú
		
		seleccion://apertura para seleccionar caso
		system("cls");
		switch (opcion)
		{
			case 1: movimientoAlfil(); break;
			case 2: movimientoTorre();break;
			case 3: movimientoReina(&x, &y);break;
			case 4: movimientoRey(&x, &y);break;
			case 5: movimientoCaballo();break;
			default: goto salir; break;//termina el switch y sale del programa
		}
		
		switch (menuRetorno())
		{
			case 1: goto seleccion; break;
			case 2: goto inicio; break;
			default: break;//termina el switch
		}
		salir:
			printf("\nGracias por usar el programa :)\n\n");
			
		return 0;
}
