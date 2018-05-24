
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
    if(peliculas[i]. estado!=1 && peliculas[i]. estado!=2)
        {
        peliculas[i]. estado=0;
        }

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
    int contador=0;
    int i;
    int auxGenero;


    do{

   for (i=0; i<tamanio; i++)
       {

           if (pelicula[i].estado==0)
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
                printf("\n 5- Otro\t");
                printf("\n Seleccione la opcion deseada\t");
                scanf("%d", &auxGenero);
                switch (auxGenero)
                {
                case 1:
                    strcpy(pelicula[i].genero, "Terror");
                    printf("El genero es Terror \t");
                    break;
                case 2:
                    strcpy(pelicula[i].genero, "Comedia");
                    printf("El genero es Comedia \t");
                    break;
                case 3:
                    strcpy(pelicula[i].genero, "Drama");
                    printf("El genero es Drama\t");
                    break;
                case 4:
                    strcpy(pelicula[i].genero, "Dibujos Animados");
                    printf("El genero es Dibujos Animados \t");
                    break;
                case 5:
                    strcpy(pelicula[i].genero, "Otro");
                    printf("El genero es OTRO \t");
                    break;
                default:
                    fflush(stdin);
                    printf("NO INGRESO UNA OPCION VALIDA\t");
                    break;
                }
                ////////////////////////

                printf("\n\nIngrese Duracion: \t");
                fflush(stdin);
                scanf("d",pelicula[i].duracion);

                printf("Ingrese Descripcion\t");
                fflush(stdin);
                gets(pelicula[i].descripcion);

                pelicula[i].puntaje=devolverPuntaje();

                printf("\nIngrese URL\t");
                fflush(stdin);
                gets(pelicula[i].linkImagen);// eventualmente arma fucniona para validar estos ingresois

                pelicula[i].estado=1;

                contador++;
                printf("\n");

                seguir = preguntarSiNo("Cargar otra Pelicula?");
                if (seguir=='n')
                {
                break;
                }

                } //if
            }//for
            } while (seguir == 's');

return contador;
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
 printf("\n%10d\t%8s\t%5s\t%d\t%0.2f" , peli.idPelicula,peli.titulo,peli.genero, peli.duracion, peli.puntaje);
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

            printf("\n Id Titulo\t Genero\tDuracion\tPuntaje\tEstado");

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


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int cargarDesdeArchivo(EMovie peliculas[],int CANTPELIS)
{
	int flag = 0;
	FILE *pelis;

	pelis=fopen("BaseDePeliculas.csv", "rb");
	if(pelis==NULL)
	{
		pelis= fopen("BaseDePeliculas.csv", "wb");
		if(pelis==NULL)
		{
			return 1;
		}

		flag=1;

	}

	if(flag ==0)
	{
	fread(peliculas,sizeof(EMovie),CANTPELIS,pelis);
    }

	fclose(pelis);
	return 0;

}


