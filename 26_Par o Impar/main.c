#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	int num, aux;
	
	printf("Introduce un numero: ");
	scanf("%u", &num);
	fflush(stdin);
	
	aux = num;
	
	if(num % 2)
		printf("%u es impar\n", aux);
	else
		printf("%u es par\n", aux);
	
	system("pause");
	return 0;
}