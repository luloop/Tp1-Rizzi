#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //biblioteca de getche y getch
#include <ctype.h> //biblioteca de funciones
#include "funciones.h"

int main()
{
    int seguir=0;
    int opcion=0;
    float primerOperando;
    float segundooperando;
    float operacion;
    int flag1=0;
    int flag2=0;

    while(seguir==0)
    {
        opcion = ingresarMenu();

        switch(opcion)
        {
            case 1:
                    primerOperando=pedirEnteroSintope(" \n=============================\n Ingrese el Primero Operando: \t ");
                    flag1=1;
                    break;

            case 2:
                    segundooperando=pedirEnteroSintope(" \n=============================\n Ingrese el Segundo Operando: \t ");
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

                   printf("=======================\nPARA EL OPERANDO: %d \n",(int)primerOperando);
                   printf("=======================\n");
                   operacion=factorial((int)primerOperando);

                   printf("\t \t El factorial es:  \t %.0f \n \n", operacion);
                   break;

            case 8:
                  primerOperando= validarFlags(flag1, primerOperando, "\n \t Ingrese el primer operando: \t");
                  flag1=1;
                  segundooperando=validarFlags(flag2,segundooperando , "\n \t Ingrese el segundo operando: \t");
                  flag2=1;

                  informarOperadores(primerOperando, segundooperando);
                  calcularTodasOperaciones(primerOperando,segundooperando);
                  break;

            case 9:
                  seguir = 1;
                  break;
        }

        printf("\n");
        system("pause");
        system ("cls");
}

    return 0;


}
