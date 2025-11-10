#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
unsigned longitud(char *p1)
{
    unsigned char *a1 = p1;
    unsigned value, conta = 0;

    do
	{
        value = *a1++;
        if (value == '\0')
            return (conta);
        else
            conta++;

    } while (*a1 != '\0');
    return (conta);
}

int main(int argc, char *argv[])
{
    char p1[15];
    int res, res2;

    printf("Cad1: ");
    gets(p1);
    fflush(stdin);

    printf("La cad1 tiene %d caracteres\n", longitud(p1));
    printf("La cad1 tiene %d caracteres\n", strlen(p1));
    
    system("pause");
	return 0;
}