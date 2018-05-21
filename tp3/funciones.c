#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "funciones.h"


/** \brief Funcion de Indice
 * \param estructura de peliculas
 * \param tamanio de array de personas
 * \return VOID
 *
 */
void indiceUsuarios (EMovie* peliculas, int tamanio)
{
    int i;
    for (i=0 ; i<tamanio;i++)
    {
    (peliculas+i)->estado=0;
    }
}

/** \brief Alta de Pelicula
 *
 * \param Estructura de peliculas
 * \param tamanio de array de pelicula
 * \return Nuevo Flag
 *
 */
int agregarPelicula(EMovie *pelicula, int tamanio)
{
    int seguir='s';
    int index;
    int flag;
    int i;
    int auxGenero;

    for (i=0; i<tamanio; i++)
       {
           while (seguir == 's')
            {
                if ((pelicula+i)->estado==0)
                {
                printf("\n \n---- NUEVO INGRESO DE PELICULA-----\t");

                printf("\n \nIngrese El Titulo\t");
                fflush(stdin);
                gets((pelicula+i)->titulo);
                /////////////pasar a funcion
                printf("\n \nIngrese El Genero\t");
                printf("\n 1- Terror\t");
                printf("\n 2- Comedia\t");
                printf("\n 3- Drama\t");
                printf("\n 4- Dibujos Animados\t");
                printf("\n 5- Otro\t");
                printf("\n 6- SALIR\t");
                printf("\n Seleccione la opcion deseada\t");
                scanf("%d", &auxGenero);
                switch (auxGenero)
                {
                case 1:
                    strcpy((pelicula+i)->genero, "Terror");
                    break;
                case 2:
                    strcpy((pelicula+i)->genero, "Comedia");
                    break;
                case 3:
                    strcpy((pelicula+i)->genero, "Drama");
                    break;
                case 4:
                    strcpy((pelicula+i)->genero, "Dibujos Animados");
                    break;
                case 5:
                    strcpy((pelicula+i)->genero, "Drama");
                    break;
                case 6:
                    seguir='n';
                    break;
                default:
                    fflush(stdin);
                    printf("\n NO INGRESO UNA OPCION VALIDA\t");
                    break;
                }
                ////////////////////////

                printf("\nIngrese Duracion: \t");
                fflush(stdin);
                scanf("d",(pelicula+i)->duracion);

                printf("\nIngrese Descripcion\t");
                fflush(stdin);
                gets((pelicula+i)->descripcion);

                (pelicula+i)->puntaje=0;

                printf("\nIngrese URL\t");
                fflush(stdin);
                gets((pelicula+i)->linkImagen);// eventualmente arma fucniona para validar estos ingresois

                (pelicula+i)->estado=1;

                flag=1;
                printf("\n");

                seguir = preguntarSiNo("Cargar otra Pelicula?");
                } //if

            }//while
            break;

            }//for

return flag;
}


 /** \brief Pregunta S o N
 * *
 * \param texto de la pregunta
 * \return respuesta
 *
 */
 char preguntarSiNo ( char texto [])
 {
     char respuesta;

     printf("%s S o N:", texto);
     fflush(stdin);
     respuesta= tolower(getche());

    while (respuesta != 's' && respuesta !='n')
        {
        printf(" \nRespuesta Incorrecta-%s\t",texto);
        fflush(stdin);
        respuesta= tolower(getche());
        }

  return respuesta;
}
