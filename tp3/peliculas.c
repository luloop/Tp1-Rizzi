
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "peliculas.h"
#include "lib.h"


/** \brief Funcion de Indice
 * \param estructura de peliculas
 * \param tamanio de array de personas
 * \return VOID
 *
 */
void indiceUsuarios (EMovie peliculas[], int tamanio)
{
    int i;
    for (i=0 ; i<tamanio;i++)
    {
      peliculas[i].estado=0;
    }
}

/** \brief Alta de Pelicula
 *
 * \param Estructura de peliculas
 * \param tamanio de array de pelicula
 * \return Nuevo Flag
 *
 */
int agregarPelicula(EMovie pelicula[], int tamanio)
{
    char seguir ='s';
    int index;
    int cargado=0;
    int i;
    int auxGenero;


    do{
       i=buscarLibre(pelicula, tamanio);
       if (i!=-1)
        {
    pelicula[i].idPelicula = i+10;
    printf("\n \n---- NUEVO INGRESO DE PELICULA %d----\t", i+1);
    printf("\n \nIngrese El Titulo\t");
    fflush(stdin);
    gets(pelicula[i].titulo);
    /////////////pasar a funcion
    printf("----------------------\n");
    printf("Ingrese El Genero\n");
    printf("----------------------");
    printf("\n 1- Terror\t");
    printf("\n 2- Comedia\t");
    printf("\n 3- Drama\t");
    printf("\n 4- Dibujos Animados\t");
    printf("\n 5- Accion\t");
    printf("\n 6- Ciencia Ficcion\t");
    printf("\n 7- Otro\t");
    printf("\n Seleccione la opcion deseada\t");
    scanf("%d", &auxGenero);
    do {
                switch (auxGenero)
                {
                case 1:
                    strcpy(pelicula[i].genero, "Terror");
                    break;
                case 2:
                    strcpy(pelicula[i].genero, "Comedia");
                    break;
                case 3:
                    strcpy(pelicula[i].genero, "Drama");
                    break;
                case 4:
                    strcpy(pelicula[i].genero, "DA");
                    break;
                case 5:
                    strcpy(pelicula[i].genero, "Accion");
                    break;
                case 6:
                    strcpy(pelicula[i].genero, "CF");
                    break;
                case 7:
                    strcpy(pelicula[i].genero, "Otro");
                    break;
                case 8:
                    strcpy(pelicula[i].genero, "Otro");
                    break;
                default:
                    fflush(stdin);
                    printf("NO INGRESO UNA OPCION VALIDA\t");
                    auxGenero=0;
                    break;
                }
    }while (auxGenero==0);

                    printf("\n-----------------------------\n");
                    printf("El genero es %s \t",pelicula[i].genero );
                    printf("\n-----------------------------\n");
                ////////////////////////

                printf("\nIngrese Duracion: \t");
               // fflush(stdin);
                scanf("%d",&pelicula[i].duracion);

                printf("Ingrese Descripcion\t");
                fflush(stdin);
                gets(pelicula[i].descripcion);

                pelicula[i].puntaje=devolverPuntaje();

                printf("Ingrese URL\t");
                fflush(stdin);
                gets(pelicula[i].linkImagen);// eventualmente arma fucniona para validar estos ingresois

                pelicula[i].estado=1;

                cargado=1;
                printf("\n");

                seguir = preguntarSiNo("Cargar otra Pelicula?");
                if (seguir=='n')
                {
                break;
                }

                } //if
            } while (seguir == 's');

return cargado;
}

/** \brief DAR DE BAJA UN USUARIO PASANDO A 2 SU STATUS
 *
 * \param
 * \param
 * \return
 *
 */
void bajaPelicula (EMovie peliculaa[], int tamanio, int flag)
{
int flagDelete;
int i;
int idAux;
char confirm;

     if(flag==0)
            {
                printf("\n\n\n======================\n NO HAY PELICULAS CARGADOS\n======================\n");
            }
        else
            {

                listarPeliculas(peliculaa, tamanio, flag);
                printf("\n========================================================================\n");
                printf("\n\n Ingrese el Id de la peliculaa que desea dar de BAJA:\t");
                scanf("%d", &idAux);
                printf("\n========================================================================\n");
                        for (i=0; i<tamanio;i++)
                            {
                                if (peliculaa[i].idPelicula== idAux)

                                    mostrarPeliculaIndividual(peliculaa[i]);
                                    confirm = preguntarSiNo(" \nSeguro que desea borrar la Pelicula?\t");

                                    if (confirm == 's')
                                     {
                                       peliculaa[i].estado=2;
                                       printf("\n\n======================================================\n");
                                       printf("Pelicula borrada: %s, con el Id  Nro: %d",peliculaa[i].titulo,peliculaa[i].idPelicula);
                                       printf("\n======================================================\n");
                                       flagDelete=1;
                                       break;
                                      }
                                    else
                                      {
                                    printf("\n\n==========================================\n");
                                    printf("Operacion Cancelada");
                                    printf("\n==========================================\n");
                                      }
                            }//fin for

                if (flagDelete==0)
                    {
                            printf("\n\n==========================================\n");
                            printf("La peliculaa que desea borrar no existe");
                            printf("\n==========================================\n");
                    }
               }

       cleanScreen();
}


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void mostrarPeliculaIndividual(EMovie peli)
{
 printf("\nIdPelicula %d \t -- Titulo: %8s -- Genero:%5s -- "
        "Duracion: %d --Puntaje: %0.2f -e: %d" , peli.idPelicula,peli.titulo,peli.genero, peli.duracion, peli.puntaje, peli.estado);
}


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void mostrarUnaPeliculaParaListado(EMovie peli)
{
 printf("\n%4d\t%8s   %5s\t%d\t\t%0.2f\t\t %d" , peli.idPelicula,peli.titulo,peli.genero, peli.duracion, peli.puntaje,peli.estado);
}


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void listarPeliculas(EMovie peliculass[], int tamanio, int flag)
{
    int i;
    if(flag==0)
            {
                printf("\n\n\n======================\n NO HAY PELICULAS CARGADAS\n======================\n");
            }
            else
            {  printf("\n\n\n========================\n PELICULAS CARGADOS\n========================\n");

            printf("\n  Id   Titulo\t      Genero\t    Duracion\t  Puntaje\tEstado");


                for (i=0; i<tamanio; i++)
                {

                    if(peliculass[i].estado==1)
                    {
                   // mostrarUnaPeliculaParaListado(peliculass[i]);
                   mostrarUnaPeliculaParaListado(peliculass[i]);
                        if ((i+1)%25==0 && i!=0) //CADA 25 PELICULAS HAGA UNA PAUSA
                        {  {
                            printf("\n");
                            system ("pause");
                            }
                        } //FIN IF PAUSA
                    }

                }
                printf("\n========================================================================\n");
            }
        cleanScreen();

}




