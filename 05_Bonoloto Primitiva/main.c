#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define FILA 8
#define COLUMNA 6
#define NUMEROS 50

void rellauto(int combinacion[FILA][COLUMNA], int bloques)
{
	int i, j, k, l, val_ale, aux;
	int listanum[NUMEROS], auxiliarOrd[COLUMNA];
	
	for(j = 0; j < bloques; j++)
	{
		for(k = 0; k < NUMEROS; k++)
			listanum[k] = k + 1;
			
		for(k = 0; k < NUMEROS; k++)
		{
			val_ale = rand() % NUMEROS;
			aux = listanum[k];
			listanum[k] = listanum[val_ale];
			listanum[val_ale] = aux;
		}
		
		for(i = 0; i < COLUMNA; i++)
			auxiliarOrd[i] = listanum[i];
		
		for(k = 0; k < (COLUMNA - 1); k++)
			for(l = 0; l < (COLUMNA - k - 1); l++)
			{
				if(auxiliarOrd[l] > auxiliarOrd[l + 1])
				{
					aux = auxiliarOrd[l];
					auxiliarOrd[l] = auxiliarOrd[l + 1];
					auxiliarOrd[l + 1] = aux;
				}
			}
			
		for(i = 0; i < COLUMNA; i++)
			combinacion[i][j] = auxiliarOrd[i];
	}
}

void imprimir(int combinacion[FILA][COLUMNA], int bloques)
{
	int i, j;
	
	for(i = 0; i < bloques; i++)
	{
		printf("[COL]");
	}
	printf("\n");
	
	for(i = 0; i < bloques; i++)
	{
		printf("[%3d]", i + 1);
	}
	printf("\n");
	
	for(i = 0; i < COLUMNA; i++) //imprime el boleto por pantalla.
	{
		printf("________________________________________\n");
		
		for(j = 0; j < bloques; j++)
			printf("|%3d|", combinacion[i][j]);
		printf("\n");
	}
	printf("________________________________________\n");
}

void main(int argc, char *argv[])
{
	srand(time(NULL));
	
	unsigned opcion;
	int i, j, combinacion[FILA][COLUMNA], reintegro, bloques, resp;
	
	FILE *f;
	
	if(!(f = fopen("BonolotoPrimitiva.txt","w")))
	{
		printf("No se ha podido abrir el fichero\n");
		return;
	}
	
	printf("---BONOLOTO PRIMITIVA---\n");
	printf("1)Automatica\n");
	printf("2)Salir\n");
	
	do //MENU
	{
		printf("Escoge una opcion (1~2): ");
		scanf("%u", &opcion);
		fflush(stdin);
	}while(opcion < 1|| opcion > 2);
	
	switch(opcion)
	{
		case 1:
		{
			do //bloques loter�a
			{
				printf("Selecciona cuantos bloques deseas rellenar(1~8): ");
				scanf("%d", &bloques);
				fflush(stdin);
			}while(bloques < 1 || bloques > FILA);
			
			rellauto(combinacion, bloques);
			imprimir(combinacion, bloques);
			
			printf("\nGenerando Reintegro: \n");
			reintegro = rand() % 10;
			printf("Reintegro: %d", reintegro);
			printf("\n");
			
			do
			{
				printf("\nImprimir boleto(1/0)? ");
				scanf("%d", &resp);
				fflush(stdin);
			}while(resp < 0 || resp > 1);
			
			if(resp == 1)
			{
				fprintf(f, "---------BOLETO BONOLOTO/PRIMITIVA-----------\n");
				fprintf(f, "\n");
				
				for(i = 0; i < bloques ; i++)
					fprintf(f, "[ %3d ]\t", i + 1);
				fprintf(f, "\n");
				
				for(i = 0; i < COLUMNA; i++)
				{
					fprintf(f, "___________________________________________________________\n");
					for(j = 0; j < bloques; j++)
						fprintf(f, "|%3d|\t", combinacion[i][j]);
					
					fprintf(f, "\n");
				}
				fprintf(f, "___________________________________________________________\n");
				fprintf(f, "Reintegro: %d\n",reintegro);
			}
		}break;
		case 2:printf("Has salido del programa\n");break;
		default:printf("Error al reconocer el valor\n");break;
	}
	
	fclose(f);
	system("pause");
}