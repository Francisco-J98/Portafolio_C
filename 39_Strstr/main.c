#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char *localizarcad(char *p1, char *p2)
{
    int L = strlen(p2);
    
    while (*p1)
	{
        if (!memcmp(p1 ++, p2, L)) 
            return(p1 - 1);
        
    }
    return(0);
}

int main(int argc, char *argv[])
{
	char p1[500], p2[15];
	
    printf("Cad1: ");
    gets(p1);
    fflush(stdin);
    printf("Cad2: ");
    gets(p2);
    fflush(stdin);
    printf("%s\n", localizarcad(p1, p2));
    
	system("pause");
	return 0;
}