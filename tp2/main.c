/********************************************************
* Programa : Tp2_laboratorio1_programacion1             *
*                                                       *
* Objetivo : ABM                                        *
*                                                       *
*                                                       *
*                                                       *
* Version: 2                                            *
* Autor: Lucila Rizzi                                   *
* Año:2018                                              *
*                                                       *
********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define CantUsuario 20


int main()
{
    char seguir='s';
    int opcion=0;
    int flagPersona=1;

     //ePersona persona;
     ePersona personas[CantUsuario];

     indiceUsuarios(personas, CantUsuario);

    while(seguir=='s')
    {
        printf("\n1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir");
        printf("\n \t \t Ingrese la opcion deseada: ");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                flagPersona=altaUsuario(personas, CantUsuario);
                cleanScreen();
                break;
            case 2:
                bajaUsuario(personas, CantUsuario, flagPersona);
                cleanScreen();
                break;
            case 3:
                mostrarOrdenadoPorNombre (personas, CantUsuario, flagPersona);
                cleanScreen();
                break;
            case 4:
                graficos (personas, CantUsuario);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}

