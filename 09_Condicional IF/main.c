#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	int a, b, c;
	
	printf("Introduce tres numeros: ");
	scanf("%d %d %d", &a, &b, &c);
	
	if(a > b)
		if(a > c)
			printf("El mayor es %d", a);
		else
			printf("El mayor es %d", c);
	else
		if(b > c)
			printf("El mayor es %d", b);
		else
			printf("El mayor es %d", c);
	
	printf("\n");
	
	system("pause");
	return 0;
}