#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "peliculas.h"
#include "lib.h"

#define CANTPELIS 20


int main()
{
    int seguir=1;
    int opcion;
    int flagPelis=0;
    char guardar;
    int contador=0;
    char salir;

    EMovie peliculas [CANTPELIS];
    EMovie pelicula;
/////////////////
    indiceUsuarios(peliculas, CANTPELIS);

    if(cargarDesdeArchivo(peliculas))
        {
        printf("No se pudo abrir el fichero");
        }
	else
        {
        flagPelis=1;
        }
////////////////
	while(seguir==1)
    {

        printf("\n-------------------------------\n");
        printf("-- BIENVENIDO AL VIDEO CLUB --\n");
        printf("-------------------------------\n");
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Generar pagina web\n");
        printf("4- Guardar\n");
        printf("0- Salir");
        printf("\n-----------------------------\n\t Ingrese la Opcion: ");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
                contador=agregarPelicula(peliculas, CANTPELIS);
                cleanScreen();
                break;
        case 2:
                if (flagPelis==1)
                {
                  listarPeliculas(peliculas, CANTPELIS, flagPelis);

                }
                break;
        case 3:
               break;
        case 4:
                if (contador!=0)
               {
               contador=guardarArchivoABM(peliculas, CANTPELIS);
               }
               else
                   {
                    printf("\n-------------------------------\n");
                    printf("No hay nuevo ingresos sin guardar\n");
                    printf("-------------------------------\n");
                   }
               cleanScreen();
               break;
        case 0:
               if (contador!=0)
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
						printf("\n-------------------------------\n");
						printf("\nSe guardo la informacion con exito\n");
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
