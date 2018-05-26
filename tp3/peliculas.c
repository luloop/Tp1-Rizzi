
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
      peliculas[i].htmlCreado=0;
      strcpy(peliculas[i].titulo, " ");
      strcpy(peliculas[i].descripcion, " ");
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

    printf("\n----------------------\n");
    printf("Ingrese El Genero\n");
    printf("----------------------");
    printf("\n 1- Terror\t");
    printf("\n 2- Comedia\t");
    printf("\n 3- Drama\t");
    printf("\n 4- Dibujos Animados\t");
    printf("\n 5- Accion\t");
    printf("\n 6- Ciencia Ficcion\t");
    printf("\n 7- Otro\t");
      do {
    printf("\n \nSeleccione la opcion deseada\t");
    scanf("%d", &auxGenero);

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
                    printf("\n-----------------------------\n");
                    printf(" NO INGRESO UNA OPCION VALIDA\t");
                     printf("\n-----------------------------\n");
                    auxGenero=0;
                    break;
                }
    }while (auxGenero==0);

                    printf("\n-----------------------------\n");
                    printf("El genero es %s \t",pelicula[i].genero );
                    printf("\n-----------------------------\n");
                ////////////////////////

                strcpy(pelicula[i].nombreArchivo, "\\template");
                strcat(pelicula[i].nombreArchivo, pelicula[i].titulo);
                strcat(pelicula[i].nombreArchivo,"_");
                strcat(pelicula[i].nombreArchivo,pelicula[i].genero);
                strcat(pelicula[i].nombreArchivo,".html");

                pelicula[i].htmlCreado=0;


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
int bajaPelicula (EMovie peliculaa[], int tamanio, int flag)
{
int flagDelete=0;
int i;
int idAux;
char confirm;

     if(flag==0)
            {
                printf("\n\n\n======================\n NO HAY PELICULAS CARGADOS\n======================\n");
            }
        else
            {

                listarPeliculas(peliculaa, tamanio, flag, 1);
                printf("\n========================================================================\n");
                printf("\n\n Ingrese el Id de la peliculaa que desea dar de BAJA:\t");
                scanf("%d", &idAux);
                printf("\n========================================================================\n");
                        for (i=0; i<tamanio;i++)
                            {
                                if (peliculaa[i].idPelicula== idAux && i!=0)
                                {

                                    mostrarPeliculaIndividual(peliculaa[i]);
                                    confirm = preguntarSiNo(" \nSeguro que desea borrar la Pelicula?\t");
                                    flagDelete=1;
                                    if (confirm == 's')
                                     {
                                       peliculaa[i].estado=2;
                                       printf("\n\n======================================================\n");
                                       printf("Pelicula borrada: %s, con el Id  Nro: %d",peliculaa[i].titulo,peliculaa[i].idPelicula);
                                       printf("\n======================================================\n");

                                       return 1;
                                       break;
                                      }
                                    else
                                      {
                                    printf("\n\n==========================================\n");
                                    printf("Operacion Cancelada");
                                    printf("\n==========================================\n\n\n\n");
                                      }

                                }//fin if id =aux


                            }//fin for


               }
                  if (flagDelete==0)
                    {
                            printf("\n\n==========================================\n");
                            printf("La peliculaa que desea borrar no existe");
                            printf("\n==========================================\n");
                            ;
                    }

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
void listarPeliculas(EMovie peliculass[], int tamanio, int flag, int estado)
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

                    if(peliculass[i].estado==estado)
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

}




int htmlArmado(EMovie peliculass[],int tamanio)
{
    FILE* archivo;
    char buffer[1080]= {};
    int idAux;
    int i;
    int flag =1;
    int flag2=0;

        listarPeliculas(peliculass, tamanio, flag, 1);
        printf("\n========================================================================\n");
        printf("\n\n Ingrese el Id de la peliculaa que desea generar el HTML:\t");
        scanf("%d", &idAux);
        printf("\n========================================================================\n");
        for (i=0; i<tamanio;i++)
                            {
                                if (peliculass[i].idPelicula&&idAux && i!=0)
                                {
                                    flag2=1;
                                    break;
                                }
                            }

      if(flag2==1)
      {
       strcat(buffer,"<html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'>"
       " <meta name='viewport' content='width=device-width, initial-scale=1'>"
        "<!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->"
        "<title>Lista peliculas</title>"
        "<!-- Bootstrap Core CSS -->"
        "<link href='css/bootstrap.min.css' rel='stylesheet'>"
        "<!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->"
        "<link href='css/custom.css' rel='stylesheet'>"
        "<!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->"
        "<!-- WARNING: Respond.js doesn't work if you view the page via file:// -->"
        "<!--[if lt IE 9]>"
        "    <script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>"
         " <script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>"
        "<![endif]-->"
        "</head>"
        "<body>   <div class='container'>        <div class='row'>");



        strcat(buffer, "<article class='col-md-4 article-intro'>   <a href='#'>"
        " <img class='img-responsive img-rounded' src='http://ia.media-imdb.com/images/M/MV5BMjA5NTYzMDMyM15BMl5BanBnXkFtZTgwNjU3NDU2MTE@._V1_UX182_CR0,0,182,268_AL_.jpg'"
        "alt=''>"
        "</a>  <h3> <a href='#'>");
        strcat(buffer,peliculass[i].titulo);
        strcat(buffer,"</a>  </h3>  <ul>   <li>");
        strcat(buffer,"Género: ");
        strcat(buffer,peliculass[i].genero);
        strcat(buffer,"</li> <li>Puntaje: ");
        strcat(buffer,(char)peliculass[i].puntaje);
        strcat(buffer,"</li><li>Duración:");
        strcat(buffer,(char)peliculass[i].duracion);
        strcat(buffer,"</li></ul><p>");
        strcat(buffer,peliculass[i].descripcion);


        strcat(buffer,"</p>"
            "</article>"
            "<!-- Repetir esto para cada pelicula -->"
            "</div><!-- /.row --></div><!-- /.container --><!-- jQuery --><script src='js/jquery-1.11.3.min.js'></script><!-- Bootstrap Core JavaScript --><script src='js/bootstrap.min.js'></script>"
            "<!-- IE10 viewport bug workaround -->"
            "<script src='js/ie10-viewport-bug-workaround.js'></script>"
            "<!-- Placeholder Images -->"
            "<script src='js/holder.min.js'></script>"
            "</body>"

            "</html>");










    strcat(buffer,"</h1></MARQUEE><br><br>");
    strcat(buffer,"<table style='width:100%'><tr><th>Firstname</th><th>Lastname</th> <th>Age</th></tr><tr><td>Jill</td><td>Smith</td><td>50</td></tr><tr>"
           " <td>Eve</td><td>Jackson</td><td>94</td></tr><tr> "
           "<td>John</td> <td>Doe</td> <td>80</td></tr></table>"
           "</body></html>");
    archivo = fopen(peliculass[i].nombreArchivo,"w");


    fprintf(archivo,buffer);

    fclose(archivo);
    return 1;
    }
    else
    {
        fflush(stdin);
        printf("\n-----------------------------\n");
        printf(" NO INGRESO UNA PELICULA VALIDA\t");
        printf("\n-----------------------------\n");
        return 0;
    }

}
