#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	float num1,num2;
	char operacion,op;
		
	do
	{
		printf("Introduzca el primer numero: ");
		scanf("%f", &num1);
		printf("Introduzca el segundo numero: ");
		scanf("%f", &num2);
		printf("Introduzca la operacion deseada a continuacion (+, -, *, /), 'X' para salir: ");
		fflush(stdin);
		scanf("%c", &operacion);
		
		if(operacion == 'X' || operacion == 'x')
			exit(1);
		
		switch(operacion)
		{
			case '+':printf("%f %c %f = %f\n",num1,operacion,num2,num1+num2);break;
			case '-':printf("%f %c %f = %f\n",num1,operacion,num2,num1-num2);break;
			case '*':printf("%f %c %f = %f\n",num1,operacion,num2,num1*num2);break;
			case '/':printf("%f %c %f = %f\n",num1,operacion,num2,num1/num2);break;
		}
		
		printf("¿Desea realizar otra operacion? (S/N): ");
		fflush(stdin);
		scanf("%c", &op);
		
		if(op == 'N' || op == 'n')
			exit(1);
	}while(operacion == '+' || operacion == '-' || operacion == '*' || operacion == '/');
	
	system("pause");
	return 0;
}