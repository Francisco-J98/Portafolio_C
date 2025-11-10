#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	int valor = 0;
	
	do
	{
		printf("\n------MENU------\n");
		printf("1). OP1\n");
		printf("2). OP2\n");
		printf("3). Salir");
		printf("\n------MENU------\n");
		
		printf("Escoge una opcion(1~3): ");
		
		scanf("%d", &valor);
		fflush(stdin);
		
		switch(valor)
		{
			case 1:printf("FELIZ 2016!\n");break;
			case 2:printf("Me gustan los churros con chocolate.\n");break;
			case 3:printf("Has salido del programa.\n");break;
			default:printf("Valor no reconocido por pantalla.\n");break;
		}
	}while(valor != 3);
	
	system("pause");
	return 0;
}