#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	int num;
	char cad[255];
	
	FILE *f;
	f = fopen("PruebasParaFicherosEscr.txt", "w");
	
	if(f == NULL)
	{
		printf("No se ha podido abrir el fichero.\n");
		exit(1);
	}
	
	printf("Introduce un numero: ");
	scanf("%i", &num);
	fflush(stdin);
	
	printf("A continuacion, un comentario: ");
	fflush(stdin);
	fgets(cad, 255, stdin);
	
	fprintf(f, "El numero que has introducido es el: %i\n", num);
	fprintf(f, "El comentario que has introducido es: %s\n", cad);
	fclose(f);
	
	system("pause");
	return 0;
}