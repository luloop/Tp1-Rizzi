
/** \brief SUMAR NUMEROS ENTEROS
 *
 * \param PRIMER NUMERO
 * \param SEGUNDO NUMERO
 * \return SUMA LISTA
 *
 */

 float sumar( int operador1, int operador2)
 {
     float resultado;
     resultado = (float)operador1+ operador2;

     return resultado;
 }



/** \brief RESTAR NUMEROS ENTEROS
 *
 * \param PRIMER NUMERO
 * \param SEGUNDO NUMERO
 * \return SUMA LISTA
 *
 */


  float restar( int operador1, int operador2)
 {
     float resultado;
     resultado = (float)operador1- operador2;

     return resultado;
 }

  /** \brief multiplicar NUMEROS ENTEROS
 *
 * \param PRIMER NUMERO
 * \param SEGUNDO NUMERO
 * \return SUMA LISTA
 *
 */

 float multiplicar( int operador1, int operador2)
  {
     float resultado;
     resultado = (float)operador1*operador2;

     return resultado;
 }


   /** \brief DIVIDIR NUMEROS ENTEROS
 *
 * \param PRIMER NUMERO
 * \param SEGUNDO NUMERO
 * \return SUMA LISTA
 *
 */

 float dividir( int operador1, int operador2)
 {
     float resultado;
     resultado = (float)operador1/operador2;

     return resultado;
 }


 /** \brief FACTORIAL DE 1 NUMERO
 *
 * \param NUMERO
 * \return SUMA LISTA
 *
 */

 float factorial( int operador1)
 {
     float resultado;
     if (operador1==0)
     {
         resultado=1;
     }
     else
        {
     resultado = (float)operador1*factorial(operador1-1);
        }

     return resultado;
 }
