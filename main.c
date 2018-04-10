#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //biblioteca de getche y getch
#include <ctype.h> //biblioteca de funciones
#include "PedirNumeros.h"
#include "operaciones.h"
int main()
{
    char seguir='s';
    int opcion=0;
    int primerOperando;
    int segundooperando;
    float operacion;
    int flag1=0;
    int flag2=0;

    float suma;
    float divi;
    float multi;
    float rest;
    float facto;

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
                primerOperando=pedirEnteroSintope(" \n ==========================================\n || Ingrese el Primero Operando: \t ");
                flag1=1;
                break;
            case 2:
                segundooperando=pedirEnteroSintope(" \n ==========================================\n ||  Ingrese el Segundo Operando: \t ");
                flag2=1;
                break;
            case 3:
               primerOperando= validarFlags(flag1, primerOperando ,"\n \t Ingrese el primer operando: \t");
               flag1=1;
               segundooperando=validarFlags(flag2,segundooperando ,"\n \t Ingrese el segundo operando: \t");
               flag2=1;
              operacion=sumar(primerOperando,segundooperando);
              printf("\n===============================\n EL PRIMERO OPERANDO ES: %d \n ",primerOperando);
              printf("EL SEGUNDO OPERANDO ES: %d \n ==============================\n ",segundooperando);
              printf("La suma es  \t %.2f \t \n \n", operacion);
               break;
            case 4:
               primerOperando= validarFlags(flag1, primerOperando, "\n \t Ingrese el primer operando: \t");
               flag1=1;
               segundooperando=validarFlags(flag2,segundooperando , "\n \t Ingrese el segundo operando: \t");
               flag2=1;
               operacion=restar(primerOperando,segundooperando);
               printf("\n===============================\n EL PRIMERO OPERANDO ES: %d \n ",primerOperando);
              printf("EL SEGUNDO OPERANDO ES: %d \n ==============================\n ",segundooperando);
               printf("La Resta es  \t %.2f \t \n \n", operacion);
               break;
            case 5:
               primerOperando= validarFlags(flag1, primerOperando, "\n \t Ingrese el primer operando: \t");
               flag1=1;
               segundooperando=validarFlags(flag2,segundooperando , "\n \t Ingrese el segundo operando: \t");
               flag2=1;
               if (segundooperando==0)
               {
                   printf("\n===============================\n EL PRIMERO OPERANDO ES: %d \n ",primerOperando);
              printf("EL SEGUNDO OPERANDO ES: %d \n ==============================\n ",segundooperando);
                 printf("La Division no se puede realizar \n \n");
               }
               else
               {
              operacion=dividir(primerOperando,segundooperando);
              printf("\n===============================\n EL PRIMERO OPERANDO ES: %d \n ",primerOperando);
              printf("EL SEGUNDO OPERANDO ES: %d \n ==============================\n ",segundooperando);
              printf("La Division es  \t %.2f \t \n \n \n", operacion);
               }
                break;
            case 6:
               primerOperando= validarFlags(flag1, primerOperando, "\n \t Ingrese el primer operando: \t");
               flag1=1;
               segundooperando=validarFlags(flag2,segundooperando , "\n \t Ingrese el segundo operando: \t");
               flag2=1;
               operacion=multiplicar(primerOperando,segundooperando);
               printf("\n===============================\n EL PRIMERO OPERANDO ES: %d \n ",primerOperando);
              printf("EL SEGUNDO OPERANDO ES: %d \n ==============================\n ",segundooperando);
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
              multi=multiplicar(primerOperando,segundooperando);
              suma= sumar(primerOperando,segundooperando);
              divi=dividir(primerOperando,segundooperando);
              rest=restar(primerOperando,segundooperando);
              facto=factorial(primerOperando);

              printf(" ===============================\n EL PRIMERO OPERANDO ES: %d \n ",primerOperando);
              printf("EL SEGUNDO OPERANDO ES: %d \n ===============================\n ",segundooperando);

              if (segundooperando==0)
               {
                   printf("\n La suma es:\t \t  %.2f \n La resta es: \t \t  %.2f \n La division no se puede realizar \n La multiplicacion es:\t  %.2f \n El factorial es:\t  %.2f \n \n", suma,rest,multi,facto);
                }
               else
                {
              printf("\n La suma es:\t \t  %.2f \n La resta es:\t \t  %.2f \n La division es:\t  %.2f \n La multiplicacion es:\t  %.2f \n El factorial es:\t  %.2f \n \n", suma,rest,divi,multi,facto);
                }
               break;
            case 9:
                seguir = 'n';
                break;
        }


}

    return 0;


}
