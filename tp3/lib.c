
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

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

 int guardarEnArchivo(EMovie peliculas [], int contador)
{

	FILE *pelis;

		pelis=fopen("BaseDePeliculas.csv","wb");
		if(pelis== NULL)
		{
			return 1;
		}

	fwrite(peliculas,sizeof(EMovie),contador,pelis);

	fclose(pelis);

	return 0;
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
