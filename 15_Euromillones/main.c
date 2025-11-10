#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define FILA 8
#define COLUMNA 5
#define ESTRELLAS 2

#define NUMEROS 49
#define NUMEROS_ESTR 12

void rellauto(int combinacion[FILA][COLUMNA], int estrellas[ESTRELLAS], int bloques)
{
	int i, j, k, l, val_ale, aux;
	int listanum[NUMEROS], auxiliarOrd[COLUMNA], estrellasAux[NUMEROS_ESTR];
	
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
	
	for (i = 0; i < NUMEROS_ESTR; i++)
		estrellasAux[i] = i + 1;
	
	for(i = 0; i < NUMEROS_ESTR; i++)
	{
		val_ale = rand() % NUMEROS_ESTR;
		aux = estrellasAux[i];
		estrellasAux[i] = estrellasAux[val_ale];
		estrellasAux[val_ale] = aux;
	}
	
	estrellas[0] = estrellasAux[0];
	estrellas[1] = estrellasAux[1];
	
	if(estrellas[0] > estrellas[1])
	{
		aux = estrellas[0];
		estrellas[0] = estrellas[1];
		estrellas[1] = aux;
	}
}

void imprimir(int combinacion[FILA][COLUMNA], int estrellas[ESTRELLAS], int bloques)
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
	
	printf("\nEstrellas generadas:\n");
	for(i = 0; i < ESTRELLAS; i++)
		printf("Estrella %d: %d\n", i + 1, estrellas[i]);
}

void main(int argc, char *argv[])
{
	srand(time(NULL));
	
	int combinacion[FILA][COLUMNA], estrellas[ESTRELLAS], i, j, bloques, resp;
	unsigned opcion;
	
	FILE *f;
	
	if(!(f=fopen("Euromillones.txt","w")))
	{
		printf("No se ha podido abrir el fichero\n");
		return;
	}
	
	printf("---EUROMILLONES---\n");
	printf("1)Automatica\n");
	printf("2)Salir\n");
	
	do //MENU
	{
		printf("Selecciona la opcion (1~2): ");
		scanf("%u", &opcion);
		fflush(stdin);
	}while(opcion < 1 || opcion > 2);
	
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
			
			rellauto(combinacion, estrellas, bloques);
			imprimir(combinacion, estrellas, bloques);
			
			do
			{
				printf("\nImprimir boleto(1/0)? ");
				scanf("%d", &resp);
				fflush(stdin);
			}while(resp < 0 || resp > 1);
			
			if(resp == 1)
			{
				fprintf(f, "---------BOLETO EUROMILLONES-----------\n");
				fprintf(f, "\n");
				
				for(i = 0; i < bloques; i++)
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
				
				for(i = 0; i < ESTRELLAS; i++)
					fprintf(f, "Estrella %d : %d\n", i + 1, estrellas[i]);
			}
			printf("\n");
		}break;
		
		case 2:printf("Has salido del programa\n");break;
		default:printf("Error al reconocer el valor\n");break;
	}
	fclose(f);

	system("pause");
}