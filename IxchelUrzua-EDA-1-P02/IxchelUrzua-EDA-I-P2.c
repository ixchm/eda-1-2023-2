#include <stdio.h>
#include <string.h>

int coordenadas (char n);
void movimientoReina(int *x, int *y);
void movimientoRey(int *x, int *y);

char X='x',Y='y';

int main()
{
    int opcion, x, y;

    do
    {
        printf("\n\n\t\tMenu de seleccion.");
        printf("\n\n\t1) Reina.\n\t2) Rey.\n\t3) Salir.\n\n\tOpcion: ");
        scanf("%i",&opcion);
        printf("\n");
        
        switch(opcion){
            
            case 1:
                movimientoReina(&x, &y);
            
            break;
            
            case 2:
                movimientoRey(&x, &y);
            
            break;
            
            case 3:
            break;
            
            default:
                printf("\n\tOpcion no valida.");
            break;
        }

    }while(opcion != 3);
}                                                                                                                       

int coordenadas(char n)
{
    int n1;
    
    printf("\tDame coordenada %c: ",n);
    scanf("%i",&n1);
    
    return n1;
}

void movimientoReina(int *x, int *y)
{
	int i,j;
    char tablero[9][9][4];



    for(i=1; i<9; i++)
    {
        for(j=1; j<9; j++)
        {
            strcpy(tablero[i][j], "*\t");
        }
    }

    *x = coordenadas(X);
    *y = coordenadas(Y);

    strcpy(tablero[*x][*y], "Q\t");


    //horizontal
  	for(i=1; i<9; i++)
    {
        if(strcmp(tablero[*x][*y],tablero[i][*y]) != 0)
        {
            strcpy(tablero[i][*y], "X\t");
        }
    }

    //vertical
    for(i=1; i<9; i++)
    {
       if(strcmp(tablero[*x][*y],tablero[*x][i]) != 0)
        {
            strcpy(tablero[*x][i], "X\t");

        }
    }
    


    //Diagonal izquierda arriba
    for(i=*x,j=*y; i>-1,j>-1; i--,j--)
    {
        if(strcmp(tablero[*x][*y],tablero[i][j]) != 0)
        {
            strcpy(tablero[i][j], "X\t");
        }
    }

	//Diagonal izquierda abajo
    for(i=*x,j=*y; i>-1, j<9; i--,j++)
    {
        if(strcmp(tablero[*x][*y],tablero[i][j]) != 0)
        {
            strcpy(tablero[i][j], "X\t");
        }
    }

    //Diagonal derecha arriba
    for(i=*x,j=*y; i<9, j>-1; i++,j--)
    {
        if(strcmp(tablero[*x][*y],tablero[i][j]) != 0)
        {
            strcpy(tablero[i][j], "X\t");
        }
    }
    
    //diagonal derecha abajo
    for(i=*x,j=*y; j<9, i<9; i++,j++)
    {
       if(strcmp(tablero[*x][*y],tablero[i][j]) != 0)
        {
            strcpy(tablero[i][j], "X\t");
        }
    }
    
    for(i=1; i<9; i++)
    {
        printf("\n\n");
        for(j=1; j<9; j++)
        {
            printf("%s",tablero[j][i]);
        }
    }
}

void movimientoRey(int *x, int *y)
{
    int i, j;
    char tablero[9][9][6];
  
    for(i=1; i<9; i++)
    {
        for(j=1; j<9; j++)
        {
            strcpy(tablero[i][j], "*\t");
        }
    }
    
    *y = coordenadas(X);
    *x = coordenadas(Y);
   
    strcpy(tablero[*x][*y], "R\t");
    strcpy(tablero[*x-1][*y], "X\t");
    strcpy(tablero[*x+1][*y], "X\t");
    strcpy(tablero[*x][*y-1], "X\t");
    strcpy(tablero[*x][*y+1], "X\t");
    strcpy(tablero[*x-1][*y-1], "X\t");
    strcpy(tablero[*x-1][*y+1], "X\t");
    strcpy(tablero[*x+1][*y-1], "X\t");
    strcpy(tablero[*x+1][*y+1], "X\t");
    
    for(i=1; i<9; i++)
    {
        printf("\n\n");
        for(j=1; j<9; j++)
        {
            printf("%s",tablero[i][j]);
        }
    }
}
