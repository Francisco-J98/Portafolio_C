#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

unsigned invertir(unsigned num)
{
	unsigned result = 0;
	for (; num; num /= 10)
		result = result * 10 + num % 10;
	return(result);
}

int main(int argc, char *argv[])
{
	unsigned num;
	printf("Introduzca el numero: ");
	scanf("%u", &num);
	printf("El numero escogido es %d y el numero con las cifras invertidas es %d\n", num, invertir(num));

	system("pause");
	return 0;
}