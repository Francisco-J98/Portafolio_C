#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define MAXIMO_CAR 30

int main(int argc, char *argv[])
{
	char vocales[MAXIMO_CAR], car;
	unsigned short conta = 0, total = 0;
	
	printf("Introduzca caracter: \n");
	
	do
	{
		scanf("%c", &car);
		total++;
		
		if(car == 'A' || car == 'E' || car == 'I' || car == 'O' || car == 'U' || car == 'a' || car == 'e' || car == 'i' || car == 'o' || car == 'u')
			vocales[conta++] = car;
	}while(conta < MAXIMO_CAR);

	for(conta = 0; conta < MAXIMO_CAR; conta++)
		printf("%c", vocales[conta]);
	printf("\nEl porcentaje de vocales es %f\n", (float) 3000 / total);
	
	system("pause");
	return 0;
}