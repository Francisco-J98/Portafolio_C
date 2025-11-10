#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void factorial(unsigned N)
{
	unsigned i, aux = 1;
	
	for(i = 1; i <= N; i++)
		aux *= i;
		
	if(N == 1 && aux == 1 || N == 0 && aux == 1)
		printf("%u! (El factorial de %u) = %u por convenio", N, N, aux);
	else
		printf("%u! (El factorial de %u) = %u", N, N, aux);
}

int main(int argc, char *argv[])
{
	unsigned N;
	printf("---------FACTORIAL DEL NUMERO N---------\n");
	printf("Introduzca el valor de N: ");
	scanf("%u", &N);
	factorial(N);
	printf("\n----------------------------------------\n");
	
	system("pause");
	return 0;
}