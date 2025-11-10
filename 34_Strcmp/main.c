#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int comparar(char *p1, char *p2, int n)
{
    unsigned char *a1 = p1;
    unsigned char *a2 = p2;
	char c1, c2;
    int i, result;
    
    for (i = n; i > 0; i--)
	{
        if (a1 != a2)
		{
            if (*a1 > *a2)
                return 1;
            else
                return -1;
        }
        if (*a1++ == 0)
            return 0;
        a2 += 1;
    }
    return 0;
}

int main(int argc, char *argv[])
{
	
    char p1[15], p2[15];
    int res, res2, n;

    printf("Cad1: ");
    gets(p1);
    fflush(stdin);

    printf("Cad2: ");
    gets(p2);
    fflush(stdin);

    printf("Numero caracteres a comparar: ");
    scanf("%d", &n);
    fflush(stdin);

    res2 = strncmp(p1, p2, n);
    res = comparar(p1, p2, n);

    if (res < 0)
        printf("cad1 es menor que cad2 en los %d caracteres\n", n);
    else if (res == 0)
        printf("cad1 es igual que cad2 en los %d caracteres\n", n);
    else if (res > 0)
        printf("cad1 es mayor que cad2 en los %d caracteres\n", n);

    if (res2 < 0)
        printf("cad1 es menor que cad2 en los %d caracteres\n", n);
    else if (res2 == 0)
        printf("cad1 es igual que cad2 en los %d caracteres\n", n);
    else if (res2 > 0)
        printf("cad1 es mayor que cad2 en los %d caracteres\n", n);
        
	system("pause");
	return 0;
}