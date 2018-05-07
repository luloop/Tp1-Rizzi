/********************************************************
* Programa : Tp1_laboratorio1_programacion1             *
*                                                       *
* Objetivo : Hace una calculadora con el ingreso de     *
         2 numeros flotantes                            *
*                                                       *
*                                                       *
*                                                       *
* Version: 7                                            *
* Autor: Lucila Rizzi                                   *
*                                                       *
********************************************************/

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
                    primerOperando=pedirEnteroSintope("Ingrese el Primero Operando: \t ");
                    flag1=1;
                    break;
            case 2:
                    segundooperando=pedirEnteroSintope("Ingrese el Segundo Operando: \t ");
                    flag2=1;
                    break;
            case 3:
                    primerOperando= validarFlags(flag1, primerOperando, "ERROR! - Ingrese el primer operando: \t");
                    flag1=1;
                    segundooperando=validarFlags(flag2,segundooperando , "ERROR! - Ingrese el segundo operando: \t");
                    flag2=1;
                    respuestaSuma(primerOperando,segundooperando, "La suma es:");
                    break;
            case 4:
                    primerOperando= validarFlags(flag1, primerOperando, "ERROR! - Ingrese el primer operando: \t");
                    flag1=1;
                    segundooperando=validarFlags(flag2,segundooperando , "ERROR! - Ingrese el segundo operando: \t");
                    flag2=1;
                    respuestaResta(primerOperando,segundooperando, "La resta es:");
                    break;
            case 5:
                    primerOperando= validarFlags(flag1, primerOperando, "ERROR! - Ingrese el primer operando: \t");
                    flag1=1;
                    segundooperando=validarFlags(flag2,segundooperando , "ERROR! - Ingrese el segundo operando: \t");
                    flag2=1;
                    respuestaDivision(primerOperando,segundooperando);
                    break;
            case 6:
                   primerOperando= validarFlags(flag1, primerOperando, "ERROR! - Ingrese el primer operando: \t");
                   flag1=1;
                   segundooperando=validarFlags(flag2,segundooperando , "ERROR! - Ingrese el segundo operando: \t");
                   flag2=1;
                   respuestaMultiplicar(primerOperando,segundooperando, "La Multiplicacion es:");
                   break;
            case 7:
                   primerOperando= validarFlags(flag1, primerOperando,"\t Ingrese el primer operando: \t");
                   flag1=1;
                   operacion= factorial(primerOperando);
                   respuestaFactorial(operacion, primerOperando);
                   break;
            case 8:
                  primerOperando= validarFlags(flag1, primerOperando, "\t Ingrese el primer operando: \t");
                  flag1=1;
                  segundooperando=validarFlags(flag2,segundooperando , "\t Ingrese el segundo operando: \t");
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
