#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	int calendario[6][7], diasem, i, j, cantdias, fecha, act, aux, consulta;
	char resp;
	
	do
	{
		fecha = 1;
		printf("\nMENU CALENDARIO\n");
		printf("0)Salir\n");
		printf("1)Rellenar Calendario.\n");
		printf("2)Mostrar Calendario\n");
		printf("3)Consultar Dia\n");
		
		do
		{
			printf("Selecciona una opcion(0~3): ");
			scanf("%c", &resp);
			fflush(stdin);
		}while(resp < '0' || resp > '3');
		
		switch(resp)
		{
			case '0':printf("Has salido del programa\n");break;
			
			case '1':
			{
				printf("Calendario de 1 mes\n");
				do
				{
					printf(" 0)L 1)M 2)X 3)J 4)V 5)S 6)D\n");
					printf("La semana empieza en(0~6): \n");
					scanf("%d", &diasem);
					fflush(stdin);
				}while(diasem < 0 || diasem > 6);
				
				do
				{
					printf("Cuantos dias tiene el mes (28~31)? ");
					scanf("%d", &cantdias);
					aux = cantdias;
					fflush(stdin);
				}while(cantdias < 28 || cantdias > 31);
				
				for(i = 0; i < 1; i++)
					for(j = diasem; j < 7; j++)
					{
						calendario[i][j] = fecha;
						fecha++;
					}
				for(i = 1; i < 6; i++)
					for(j = 0; j < 7; j++)
					{
						calendario[i][j] = fecha;
						fecha++;
					}
				act = 1;
				printf("\n");		
			}break;
			
			case '2':
			{
				if(act == 1)
				{
					cantdias = aux;
					fecha = cantdias;
					
					for(i = 0; i < 1; i++)
						for(j = 0; j < diasem; j++)
							printf("|  |");
										
					for(i = 0; i < 1; i++)
						for(j = diasem; j < 7; j++)
						{
							if(calendario[i][j] < 10)
								printf("|0%d|", calendario[i][j]);
							else
								printf("|%d|", calendario[i][j]);
							cantdias--;
						}
					printf("\n");
					
					for(i = 1; i < 6; i++)
					{
						for(j = 0; cantdias != 0 && j < 7; j++)
						{
							if(calendario[i][j] < 10)
								printf("|0%d|", calendario[i][j]);
							else
								printf("|%d|", calendario[i][j]);
							cantdias--;
						}
						printf("\n");
					}
				}
				else
					printf("No se ha podido cargar el calendario.");
				printf("\n");
			}break;
			
			case '3':
			{
				if(act == 1)
				{
					do
					{
						printf("Introduce un numero para realizar la consulta del dia deseado(1~%d): \n", aux);
						scanf("%d", &consulta);
						fflush(stdin);
					}while(consulta < 1 || consulta > aux);
					
					for(i=0;i<6;i++)
						for(j=0;j<7;j++)
					
					if(consulta==calendario[i][j])
						aux=j;
					
					switch(aux)
					{
						case 0:printf("El dia %d es Lunes\n",consulta);break;
						case 1:printf("El dia %d es Martes\n",consulta);break;
						case 2:printf("El dia %d es Miercoles\n",consulta);break;
						case 3:printf("El dia %d es Jueves\n",consulta);break;
						case 4:printf("El dia %d es Viernes\n",consulta);break;
						case 5:printf("El dia %d es Sabado\n",consulta);break;
						case 6:printf("El dia %d es Domingo\n",consulta);break;
					}
				}
				else
					printf("No se ha podido cargar el calendario.");
				printf("\n");
			}break;
		}
	}while(resp != '0');
	
	system("pause");
	return 0;
}