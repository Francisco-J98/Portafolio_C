#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{	
    int a, b, c, mayor;
    printf("Introduzca tres numeros: ");
    scanf("%d %d %d", &a, &b, &c);
    mayor = ((a > b)?(a > c)?a:c : (b > c)?b : c);
    printf("El mayor es %d\n", mayor);
    
    system("pause");
	return 0;
}