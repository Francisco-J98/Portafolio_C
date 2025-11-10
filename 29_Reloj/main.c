#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	int Hora[3], i;
	
	for (i = 0; i < 3; i++)
	{
		printf("Hora[%d]: ", i + 1);
		scanf("%d", & Hora[i]);
		fflush(stdin);
	}
	
	for (i = 0; Hora[i]; i++)
	{
		if (Hora[0] >= 24)
			Hora[0] %= 24;
		
		if (Hora[1] >= 60)
		{
			Hora[0] += Hora[1] / 60;
			Hora[1] %= 60;
		}
		
		if (Hora[2] >= 60)
		{
			Hora[1] += Hora[2] / 60;
			Hora[2] %= 60;
		}
	}
	
	printf("Son las: ");
	for (i = 0; i < 3; i++)
	{
		if(Hora[i] < 10)
			printf("| 0%d |", Hora[i]);
		else
			printf("| %d |", Hora[i]);
	}
	
	printf("\n");
	system("pause");
	return 0;
}