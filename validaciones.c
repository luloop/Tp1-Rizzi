#include <stdio.h>
#include <stdlib.h>
#include "PedirNumeros.h"
#include <conio.h> //biblioteca de getche y getch
#include <ctype.h> //biblioteca de funciones


/** \brief DEVUELVE UN NUMERO ENTERO INGRESADO POR USUARIO
 *  \param texto a mostrar
 *  \param valir minimo
 *  \param valor maximo
 *  \return numero ingresado
 */

int validarEntero(int dato, int min, int max)
{
   while ( dato <min || dato > max)
                {
               printf("\t Error reingrese \t");
               scanf("%d", &dato);
               }


    return dato;

    }

/** \brief VALIDACION DEL NUMERO FLOTANTE DADO POR EL USUARIO
 *
 * \param DATO INGRESADO
 * \param MAXIMO
  * \param MINIMO
 * \return DATO VALIDADO
 *
 */
float validarFlotante(float dato, float min, float max)
{
    while ( dato <min || dato > max)
                {
               printf("\t Error reingrese \t");
               scanf("%f", &dato);
               }
    return dato;


}

    /** \brief VALIDACION DEL CARACTER DADO POR EL USUARIO
 *
 * \param DATO INGRESADO
 * \param MAXIMO
  * \param MINIMO
 * \return DATO VALIDADO
 *
 */
char validarCaracter(char dato, char min, char max)
{
    while ( dato <min || dato > max)
                {
               printf("\t Error reingrese \t");
               dato=getche();
               }
    return dato;

    }


/** \brief VALIDACION DE UNA OPERACION
 *
 * \param OPERACION 1
 * \param  OPERACION 2
  \param  OPERACION 3
 * \param  OPERACION 4
 * \return UN CARACTER VALIDADO ENTRE UN MAXIMO Y UN MINIMO
 *
 */
char validarOperacion(char dato, char op1,char op2,char op3,char op4)
{
    while ( dato !=op1 && dato !=op2 && dato !=op3 && dato !=op4)
                {
               printf("\t Error reingrese \t");
               dato=getche();
               }
    return dato;

    }


/** \brief VALIDACION entre 2 datos
 *
 * \param DATO
 * \param  opcion 1
 * \param  opcion 2
 * \return UN CARACTER VALIDADO ENTRE UN MAXIMO Y UN MINIMO
 *
 */
char validarEntre2Datos(char dato, char op1,char op2)
{
    while ( dato !=op1 && dato !=op2)
                {
               printf("\t Error reingrese \t");
               dato= getche();
               }
    return dato;

    }

/** \brief VALIDAR ENTRE 2 FLAGS
 *
 * \param flag
 * \param operando A
 * \return CARGA DE DATOS EN VARIBLAES OPERADORES
 *
 */

 int validarFlags (int bandera1, int operando1,char texto[])
 {
     if (bandera1==0)
     {
      operando1=pedirEnteroSintope(texto);
     }
     return operando1;

 }



