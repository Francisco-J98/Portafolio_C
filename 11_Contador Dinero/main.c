#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	unsigned Euro,aux_euro,e1,e2,e5,e10,e20,e50,e100,e200,e500;
	printf("Introduce la cantidad deseada: ");
	scanf("%u", &Euro);
	
	aux_euro = Euro;
	
	e500 = aux_euro / 500;
	aux_euro = aux_euro - (e500 * 500);
	
	e200 = aux_euro / 200;
	aux_euro -= (e200 * 200);
	
	e100 = aux_euro / 100;
	aux_euro -= (e100 * 100);
	
	e50 = aux_euro / 50;
	aux_euro -= (e50 * 50);
	
	e20 = aux_euro / 20;
	aux_euro -= (e20 * 20);
	
	e10 = aux_euro / 10;
	aux_euro -= (e10 * 10);
	
	e5 = aux_euro / 5;
	aux_euro -= (e5 * 5);
	
	e2 = aux_euro / 2;
	aux_euro -= (e2 * 2);
	
	e1 = aux_euro / 1;
	aux_euro -= (e1 * 1);

	printf("%u euro(s) son %u billete(s) de 500\n", Euro, e500);
	printf("%u euro(s) son %u billete(s) de 200\n", Euro, e200);
	printf("%u euro(s) son %u billete(s) de 100\n", Euro, e100);
	printf("%u euro(s) son %u billete(s) de 50\n", Euro, e50);
	printf("%u euro(s) son %u billete(s) de 20\n", Euro, e20);
	printf("%u euro(s) son %u billete(s) de 10\n", Euro, e10);
	printf("%u euro(s) son %u billete(s) de 5\n", Euro, e5);
	printf("%u euro(s) son %u monedas(s) de 2\n", Euro, e2);
	printf("%u euro(s) son %u moneda(s) de 1\n", Euro, e1);
	
	system("pause");
	return 0;
}