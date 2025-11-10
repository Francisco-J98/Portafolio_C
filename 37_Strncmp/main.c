#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int comparar(char *p1, char *p2)
{
    unsigned char *a1 = p1;
    unsigned char *a2 = p2;
    char c1, c2;

    do
	{
        c1 = *a1++;
        c2 = *a2++;
        if (c1 == '\0' && c2 == '\0')
            return (c1 - c2);
    }while (c1 == c2);

    return (c1 - c2);
}

int main(int argc, char *argv[])
{
	int res, res2;
    char p1[15], p2[15];

    printf("Cad1: ");
    gets(p1);
    fflush(stdin);

    printf("Cad2: ");
    gets(p2);
    fflush(stdin);

    res = comparar(p1, p2);
    res2 = strcmp(p1, p2);
    if (res < 0)
        printf("cad1 es menor que cad2\n");
    else if (res == 0)
        printf("cad1 es igual que cad2\n");
    else if (res > 0)
        printf("cad1 es mayor que cad2\n");

    if (res2 < 0)
        printf("cad1 es menor que cad2\n");
    else if (res2 == 0)
        printf("cad1 es igual que cad2\n");
    else if (res2 > 0)
        printf("cad1 es mayor que cad2\n");
        
	system("pause");
	return 0;
}