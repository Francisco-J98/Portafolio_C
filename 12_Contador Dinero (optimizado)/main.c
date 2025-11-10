#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	unsigned Euro;
	
	printf("Introduzca la cantidad en Euros: ");
	scanf("%u", &Euro);
	printf("\n%u billete(s) de 500 euros\n", Euro / 500);
	Euro %= 500;
	printf("%u billete(s) de 200 euros\n", Euro / 200);
	Euro %= 200;
	printf("%u billete(s) de 100 euros\n", Euro / 100);
	Euro %= 100;
	printf("%u billete(s) de 50 euros\n", Euro / 50);
	Euro %= 50;
	printf("%u billete(s) de 20 euros\n", Euro / 20);
	Euro %= 20;
	printf("%u billete(s) de 10 euros\n", Euro / 10);
	Euro %= 10;
	printf("%u billete(s) de 5 euros\n", Euro / 5);
	Euro %= 5;
	printf("%u moneda(s) de 2 euros\n%u moneda(s) de 1 euro\n", Euro / 2, Euro % 2);

	system("pause");
	return(0);
}