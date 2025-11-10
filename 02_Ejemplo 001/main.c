#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	char car = 'L';
	char letra, digito;

	printf("%c\n", car);
	letra = '?';
	car = letra;
	digito = 48;
	letra = 65;
	printf("%c %c %c\n", car, letra, digito);
	
	system("pause");
	return 0;
}