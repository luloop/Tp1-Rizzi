/** \brief PEDIR AL USUARIO QUE INGRESE UN NUMERO FLOTANTE (sin limitaciones)
 * \param texto para pedir el dato a ingresar
 * \return DATO
 */
 float pedirEnteroSintope (char texto[]);


 ////////////////////////// VALIDACIONES///////////////////////////

/** \brief VALIDAR FLAG
 * \param flag 1
 * \param parametro a ingresar
 * \param texto de los que esta validando
 * \return CARGA DE DATOS EN VARIBLAES OPERADORES
 */

float validarFlags (int bandera1, float operando1,char texto[]);


/////////////////////////////OPERACIONES////////////////////////////


/** \brief SUMAR NUMEROS FLOTANTE
 * \param PRIMER OPERANDOR
 * \param SEGUNDO OPERADOR
 * \return RESULTADO DE LA SUMA
 */
 float sumar( float operador1, float operador2);


/** \brief RESTAR NUMEROS FLOTANTES
 * \param PRIMER OPERANDOR
 * \param SEGUNDO OPERADOR
 * \return RESULTADO DE LA RESTA
 */
  float restar( float operador1, float operador2);


/** \brief MULTIPLICAR NUMEROS FLOTANTE
 * \param PRIMER OPERANDOR
 * \param SEGUNDO OPERADOR
 * \return RESULTADO DE LA MULTIPLICACION
 */
 float multiplicar( float operador1, float operador2);


 /** \brief DIVIDIR NUMEROS FLOTANTES (sin validacion?
 * \param PRIMER OPERANDOR
 * \param SEGUNDO OPERADOR
 * \return RESULTADO DE LA DIVISION
 */
 float dividir( float operador1, float operador2);


 /** \brief FACTORIAL DE 1 NUMERO FLOTANTE
 * \param OPERANDOR CASTEADO
 * \return RESULTADO DEL FACTORIAL
 */
 float factorial(float operador1);

////////////////////////////////MOSTRAR - OPERACIONES VOID/////////////////////////

 /** \brief MOSTRAR OPERADORES INGRESADO
  * \param OPERADOR1
  * \param OPERADOR2
  * \return VOID
  */
  void informarOperadores (float op1, float op2);

  /** \brief MOSTRAR TODAS LAS OPERACIONES JUNTAS
  *
  * \param OPERADOR1
  * \param OPERADOR2
  * \return VOID
  */
  void calcularTodasOperaciones (float , float);

  /** \brief INGRESAR MENU
   * \return LA OPCION ELEGIDA DEL MENU VALIDAD
   */
    int ingresarMenu (void);


