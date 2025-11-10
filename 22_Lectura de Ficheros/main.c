#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	char aux;
	char aux_2[300];
	FILE *f;
	
	//1a apertura del fichero
	f = fopen("Stats.txt", "r");
	
	if(f == NULL)
	{
		printf("No se ha podido abrir el fichero.\n");
		exit(1);
	}
	
	//Lectura de ficheros carácter a carácter.
	printf("Lectura de ficheros caracter a caracter.\n");
	while(aux != EOF)
	{
		aux = fgetc(f);
		printf("%c", aux);
	}
	
	printf("\n");
	fclose(f);
	
	//2a apertura del fichero
	f = fopen("Stats.txt", "r");
	
	if(f == NULL)
	{
		printf("No se ha podido abrir el fichero.\n");
		exit(1);
	}
	
	//Lectura de ficheros con strings.
	printf("\nLectura de ficheros con strings.\n");
	while(!feof(f))
	{
		fgets(aux_2, 300, f);
		printf("%s", aux_2);
	}
	
	printf("\n");
	fclose(f);
	
	system("pause");
	return 0;
}