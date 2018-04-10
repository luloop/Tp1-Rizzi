
#include "funciones.h" // el .c debe incluir el .h // COMILLAS POR QUE ES UN ARCHIVO LOCAL
#include <stdio.h>
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
 float pedirEnteroSintope (char texto[])
{
    float numero;

    printf("%s",texto); // se adapta al texto del mail
    scanf("%f", &numero);

    return numero;
}

/////////////////////////////// VALIDACIONES ///////////////////////

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

/** \brief VALIDAR FLAG
 * \param flag 1
 * \return CARGA DE DATOS EN VARIBLAES OPERADORES
 *
 */

float validarFlags (int bandera1, float operando1,char texto[])
 {
     if (bandera1==0)
     {
      operando1=pedirEnteroSintope(texto);
     }
     return operando1;

 }


//////////////////////////// OPERACIONES ///////////////////////////

/** \brief SUMAR NUMEROS FLOTANTE
 *
 * \param PRIMER NUMERO
 * \param SEGUNDO NUMERO
 * \return SUMA LISTA
 *
 */

 float sumar( float operador1, float operador2)
 {
     float resultado;
     resultado = operador1+ operador2;

     return resultado;
 }



/** \brief RESTAR NUMEROS FLOTANTES
 * \param PRIMER NUMERO
 * \param SEGUNDO NUMERO
 * \return SUMA LISTA
 *
 */


  float restar( float operador1, float operador2)
 {
     float resultado;
     resultado = operador1- operador2;

     return resultado;
 }

  /** \brief multiplicar NUMEROS FLOTANTE
 *
 * \param PRIMER NUMERO
 * \param SEGUNDO NUMERO
 * \return SUMA LISTA
 *
 */

 float multiplicar( float operador1, float operador2)
  {
     float resultado;
     resultado = operador1*operador2;

     return resultado;
 }


   /** \brief DIVIDIR NUMEROS FLOTANTES
 *
 * \param PRIMER NUMERO
 * \param SEGUNDO NUMERO
 * \return SUMA LISTA
 *
 */

 float dividir( float operador1, float operador2)
 {
     float resultado;
     resultado = operador1/operador2;

     return resultado;
 }


 /** \brief FACTORIAL DE 1 NUMERO
 *
 * \param NUMERO
 * \return SUMA LISTA
 *
 */

 float factorial( float operador1)
 {
     float resultado;
     if ((int)operador1==0)
     {
         resultado=1;
     }
     else
        {
     resultado = operador1*factorial(operador1-1);
        }

     return resultado;

}

////////////////////////////////MOSTRAR - OPERACIONES VOID/////////////////////////

void informarOperadores (float op1, float op2)
{
    printf("\n===================================\n EL PRIMERO OPERANDO ES: %.2f \n ",op1);
    printf("EL SEGUNDO OPERANDO ES: %.2f \n==================================\n ",op2);
}


void calcularTodasOperaciones (float primerOperando, float segundooperando)
{
float multi;
float suma;
float divi;
float rest;
float facto;

    multi=multiplicar(primerOperando,segundooperando);
    suma= sumar(primerOperando,segundooperando);
    divi=dividir(primerOperando,segundooperando);
    rest=restar(primerOperando,segundooperando);
    facto=factorial((int)primerOperando);

     if (segundooperando==0)
        {
        printf("\n La suma es:\t \t  %.2f \n La resta es: \t \t  %.2f \n La division no se puede realizar \n La multiplicacion es:\t  %.2f \n El factorial es:\t  %.2f \n \n", suma,rest,multi,facto);
        }
        else
        {
        printf("\n La suma es:\t \t  %.2f \n La resta es:\t \t  %.2f \n La division es:\t  %.2f \n La multiplicacion es:\t  %.2f \n El factorial es:\t  %.2f \n \n", suma,rest,divi,multi,facto);
        }
}


int ingresarMenu (void)
{ int opcion;
        printf("\n1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        printf(" \n \t Ingrese la opcion elegida: \t");

        scanf("%d",&opcion);

        return opcion;
}
