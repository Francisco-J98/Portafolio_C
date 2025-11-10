#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define MINIMO 1
#define MAXIMO 20

int main(int argc, char *argv[])
{
    unsigned numer, i;

    do
	{
        printf("Introduce un numero entre %d y %d: ", MINIMO, MAXIMO);
        fflush(stdin);
        scanf("%u", &numer);
    }while(numer < MINIMO || numer > MAXIMO);

    printf("----TABLA DEL %u----\n", numer);
    for (i = 1; i < 11; i++)
        printf("\t%3u x %d = %d\n", numer, i, numer * i);
        
	system("pause");
	return 0;
}