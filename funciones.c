
#include "funciones.h" // el .c debe incluir el .h // COMILLAS POR QUE ES UN ARCHIVO LOCAL
#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //biblioteca de getche y getch
#include <ctype.h> //biblioteca de funciones



/** \brief PEDIR AL USUARIO QUE INGRESE UN NUMERO FLOTANTE (sin limitaciones)
 * \param texto para pedir el dato a ingresar
 * \return DATO
 */
 float pedirEnteroSintope (char texto[])
{
    float numero;
    printf("%s",texto); // se adapta al texto del mail
    scanf("%f", &numero);

    return numero;
}

/////////////////////////////// VALIDACIONES ///////////////////////

/** \brief VALIDAR FLAG y cargar dato en caso de flag false
 * \param flag 1
 * \param parametro a ingresar
 * \param texto de los que esta validando
 * \return parametro cargado
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
 * \param PRIMER OPERANDOR
 * \param SEGUNDO OPERADOR
 * \return RESULTADO DE LA SUMA
 */
 float sumar( float operador1, float operador2)
{
    float resultado;
    resultado = operador1+ operador2;
    return resultado;
}


/** \brief RESTAR NUMEROS FLOTANTES
 * \param PRIMER OPERANDOR
 * \param SEGUNDO OPERADOR
 * \return RESULTADO DE LA RESTA
 */
 float restar( float operador1, float operador2)
 {
    float resultado;
    resultado = operador1- operador2;
    return resultado;
 }

  /** \brief MULTIPLICAR NUMEROS FLOTANTE
 * \param PRIMER OPERANDOR
 * \param SEGUNDO OPERADOR
 * \return RESULTADO DE LA MULTIPLICACION
 */
 float multiplicar( float operador1, float operador2)
{
    float resultado;
    resultado = operador1*operador2;
    return resultado;
}


 /** \brief DIVIDIR NUMEROS FLOTANTES (sin validacion?
 * \param PRIMER OPERANDOR
 * \param SEGUNDO OPERADOR
 * \return RESULTADO DE LA DIVISION
 */
 float dividir( float operador1, float operador2)
 {
    float resultado;
    resultado = operador1/operador2;
    return resultado;
 }


 /** \brief FACTORIAL DE 1 NUMERO FLOTANTE
 * \param OPERANDOR CASTEADO
 * \return RESULTADO DEL FACTORIAL
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


 /** \brief MOSTRAR OPERADORES INGRESADO
  * \param OPERADOR1
  * \param OPERADOR2
  * \return VOID
  */
void informarOperadores (float op1, float op2)
{
    printf("\n===================================\n EL PRIMERO OPERANDO ES: %.2f \n ",op1);
    printf("EL SEGUNDO OPERANDO ES: %.2f \n==================================\n ",op2);
}

 /** \brief MOSTRAR TODAS LAS OPERACIONES JUNTAS
  * \param OPERADOR1
  * \param OPERADOR2
  * \return VOID
  */
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

   /** \brief INGRESAR MENU
   * \return LA OPCION ELEGIDA DEL MENU VALIDAD
   */
int ingresarMenu (void)
{
    int opcion;

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

        if (opcion >9 || opcion <1)
        {
        printf("\n-------------------------------- \n LA OPCION ELEGIDA NO ES VALIDA\n-------------------------------- \n");
        printf("\n1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        printf(" \n \t Reingrese la opcion elegida: \t");
        fflush(stdin);
        scanf("%d",&opcion);
        }

        return opcion;
}
