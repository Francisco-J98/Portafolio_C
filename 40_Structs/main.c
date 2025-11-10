#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct
{
    char nombre[50];
    char empleo[50];
    unsigned edad;
}registro;

int main(int argc, char *argv[])
{
    registro f1, f2;
    
    printf("\n-----FORMULARIO 1-----\n");
    printf("Introduzca su nombre: \n");
    fgets(f1.nombre, 50, stdin);
    printf("Introduzca su empleo: \n");
    fflush(stdin);
    fgets(f1.empleo, 50, stdin);
    printf("Introduzca su edad: \n");
    scanf("%u", &f1.edad);
    printf("----------------------\n");
    printf("\n-----FORMULARIO 2-----\n");
    printf("Introduzca su nombre: \n");
    fflush(stdin);
    fgets(f2.nombre, 50, stdin);
    printf("Introduzca su empleo: \n");
    fflush(stdin);
    fgets(f2.empleo, 50, stdin);
    printf("Introduzca su edad: \n");
    scanf("%u", &f2.edad);
    printf("----------------------\n");
    printf("El nombre de f1: %s", f1.nombre);
    printf("El nombre de f2: %s", f2.nombre);
    printf("El empleo de f1: %s", f1.empleo);
    printf("El empleo de f2: %s", f2.empleo);
    printf("La edad de f1: %u anios\n", f1.edad);
    printf("La edad de f2: %u anios\n", f2.edad);
    
    system("pause");
    return 0;
}