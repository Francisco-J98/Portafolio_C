#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define  FILA 3
#define  COLUMNA 4

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

void lim_mat(int matriz[FILA][COLUMNA], int filaParam, int columnaParam, int lim_fil, int lim_col)
{
    int i, j;
    for (i = filaParam; i < FILA && i <= lim_fil; i ++)
	{
        for (j = columnaParam; j < COLUMNA && j <= lim_col; j ++)
		{
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void main()
{
	char resp;
    int matriz[FILA][COLUMNA], filaValor, columnaValor, lim_fil, lim_col;
    
    rell_mat(matriz);
    impr_mat(matriz);
    
	do
	{
        do
		{
            printf("Valor de la fila (submatriz): ");
            scanf("%d", &filaValor);
            fflush(stdin);
        }while (filaValor < 0 || filaValor > (FILA - 1));
        
        do
		{
            printf("Valor de la columna (submatriz): ");
            scanf("%d", &columnaValor);
            fflush(stdin);
        }while (columnaValor < 0 || columnaValor > (COLUMNA - 1));
        
        do
		{
            printf("Valor de la amplitud de la fila: ");
            scanf("%d", & lim_fil);
            fflush(stdin);
        }while (lim_fil < 1 || lim_fil > FILA);
        
        do
		{
            printf("Valor de la amplitud de la columna: ");
            scanf("%d", & lim_col);
            fflush(stdin);
        }while (lim_col < 1 || lim_col > COLUMNA);
        
        lim_mat(matriz, filaValor, columnaValor, lim_fil, lim_col);
        
        printf("Deseas seguir (1/0): ");
        scanf("%c", &resp);
        fflush(stdin);
    }while (resp != '0');
}