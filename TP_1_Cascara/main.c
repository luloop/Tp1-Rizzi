#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int primerOperando;
    int segundoOperando;
    int resultado;

    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                primerOperando= // funcion pedir primer operando;// validaciones
                break;
            case 2:
                segundoOperando= // funcion pedir segundo operando// validaciones
                break;
            case 3:
                resultado= // funcion suma // validaciones
                break;
            case 4:
                resultado= // funcion resta // validaciones
                break;
            case 5:
                resultado= // funcion division // validaciones
                break;
            case 6:
                resultado= // funcion multiplicacion // validaciones
                break;
            case 7:
                resultado= // funcion factorial // validaciones
                break;
            case 8:
                resultado= // TODAS LAS FUNCIONES // validaciones
                break;
            case 9:
                seguir = 'n';
                break;
        }


        }

    return 0;
}
