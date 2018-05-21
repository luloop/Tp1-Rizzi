#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"

#define CANTPELIS 20


int main()
{
    char seguir='s';
    int opcion=0;
    int flagPelis=0;


    EMovie peliculas [CANTPELIS];
    EMovie pelicula;
    EMovie *pPeliculas =NULL;

    pPeliculas=peliculas;

    FILE *pArchivo;

    pArchivo=fopen("peliculas-descripcion.txt", "w");

    indiceUsuarios(peliculas, CANTPELIS);

    if ( pArchivo!=NULL)
    {

    //fprintf(parchivo, "Holaaaaaaaaaa");

    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Generar pagina web\n");
        printf("4- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                flagPelis=agregarPelicula(pPeliculas, CANTPELIS);
                break;
            case 2:
                break;
            case 3:
               break;
            case 4:
                seguir = 'n';
                break;
        }
    }
    fclose(pArchivo);
    printf("Guardado");
    } // FIN IF DE !=NULL
    else
    {
         printf("No Existe");
    }


    return 0;
}
