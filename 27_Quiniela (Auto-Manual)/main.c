#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define FILA 8
#define COLUMNA 14
#define PLENOAL15 2

void rellauto(char quiniela[FILA][COLUMNA],int bloques, char pleno15[PLENOAL15])
{
	int i, j, val_ale;
	char result[3] = "1X2", result2[4] = "012M";
	
	for(i = 0; i < bloques; i++)
	    for(j = 0; j < COLUMNA; j++)
	    	quiniela[i][j] = result[rand()%3];
	    	
	for(i = 0; i < PLENOAL15; i++)
		pleno15[i] = result2[rand()%4];
}

void rellman(char quiniela[FILA][COLUMNA], int bloques, char pleno15[PLENOAL15])
{
	int i, j;

	for(i = 0; i < bloques; i++)
		for(j = 0; j < COLUMNA; j++)
			do
			{
				printf("Partido[%d][%d]: ", i + 1, j + 1);
				scanf("%c", &quiniela[i][j]);
				fflush(stdin);
			}while(quiniela[i][j] != '1' && quiniela[i][j] != '2' &&quiniela[i][j] != 'X');
			
	for(i = 0; i < PLENOAL15; i++)
		do
		{
			printf("\nPleno al 15 Equipo %d : ", i + 1);
			scanf("%c", &pleno15[i]);
			fflush(stdin);
		}while(pleno15[i] != '0' && pleno15[i] != '1' && pleno15[i] != '2' && pleno15[i] != 'M');
}

void imprquin(char quiniela[FILA][COLUMNA], int bloques, char pleno15[PLENOAL15])
{
	int i, j;
	
	printf("---------QUINIELA (VISTA PREVIA)-----------\n");  //vista previa quiniela
	for(j = 0; j < COLUMNA; j++)
	{
		for(i = 0; i < bloques; i++)
			printf("     %c\t", quiniela[i][j]);
		printf("\n");
	}
	printf("Equipo 1: %c  \tEquipo 2: %c   \n", pleno15[0], pleno15[1]);
}

int main(int argc, char *argv[])
{
	srand(time(NULL));
	
	int bloques, opcion, i, j;
	char quiniela[FILA][COLUMNA], pleno15[PLENOAL15], resp;
	
	FILE *f;
	
	if(!(f = fopen("BoletoQuiniela.txt", "a")))
	{
		printf("No se ha podido abrir el fichero.\n");
		return 1;
	}
	
	do
	{
		printf("QUINIELA CON APUESTAS AUTOMATICAS Y MANUALES\n");
		printf("1)AUTOMATICA\n");
		printf("2)MANUAL\n");
		
		do //MENU
		{
			printf("Seleccione la opcion (1~2): ");
			scanf("%u", &opcion);
			fflush(stdin);
		}while(opcion < 1 || opcion > 2);
		
		switch(opcion)
		{
			case 1:
			{
				do // seleccionar bloques quiniela
				{
					printf("Selecciona cuantos bloques deseas rellenar(1~8): ");
					scanf("%d", &bloques);
					fflush(stdin);
				}while(bloques < 1 || bloques > FILA);
				
				rellauto(quiniela, bloques, pleno15);
				imprquin(quiniela, bloques, pleno15);
				
				fprintf(f, "\n---------QUINIELA AUTOMATICA-----------\n");
				
				for(j = 0; j < COLUMNA; j++)
				{
					for(i = 0; i < bloques; i++)
						fprintf(f, "     %c\t", quiniela[i][j]);
					
					fprintf(f, "\n");
				}
				
				fprintf(f, "Equipo 1: %c  \tEquipo 2: %c   \n", pleno15[0], pleno15[1]);
				printf("\nLa quiniela se ha guardado satisfactoriamente en el fichero\n");
			}break;
			
			case 2:
			{
				do // seleccionar bloques quiniela
				{
					printf("Selecciona cuantos bloques deseas rellenar(1~8): ");
					scanf("%d", &bloques);
					fflush(stdin);
				}while(bloques < 1 || bloques > FILA);
				
				rellman(quiniela, bloques, pleno15);
				imprquin(quiniela, bloques, pleno15);
				
				fprintf(f, "\n---------QUINIELA MANUAL-----------\n");
				
				for(j = 0; j < COLUMNA; j++)
				{
					for(i = 0; i < bloques; i++)
						fprintf(f ,"     %c\t", quiniela[i][j]);
					fprintf(f, "\n");
				}
				
				fprintf(f, "Equipo 1: %c  \tEquipo 2: %c   \n", pleno15[0], pleno15[1]);
				printf("\nLa quiniela se ha guardado satisfactoriamente en el fichero\n");
			}break;
		}
		
		printf("Desea seguir utilizando el programa? ('*' para salir)? ");
		scanf("%c", &resp);
		fflush(stdin);
		
	}while(resp != '*');
	
	fclose(f);
	system("pause");
	return 0;
}