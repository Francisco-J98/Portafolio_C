#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char *concatenar(char *p1, char *p2, int n)
{
    char *aux = p1;
    int L;
    
    p1 += strlen(p1);
    L = strnlen(p2, n);
    p1[L] = '\0';
    memcpy(p1, p2, n);
    
	return aux;
}

int main(int argc, char *argv[])
{
	int n;
    char p1[15], p2[15];
    
    printf("Cad1: ");
    gets(p1);
    fflush(stdin);
    printf("Cad2: ");
    gets(p2);
    fflush(stdin);
    printf("numero de caracteres: ");
    scanf("%d", & n);
    fflush(stdin);
    printf("%s\n", concatenar(p1, p2, n));
    
	system("pause");
	return 0;
}