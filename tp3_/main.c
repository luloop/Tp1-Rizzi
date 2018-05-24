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
    int contador;
    int flagGuardar=0;
    char salir;

    EMovie peliculas [CANTPELIS];
    EMovie pelicula;

    if(cargarDesdeArchivo(peliculas, 10))
	{
	printf("No se pudo abrir el fichero");
	}
	else
	{
	flagPelis=1;
	}
	indiceUsuarios(peliculas, CANTPELIS);
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
                flagGuardar=0;
                cleanScreen();
                break;
        case 2:
                if (flagPelis==1)
                {

                  listarPeliculas(peliculas, CANTPELIS, flagPelis);
              //  bajaPelicula(peliculas, CANTPELIS, flagPelis);
                }

                break;
        case 3:
               break;

        case 0:
               if (flagGuardar==0)
               {
                printf("\n-------------------------------\n");
                salir=preguntarSiNo("Dese Guardar antes de salir?");
                printf("-------------------------------\n");
                    if (salir == 's')
                    {
                        if(guardarEnArchivo(peliculas,contador))
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
						flagGuardar=1;
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
        case 4:
               if (contador !=0)
               {
               guardar=preguntarSiNo("\nDesea guardar los cambios realizados?");
               if (guardar == 's')
               {
                   if(guardarEnArchivo(peliculas,contador))
					{
						printf("\nNo se pudo abrir el fichero\n");
					}
					else
					{
						printf("\nSe guardo la informacion con exito\n");
						flagGuardar=1;
					}
               }
               else
               {
               printf("-------------------------------\n");
               printf("Operacion Cancelada\n");
               printf("-------------------------------\n");
               }
               cleanScreen();
               }


               break;
        default:
                fflush(stdin);
                printf("-------------------------------\n");
                printf("La opcion ingresda no existe \n");
                printf("-------------------------------\n");

                cleanScreen();
                break;
        }
    }

    return 0;
}