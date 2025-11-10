#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define N 10

void main(int argc, char *argv[])
{
	char opcion;
	int i, j, val_ale, ale_signo, mat_trisup[N][N], mat_diag[N][N], mat_sim[N][N];
	
	ale_signo = rand() % 2;
	val_ale = rand() % 101;
	
	srand(time(NULL));
	
	do
	{
		printf("-------MENU-------\n");
		printf("0) Salir\n");
		printf("1) Matriz Triangular Superior\n");
		printf("2) Matriz Simetrica\n");
		printf("3) Matriz Diagonal\n");
		printf("------------------\n");
		
		do
		{
			printf("Escoge una opcion (0~3): ");
			scanf("%c", &opcion);
			fflush(stdin);
			
			switch(opcion)
			{
				default:printf("Error! Valor no reconocido como opcion.\n");break;
				case '0':printf("Has salido del programa.\n");break;
				case '1':
				{
					printf("\n-----------------MATRIZ TRIANGULAR SUPERIOR-----------------\n");
					
					for(i = 0; i < N; i++)
						for(j = 0; j < N; j++)
						{
							if(i > j)
								mat_trisup[i][j] = 0;
							else
							{
								ale_signo = rand() % 2;
								val_ale = rand() % 101;
								
								if(ale_signo == 1)
									mat_trisup[i][j] = val_ale * (-1);
								else
									mat_trisup[i][j] = val_ale;
							}
						}
					
					for(i = 0; i < N; i++)
					{
						for(j = 0; j < N; j++)
							printf("%5d|", mat_trisup[i][j]);
						printf("\n");
					}
				}break;
				
				case '2':
				{
					printf("\n-----------------MATRIZ SIMETRICA-----------------\n");
					
					for(i = 0; i < N; i++)
						for(j = i; j < N; j++)
						{
							val_ale = rand() % 101; 
							ale_signo = rand() % 2;
							if(ale_signo == 1)
								mat_sim[i][j] = val_ale * (-1);
							else
								mat_sim[i][j] = val_ale;
							mat_sim[j][i] = mat_sim[i][j]; 
						}
						
					for(i = 0; i < N; i++)
					{
						for(j = 0; j < N; j++)
							printf("%4d |", mat_sim[i][j]);
						printf("\n");
					}
				}break;
				
				case '3':
				{
					printf("\n-----------------MATRIZ DIAGONAL-----------------\n");
					for(i = 0; i < N; i++)
						for(j = 0; j < N; j++)
						{
							ale_signo = rand()%2;
							val_ale = rand()%101;
							
							if(i == j)
							{
								if(ale_signo == 1)
									mat_diag[i][j] = val_ale * (-1);
								else
									mat_diag[i][j] = val_ale;
							}
							else
								mat_diag[i][j] = 0;
						}
						
					for(i = 0; i < N; i++)
					{
						for(j = 0; j < N; j++)
							printf("%5d|", mat_diag[i][j]);
						printf("\n");
					}
				}break;
			}
		}while(opcion < '0' || opcion > '3');
	}while(opcion != '0');
	
	system("pause");
}