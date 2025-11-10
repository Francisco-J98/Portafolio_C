#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{	
    long valorXD;

    printf("Introduce un valor: ");
    scanf("%li", &valorXD);
    
    for (; valorXD <= 2147483647; valorXD--)
        printf("%li\n", valorXD);
    
	system("pause");
	return 0;
}