#include "PedirNumeros.h" // el .c debe incluir el .h // COMILLAS POR QUE ES UN ARCHIVO LOCAL
#include <stdio.h>
#include "validaciones.h"
#include <stdlib.h>
#include <conio.h> //biblioteca de getche y getch
#include <ctype.h> //biblioteca de funciones


/** \brief VALIDACION DEL NUMERO DADO POR EL USUARIO
 *
 * \param texto para pedir el dato a ingresar
 * \param MAXIMO
  * \param MINIMO
 * \return DATO VALIDADO
 *
 */
 int pedirEntero (char texto[], int min, int max)
{
    int numero;

    printf("%s",texto); // se adapta al texto del mail
    scanf("%d", &numero);
    numero = validarEntero(numero, min, max);

    return numero;
}

/** \brief PEDIR UN NUMERO FLOTANTE
 *
 * \param texto de lo que pide
 * \param numero minimo
 * \param numero maximo
 * \return UN NUMERO FLOTANTE VALIDADO ENTRE UN MAXIMO Y UN MINIMO
 *
 */
float pedirFlotante (char texto[], float min, float max)
{
    float numero;

    printf("%s",texto); // se adapta al texto del mail
    scanf("%f", &numero);
    numero = validarFlotante(numero, min, max);

    return numero;
}

/** \brief PEDIR UN CARACTER ASCII
 *
 * \param texto de lo que pide
 * \param CARACTER minimo
 * \param CARACTER maximo
 * \return UN CARACTER VALIDADO ENTRE UN MAXIMO Y UN MINIMO
 *
 */
char pedirCaracter (char texto[], char min, char max)
{
    char caracter;

    printf("%s",texto); // se adapta al texto del mail
    caracter = getche();
    caracter= validarCaracter(caracter, min, max);

    return caracter;

    }

    /** \brief PEDIR UNA OPERACION
 *\param TEXTO
 * \param OPERACION 1
 * \param  OPERACION 2
  \param  OPERACION 3
 * \param  OPERACION 4
 * \return UN CARACTER VALIDADO ENTRE UN MAXIMO Y UN MINIMO
 *
 */
char pedirOperacion(char texto[], char op1,char op2,char op3,char op4)
{
    char operacion;
    printf("%s",texto); // se adapta al texto del mail
    operacion = getche();
    operacion= validarOperacion(operacion, op1, op2, op3, op4);
    return operacion;
    }

/** \brief PREGUNTAR ENTRE 2 COSAS
 *\param TEXTO
 * \param OPCION 1
 * \param  OPCION 2
 * \return UN CARACTER VALIDADO ENTRE UN MAXIMO Y UN MINIMO
 *
 */
char preguntar(char texto[], char op1,char op2)
{
    char respuesta;
    printf("%s",texto); // se adapta al texto del mail
    respuesta= getche();
    respuesta= validarEntre2Datos(respuesta, op1, op2);
    return respuesta;
    }

/** \brief VALIDACION DEL NUMERO DADO POR EL USUARIO
 *
 * \param texto para pedir el dato a ingresar
 * \param MAXIMO
  * \param MINIMO
 * \return DATO VALIDADO
 *
 */
 int pedirEnteroSintope (char texto[])
{
    int numero;

    printf("%s",texto); // se adapta al texto del mail
    scanf("%d", &numero);

    return numero;
}
