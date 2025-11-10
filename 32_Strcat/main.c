#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char *concatenar (char *p1,char *p2)
{
  strcpy (p1 + strlen (p1), p2);
  return p1;
}

int main(int argc, char *argv[])
{
	char p1[15], p2[15];
	
	printf("Cad1: ");
	gets(p1);
	fflush(stdin);
		
	printf("Cad2: ");
	gets(p2);
	fflush(stdin);
	
	printf("%s\n", concatenar(p1,p2));
	
	system("pause");
	return 0;
}