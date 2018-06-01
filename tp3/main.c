/********************************************************
* Programa : Tp3 laboratorio1_programacion1             *
*                                                       *
* Objetivo : ARCHIVOS Y PUNTEROS                        *
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
#include "peliculas.h"
#include "lib.h"

#define CANTPELIS 10



int main()
{
    int seguir=1;
    int opcion;
    int flagPelis=0;
    int contador=0;
    char salir;

    EMovie peliculas [CANTPELIS];
  /////////////////
    indiceUsuarios(peliculas, CANTPELIS);

    if(cargarDesdeArchivo(peliculas, CANTPELIS))
        {
        printf("No se pudo abrir el fichero");
        }
////////////////

	while(seguir==1)
    {
        contador=contadorArray(peliculas, CANTPELIS);

        printf("\n-------------------------------\n");
        printf("-- BIENVENIDO AL VIDEO CLUB --\n");
        printf("-------------------------------\n");
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar \n");
        printf("4- Generar pagina web\n");
        printf("5- Guardar\n");
        printf("6- Listar Todo\n");
        printf("7- Poner todos disponobles\n");
        printf("0- Salir");
        printf("\n-----------------------------\n\t Ingrese la Opcion: ");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
                flagPelis=agregarPelicula(peliculas, CANTPELIS);
                cleanScreen();
                break;
        case 2:
                if (contador>0 )
                {
                 flagPelis= bajaPelicula(peliculas, CANTPELIS, contador, flagPelis);
                }
                else
                {
                    printf("\n\nNO HAY PELICULAS DISPONIBLES EN EL ARCHIVO ORIGINAL\n");
                }
                cleanScreen();
                break;
        case 3:
                if (contador>0)
                {
                 flagPelis= modificarPelicula(peliculas, CANTPELIS, contador);
                }
                else
                {
                     printf("\n\nNO HAY PELICULAS DISPONIBLES EN EL ARCHIVO ORIGINAL\n");
                }
                cleanScreen();
                break;
        case 4:
            if (contador>0 || flagPelis!=0)
                {
                 flagPelis=htmlArmado(peliculas, CANTPELIS);
                 flagPelis=htmlLISTADO(peliculas, CANTPELIS);
                }
            else
                {
                printf("\n\nNO HAY PELICULAS DISPONIBLES EN EL ARCHIVO ORIGINAL\n");
                }
            cleanScreen();
            break;
        case 5:
                if (flagPelis!=0)
                   {
                   flagPelis=guardarArchivoABM(peliculas, CANTPELIS);
                   }
               else
                   {
                    printf("\n-------------------------------\n");
                    printf("No hay nuevo ingresos sin guardar\n");
                    printf("-------------------------------\n");
                   }
                   cleanScreen();
               break;
        case 6:
            listarTodo(peliculas, CANTPELIS);
            cleanScreen();
          break;
          case 7:
            indiceUsuarios(peliculas, CANTPELIS);
            flagPelis=1;
            cleanScreen();
          break;
        case 0:
               if (flagPelis!=0)
               {
                printf("\n-------------------------------\n");
                salir=preguntarSiNo("Dese Guardar antes de salir?");
                printf("\n-------------------------------\n");
                    if (salir == 's')
                    {
                        if(guardarEnArchivo(peliculas,CANTPELIS))
                        {
						printf("\nNo se pudo abrir el fichero\n");
                        }
                        else
                        {
                        printf("-------------------------------\n");
                        printf("Chau\n");
                        printf("-------------------------------\n");
					    seguir =0;
                        }

                    }
                     else
                       {
                       printf("\n-------------------------------\n");
                       printf("Chau\n");
                       printf("-------------------------------\n");
                       seguir =0;
                       }
               }
               else
               {
               printf("\n-------------------------------\n");
               printf("Chau\n");
               printf("-------------------------------\n");
               seguir =0;
               }

               break;
        default:
                fflush(stdin);
                printf("-------------------------------\n");
                printf("La opcion ingresada no existe \n");
                printf("-------------------------------\n");
                cleanScreen();
                break;
        }
    }

    return 0;
}
