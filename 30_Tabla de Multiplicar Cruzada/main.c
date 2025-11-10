#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define MINIMO 1
#define MAXIMO 10

int main(int argc, char *argv[])
{
    int n, i, j;
    
	do
	{
        printf("----TABLA MULTIPLICAR CRUZADA----");
        printf("\nIntroduzca un numero entre %d y %d: ", MINIMO, MAXIMO);
        fflush(stdin);
        scanf("%d", &n);
    }while(n < MINIMO || n > MAXIMO);
    
    printf("   ");

    for (i = 1; i <= n; i++)
        printf("%4d", i);

    printf("\n___________________________________________");
    for (i = 1; i <= n; i++)
	{
        printf("\n%2d|", i);
        for (j = 1; j <= n; j++)
            printf("%4d", i*j);
    }
    printf("\n\n");
    
    system("pause");
    return 0;
}