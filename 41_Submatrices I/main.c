#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define  FILA 10
#define  COLUMNA 15

void rell_mat(int matriz[FILA][COLUMNA])
{
    int i, j;
    
    printf("Introduzca los valores de la matriz: ");
    for (i = 0; i < FILA; i ++) 
        for (j = 0; j < COLUMNA; j ++)
		{
            printf("\nMatriz[%d][%d]: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
}

void impr_mat(int matriz[FILA][COLUMNA])
{
    int i, j;
    for (i = 0; i < FILA; i ++)
	{
        for (j = 0; j < COLUMNA; j ++) 
            printf(" %d ", matriz[i][j]);    
        printf("\n");
    }
}

void sub_mat(int matriz[FILA][COLUMNA], int fila, int columna)
{
    int i, j;
    for (i = fila; i < FILA; i ++)
	{
        for (j = columna; j < COLUMNA; j ++) 
            printf(" %d ", matriz[i][j]);    
        printf("\n");
    }
}

void main()
{
	
	char resp;
    int matriz[FILA][COLUMNA], filaValor, columnaValor;
    
    rell_mat(matriz);
    impr_mat(matriz);
	
	do
	{
		do
		{
            printf("Valor de la fila (submatriz): ");
            scanf("%d", &filaValor);
            fflush(stdin);
        }while(filaValor < 0 || filaValor > (FILA - 1));
        
        do
		{
            printf("Valor de la columna (submatriz): ");
            scanf("%d", &columnaValor);
            fflush(stdin);
        }while(columnaValor < 0 || columnaValor > (COLUMNA - 1));
        
        sub_mat(matriz, filaValor, columnaValor);
        printf("Deseas seguir (1/0): ");
        scanf("%c", & resp);
        fflush(stdin);   
    }while(resp != '0');
}