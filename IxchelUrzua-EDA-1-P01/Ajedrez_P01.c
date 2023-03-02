#include <stdio.h>
#include <stdlib.h>
//Variables globales
int i,j,x,y;

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
    printf(".:Simulador de movimiento para la torre y el alfil:.\n");
    printf("1)Simulador del alfil\n");
    printf("2)Simulador de la torre\n");
    printf("3)Salir\n\n");

    printf(".:Seleccione una opcion:.\n");
    return pedirOpcion(3);//El numero maximo de opciones es 3 (en este caso)
}
int menuRetorno()
{
printf("*******MENU DE RETORNO*******\n");
printf("1)Repetir simulacion\n");
printf("2)Volver al menu principal\n");
printf("3)Salir\n\n");

printf(".:Seleccione una opcion:.\n");
return pedirOpcion(3);
}
void movimientoAlfil()
{
int tablero[9][9];
printf("\nIngrese la posicion del alfil en este formato -> x,y:"); 
    scanf("%d,%d",&x,&y); 

// crear toda la matriz 

    for (i=1; i<9; i++){
        for (j=1; j<9; j++){ 
            tablero[i][j]=0; 
        }
    }
      
//inferior izquierda
for ( i=x, j=y; (j<9&&i>=1); i--, j++) {
    tablero[i][j]=1;                
}

//inferior derecha
for (i=x, j=y; (i>=1&&j<9); i++, j++){
    tablero[i][j]=1; 
}

//superior derecha
for (i=x, j=y; (i>1&&j>=1); i++, j--){
    tablero[i][j]=1; 
}

//superior izquierda
for (i=x, j=y; (i>=1&&j>=1); i--, j--){
    tablero[i][j]=1; 
}

                     

    tablero[x][y]=8; // la posicion del alfil 
    
    
    printf("El alfil esta en %d,%d\n",x,y);  
    for (j=1; j<9; j++){
        for (i=1; i<9; i++){ 
                if(tablero[i][j]==0){
                    printf("*\t"); 
                } 
                if(tablero[i][j]==1){
                    printf("P\t");
                } 
                if(tablero[i][j]==8){
                    printf("A\t");
                } 
        }
            printf("\n\n"); 
    }  
}
void movimientoTorre()
{
int tablero[9][9];
printf("\nIngrese la posicion de la torre en este formato -> x,y:"); 
    scanf("%d,%d",&x,&y); 

// crerar toda la matriz 

    for (i=1; i<9; i++){
        for (j=1; j<9; j++){ 
            tablero[i][j]=0; 
        }
    }

// Arriba
for ( i=x, j=y; (i<9&&j>=0);j-- ) {
    tablero[i][j]=1;                
}   
//Derecha 
for ( i=x, j=y; (i<9&&j>=0);i++ ) {
   tablero[i][j]=1;                
}     
//izquierda             
for (i=x, j=y; (i>0&&j>=1); i--){
    tablero[i][j]=1; 
}  

//Abajo
for ( i=x, j=y; (i>0&&j<9);j++ ) {
    tablero[i][j]=1;  
}

    tablero[x][y]=8; // la posicion de la torre 
    
    
    printf("La torre esta en %d,%d\n",x,y);  
    for (j=1; j<9; j++){
        for (i=1; i<9; i++){ 
                if(tablero[i][j]==0){
                    printf("*\t"); 
                } 
                if(tablero[i][j]==1){
                    printf("P\t");
                } 
                if(tablero[i][j]==8){
                    printf("T\t");
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
