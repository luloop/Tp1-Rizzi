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
#include <ctype.h>
#include <string.h>
#include <conio.h>

#include "funciones.h"
#define CantUsuario 20


int main()
{
    char seguir='s';
    char opcion;
    int flagPersona=0;

     //ePersona persona;
     ePersona personas[CantUsuario];

     indiceUsuarios(personas, CantUsuario);
     flagPersona= cargarUsuarios(personas, 15);

    while(seguir=='s')
    {
        printf("\n\t====== SISTEMA DE GESTION DE PERSONAS ======\n");
        printf("\n\t1- Agregar persona\n");
        printf("\t2- Borrar persona\n");
        printf("\t3- Imprimir lista ordenada por  nombre\n");
        printf("\t4- Imprimir grafico de edades\n");
        printf("\t5- Salir");
        printf("\n\t \t \t Ingrese la opcion deseada: ");
        fflush(stdin);
        scanf("%c",&opcion);

        switch(opcion)
        {
            case '1':
                flagPersona=altaUsuario(personas, CantUsuario);
                cleanScreen();
                break;
            case '2':
                bajaUsuario(personas, CantUsuario, flagPersona);
                cleanScreen();
                break;
            case '3':
                mostrarOrdenadoPorNombre (personas, CantUsuario, flagPersona);
                cleanScreen();
                break;
            case '4':
                printf("\n------- Grafico por edades ------- \n");
                graficos (personas, CantUsuario);
                break;
            case '5':
                printf("\n");
                system ("cls");
                printf("\n------------------------------------------------------\n");
                printf("\n---------------------- CHAU --------------------------\n");
                printf("\n------------------------------------------------------\n\n\n\n\n\n\n\n\n\n\n");
                seguir = 'n';
                break;
            default:
                printf("\n------------------------------------------------------\n");
                printf("\n----------- No ingreso una opcion valida -------------\n ");
                printf("\n------------------------------------------------------\n");
                fflush(stdin);
                cleanScreen();
                break;
        }
    }

    return 0;
}

