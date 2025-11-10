#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	char letra;
	printf("Introduzca un caracter, '*' para acabar: ");
	scanf("%c", &letra);
	
	while(letra != '*')
	{
		if(letra >= 'A' && letra <= 'Z')
			printf("\n%c\n", letra-'A' + 'a');
		else
			if(letra >= 'a' && letra <= 'z')
				printf("\n%c\n", letra - 'a' + 'A');
		else
			printf("\n%c\n", letra);
		
		printf("\nIntroduzca un nuevo caracter: ");
		fflush(stdin);
		scanf("%c", &letra);
	}
	
	system("pause");
	return 0;
}