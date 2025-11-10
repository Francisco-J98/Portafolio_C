#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
{
	float radio, pi=3.141595;
	printf("Introduce el radio de la circunferencia (cm): ");
	scanf("%f", &radio);
	printf("El area es %f cm^2 y el perimetro es %f cm\n", pi * radio * radio, 2 * pi *radio);
	system("pause");
	return 0;
}