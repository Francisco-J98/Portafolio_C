#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	unsigned short n,i,j;
	char car;

	printf("Caracter para dibujar el cuadrado: ");
	scanf("%c", &car);

	do
	{
		printf("\nIntroduzca el valor del lado: ");
		scanf("%uh", &n);
	}while(n < 2 || n > 24);

	if (n < 25)
	{
		for (i = 0; i < (25 - n) / 2; i++)
			printf("\n");
	}

	for (i = 0; i < n; i++)
	{
		for(j = 0; j < (80 - n) /2; j++)
			printf(" ");
		for(j = 0; j < n; j++)
			printf(" %c", car);
		printf("\n");
	}

	system("pause");
	return 0;
}