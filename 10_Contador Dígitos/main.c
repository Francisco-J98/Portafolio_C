#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	long int num;
	unsigned short conta = 1;
	
	printf("Introduzca el numero: ");
	scanf("%ld", &num);
	
	for (; num /= 10; conta++);
		printf("\nEl numero de digitos es %u\n", conta);
		
	system("pause");
	return 0;
}