#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //biblioteca de getche y getch
#include <ctype.h> //biblioteca de funciones
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float primerOperando;
    float segundooperando;
    float operacion;
    int flag1=0;
    int flag2=0;

   /* float suma;
    float divi;
    float multi;
    float rest;
    float facto;*/


    while(seguir=='s')
    {
        printf("\n1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        printf(" \n \t Ingrese la opcion elegida: \t");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                    primerOperando=pedirEnteroSintope(" \n==========================================\n Ingrese el Primero Operando: \t ");
                    printf("==========================================\n");
                    flag1=1;
                    break;

            case 2:
                    segundooperando=pedirEnteroSintope(" \n ==========================================\n Ingrese el Segundo Operando: \t ");
                    printf("==========================================\n");
                    flag2=1;
                    break;

            case 3:
                    primerOperando= validarFlags(flag1, primerOperando ,"\n \t Ingrese el primer operando: \t");
                    flag1=1;
                    segundooperando=validarFlags(flag2,segundooperando ,"\n \t Ingrese el segundo operando: \t");
                    flag2=1;
                    operacion=sumar(primerOperando,segundooperando);
                    informarOperadores(primerOperando, segundooperando);
                    printf("La suma es  \t %.2f \t \n \n", operacion);
                    break;

            case 4:
                    primerOperando= validarFlags(flag1, primerOperando, "\n \t Ingrese el primer operando: \t");
                    flag1=1;
                    segundooperando=validarFlags(flag2,segundooperando , "\n \t Ingrese el segundo operando: \t");
                    flag2=1;
                    operacion=restar(primerOperando,segundooperando);
                    informarOperadores(primerOperando, segundooperando);
                    printf("La Resta es  \t %.2f \t \n \n", operacion);
                    break;

            case 5:
                    primerOperando= validarFlags(flag1, primerOperando, "\n \t Ingrese el primer operando: \t");
                    flag1=1;
                    segundooperando=validarFlags(flag2,segundooperando , "\n \t Ingrese el segundo operando: \t");
                    if (segundooperando==0)
                    {
                    informarOperadores(primerOperando, segundooperando);
                    printf("La Division no se puede realizar \n \n");
                    }
                    else
                    {
                    operacion=dividir(primerOperando,segundooperando);
                    informarOperadores(primerOperando, segundooperando);
                    printf("La Division es  \t %.2f \t \n \n \n", operacion);
                    }
                    break;

            case 6:
                   primerOperando= validarFlags(flag1, primerOperando, "\n \t Ingrese el primer operando: \t");
                   flag1=1;
                   segundooperando=validarFlags(flag2,segundooperando , "\n \t Ingrese el segundo operando: \t");
                   flag2=1;
                   operacion=multiplicar(primerOperando,segundooperando);
                   informarOperadores(primerOperando, segundooperando);

                   printf("La Multiplicacion es  \t %.2f \t \n \n \n", operacion);
                   break;

            case 7:

                   primerOperando= validarFlags(flag1, primerOperando," \n \t Ingrese el primer operando: \t");
                   flag1=1;
                   operacion=factorial(primerOperando);

                   printf("\t \t El factorial es:  \t %.2f \n \n", operacion);
                   break;

            case 8:
                  primerOperando= validarFlags(flag1, primerOperando, "\n \t Ingrese el primer operando: \t");
                  flag1=1;
                  segundooperando=validarFlags(flag2,segundooperando , "\n \t Ingrese el segundo operando: \t");
                  flag2=1;

                  informarOperadores(primerOperando, segundooperando);
                  calcularTodasOperaciones(primerOperando,segundooperando);

            case 9:
                seguir = 'n';
                break;

                printf("\n");
                system("pause");
                system ("cls");


        }


}

    return 0;


}
