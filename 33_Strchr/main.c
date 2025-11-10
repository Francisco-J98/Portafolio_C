#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char *localizarcad (char *p1, char car)
{
  while (*p1 !=car)
  	if (!*p1++)
		return 0;
  return p1;
}

int main(int argc, char *argv[])
{
	char p1[500], car;
	
    printf("Cad1: ");
    gets(p1);
    fflush(stdin);
    printf("caracter deseado: ");
    car = getchar();
    fflush(stdin);
    printf("%s\n", localizarcad(p1, car));
    
	system("pause");
	return 0;
}