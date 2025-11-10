#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char *localizarchar(char *p1, char car)
{
    char *aux = NULL;
    
    do
	{
        if ( *p1 == car) 
            aux = p1;    
    }while(*p1++);
    
	return(aux);
}

int main(int argc, char *argv[])
{
    char p1[15], car;
    
    printf("Cad1: ");
    gets(p1);
    fflush(stdin);
    printf("caracter deseado: ");
    car = getchar();
    fflush(stdin);
    printf("%s\n", localizarchar(p1, car));
		
	system("pause");
	return 0;
}