
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "peliculas.h"
#include "lib.h"


/** \brief LIMPIAR PANATALLA
 *
 */
void cleanScreen (void)
{
            printf("\n");
            system ("pause");
            system ("cls");
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

/** \brief devolver numero random float //////////arreglar!!!!!!!
 * \param
 * \param
 * \return
 *
 */

float devolverPuntaje()
{
    float random;
    srand(time(NULL));
    random = (rand()%11)+1;
    return random;

}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int guardarEnArchivo(EMovie peliculas [], int cantidad)
 {
	FILE *pelis;
	int i=0;
	int j;
     //   listarPeliculas(peliculas, 20, 1);
		pelis=fopen("BaseDePeliculas.data","wb");
		if(pelis== NULL)
		{
       return 1;
		}
        else
        {
        while(i<=cantidad)
        {
            fwrite(&peliculas[i] ,sizeof(EMovie),1,pelis);
            i++;
        }

        }

    fclose(pelis);
       return 0;
        }


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int guardarArchivoABM (EMovie peliculas [], int cantidad)
{
    char guardar;

        if (cantidad>0)
            {
            guardar=preguntarSiNo("\nDesea guardar los cambios realizados?");
            if (guardar == 's')
            {
                if(guardarEnArchivo(peliculas,cantidad))
                {
                printf("\nNo se pudo abrir el fichero\n");
                }
                else
                {
                cantidad=0;
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
        else
        {
        printf("\n-------------------------------\n");
        printf("NO HAY NADA PARA GUARDAR\n");
        printf("-------------------------------\n");
        }

        return cantidad;
}


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int cargarDesdeArchivo(EMovie peliculas[])
{
	FILE *pelis;
	int i=0;
	int flag = 0;

	pelis=fopen("BaseDePeliculas.data", "rb");
    if(pelis==NULL)
    {
        pelis= fopen("BaseDePeliculas.data", "wb");
        if(pelis==NULL)
        {
        return 1;
        }
        flag=1;
        }

	if(flag==0)
	{
        while(feof(pelis)==0)
        {
        fread(&peliculas[i],sizeof(EMovie),1,pelis);
        i++;
        }
    }

	fclose(pelis);
	return 0;

}

////////////////////////////////////////

int buscarLibre(EMovie losAlumnos[], int cantidad)
{
	int index=-1;
	int i;
	for( i=0; i < cantidad; i++)
	   if(losAlumnos[i].estado==0){
		index=i;
		break;
	   }
	return index;
}
