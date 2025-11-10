#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	char frase[23];
	char frase_2[23];
	
	printf("Introduce un comentario: ");
	fgets(frase,23,stdin);
	printf("\nIntroduce el siguente comentario: ");
	fflush(stdin);
	fgets(frase_2,23,stdin);
	
	if(strcmp(frase,frase_2)==0)
		printf("Ambos comentarios son iguales\n");
	else
		printf("Ambos comentarios no son iguales\n");
	system("pause");
	
	return 0;
}