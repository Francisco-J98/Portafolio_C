#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	srand(time(NULL));
    int num, lim_max = 999, lim_min = 0, conta = 0, clave;
    
	clave = rand()%1000;
	
    do
    {
        printf("Introduce un numero entre %d y %d: ", lim_min, lim_max);
        scanf("%d", &num);
        fflush(stdin);
    }while(num < lim_min || num > lim_max);
	
	do
	{
        if(num < clave)
		{
			lim_min = num;
			printf("Prueba entre %d y %d: ", lim_min, lim_max);
            scanf("%d", &num);
			
			if(num < lim_min || num > lim_max)
			{
				do
				{
					printf("Introduce un valor entre los limites %d y %d: ", lim_min, lim_max);
                    fflush(stdin);
                    scanf("%d", &num);
				}while(num < lim_min || num > lim_max);
            }
			conta++;
        }
		else
			if(num>clave)
			{
				lim_max = num;
				printf("Prueba entre %d y %d: ", lim_min, lim_max);
				scanf("%d", &num);
				
				if(num < lim_min || num > lim_max)
				{
                    do
                    {
						printf("Introduce un valor entre los limites %d y %d: ", lim_min, lim_max);
						fflush(stdin);
						scanf("%d", &num);
                    }while(num < lim_min || num > lim_max);
                }
				conta++;
			}
	}while(num != clave);

    if(num == clave)
    {
        printf("Enhorabuena! El numero era %d\n", num);
        printf("Numero de (re)intento(s): %d\n", conta);
    }
    
    system("pause");
	return 0;
}