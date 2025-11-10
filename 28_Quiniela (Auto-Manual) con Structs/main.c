#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define FILAS 8
#define COLUMNAS 14
#define PLENOAL15 2

//QUINIELA (2017) - AUTO-MANUAL con STRUCTS

typedef struct{
	char pleno15[PLENOAL15];
	char quiniela[FILAS][COLUMNAS];
	
	int bloques;
}QUINIELA;

void rellauto(QUINIELA *Q1)
{
	int i, j;
	char result[3] = "1X2";
	char partidazo[4] = "012M";
	
	for(i = 0; i < ((*Q1).bloques); i++)
		for(j = 0; j < COLUMNAS; j++)
			(Q1 -> quiniela[i][j]) = result[rand() % 3];
	
	for(i = 0; i < PLENOAL15; i++)
		(Q1 -> pleno15[i]) = partidazo[rand() % 4];
}

void rellman(QUINIELA *Q1)
{
	int i, j;
	
	for(i = 0; i < (Q1 -> bloques); i++)
		for(j = 0; j < COLUMNAS; j++)
			do
			{
				printf("Partido[%d][%d]: ", i + 1, j + 1);
				scanf("%c", &Q1 -> quiniela[i][j]);
				fflush(stdin);
			}while(Q1 -> quiniela[i][j] != '1' && Q1 -> quiniela[i][j] != '2' && Q1 -> quiniela[i][j] != 'X');
			
	for(i = 0; i < PLENOAL15; i++)
		do
		{
			printf("\nPleno al 15, Equipo %d: ", i +1);
			scanf("%c", &Q1 -> pleno15[i]);
			fflush(stdin);
		}while(Q1 -> pleno15[i] != '0' && Q1 -> pleno15[i] != '1' && Q1 -> pleno15[i] != '2' && Q1 -> pleno15[i] != 'M');
}

void imprquin(QUINIELA *Q1)
{
	int i, j;
	
	printf("-----QUINIELA VISTA PREVIA-----\n");
	
	for(j = 0; j < COLUMNAS; j++)
	{
		for(i = 0; i < (Q1 -> quiniela[i][j]); i++)
			printf("%c \t", Q1 -> quiniela[i][j]);
		printf("\n");
	}
	
	printf("Equipo 1: %c   \tEquipo 2: %c ", Q1 -> pleno15[0], Q1 -> pleno15[1]);
}

int main(int argc, char *argv[])
{
	char resp;
	QUINIELA Q1;
	int i, j, opcion;
	srand(time(NULL));
	
	FILE *f;
	
	if(!(f = fopen("BoletoQuiniela.txt","a")))
	{
		printf("No se ha podido abrir el fichero\n");
		return 1;
	}
	
	do
	{
		printf("QUINIELA CON APUESTAS AUTOMATICAS Y MANUALES\n");
		printf("1)AUTOMATICA\n");
		printf("2)MANUAL\n");
		
		do
		{
			printf("Selecciona una opcion (1~2): ");
			scanf("%u", &opcion);
			fflush(stdin);
		}while(opcion < 1 || opcion > 2);
		
		switch(opcion)
		{
			case 1:
			{
				do
				{
					printf("Selecciona cuantos bloques deseas rellenar(1~8): ");
					scanf("%d", &Q1.bloques);
					fflush(stdin);
				}while(Q1.bloques < 1 || Q1.bloques > FILAS);
				
				rellauto(&Q1);
				imprquin(&Q1);
				
				fprintf(f, "\n-----QUINIELA AUTOMATICA-----\n");
					
				for(j = 0; j < COLUMNAS; j++)
				{
					for(i = 0; i < (Q1.bloques); i++)
						fprintf(f, "%c \t", Q1.quiniela[i][j]);
					fprintf(f, "\n");
				}
					
				fprintf(f, "Equipo 1: %c   \tEquipo 2: %c ", Q1.pleno15[0], Q1.pleno15[1]);
				printf("\nApuesta guardada satisfactoriamente en el fichero\n");	
			}break;
			
			case 2:
			{
				do
				{
					printf("Selecciona cuantos bloques deseas rellenar(1~8): ");
					scanf("%d", &Q1.bloques);
					fflush(stdin);
				}while(Q1.bloques < 1 || Q1.bloques > FILAS);
				
				rellman(&Q1);
				imprquin(&Q1);
					
				fprintf(f, "\n-----QUINIELA MANUAL-----\n");
					
				for(j = 0; j < COLUMNAS; j++)
				{
					for(i = 0; i < (Q1.bloques); i++)
						fprintf(f, "%c \t", Q1.quiniela[i][j]);
					fprintf(f, "\n");
				}
					
				fprintf(f, "Equipo 1: %c   \tEquipo 2: %c ", Q1.pleno15[0], Q1.pleno15[1]);
				printf("\nApuesta guardada satisfactoriamente en el fichero\n");
			}break;
		}
		
		printf("Deseas seguir utilizando el programa ('*' para salir)? ");
		scanf("%c", &resp);
		fflush(stdin);
	}while(resp != '*');
	
	fclose(f);
	
	system("pause");
	return 0;
}