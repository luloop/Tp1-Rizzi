/** \brief PEDIR UN NUMERO ENTERO
 *
 * \param texto de lo que pide
 * \param numero minimo
 * \param numero maximo
 * \return UN NUMERO ENTERO VALIDADO ENTRE UN MAXIMO Y UN MINIMO
 *
 */
int pedirEntero (char texto[], int min, int max);

/** \brief PEDIR UN NUMERO FLOTANTE
 *
 * \param texto de lo que pide
 * \param numero minimo
 * \param numero maximo
 * \return UN NUMERO FLOTANTE VALIDADO ENTRE UN MAXIMO Y UN MINIMO
 *
 */
float pedirFlotante (char texto[], float min, float max);

/** \brief PEDIR UN CARACTER ASCII
 *
 * \param texto de lo que pide
 * \param CARACTER minimo
 * \param CARACTER maximo
 * \return UN CARACTER VALIDADO ENTRE UN MAXIMO Y UN MINIMO
 *
 */
char pedirCaracter (char texto[], char min, char max);


/** \brief PEDIR UNA OPERACION
 *
 * \param OPERACION 1
 * \param  OPERACION 2
  \param  OPERACION 3
 * \param  OPERACION 4
 * \return UN CARACTER VALIDADO ENTRE UN MAXIMO Y UN MINIMO
 *
 */
char pedirOperacion(char texto[], char op1,char op2,char op3,char op4);

/** \brief PREGUNTAR ENTRE 2 COSAS
 *
 * \param OPCION 1
 * \param  OPCION 2
 * \return UN CARACTER VALIDADO ENTRE UN MAXIMO Y UN MINIMO
 *
 */
char preguntar(char texto[], char op1,char op2);

/** \brief PEDIR ENTERO SIN LIMITACIONES
 *
 * \param texto para pedir el dato a ingresar
 * \param MAXIMO
  * \param MINIMO
 * \return DATO VALIDADO
 *
 */
 float pedirEnteroSintope (char texto[]);


 ////////////////////////// VALIDACIONES///////////////////////////
 /** \brief VALIDACION DEL NUMERO ENTERO DADO POR EL USUARIO
 *
 * \param DATO INGRESADO
 * \param MAXIMO
  * \param MINIMO
 * \return DATO VALIDADO
 *
 */
int validarEntero(int dato, int min, int max);


/** \brief VALIDACION DEL NUMERO FLOTANTE DADO POR EL USUARIO
 *
 * \param DATO INGRESADO
 * \param MAXIMO
  * \param MINIMO
 * \return DATO VALIDADO
 *
 */
float validarFlotante(float dato, float min, float max);


/** \brief VALIDACION DEL CARACTER DADO POR EL USUARIO
 *
 * \param DATO INGRESADO
 * \param MAXIMO
  * \param MINIMO
 * \return DATO VALIDADO
 *
 */
char validarCaracter(char dato, char min, char max);

/** \brief VALIDACION DE UNA OPERACION
 *
 * \param OPERACION 1
 * \param  OPERACION 2
  \param  OPERACION 3
 * \param  OPERACION 4
 * \return UN CARACTER VALIDADO ENTRE UN MAXIMO Y UN MINIMO
 *
 */
char validarOperacion(char dato, char op1,char op2,char op3,char op4);


/** \brief VALIDACION entre 2 datos
 *
 * \param DATO
 * \param  opcion 1
 * \param  opcion 2
 * \return UN CARACTER VALIDADO ENTRE UN MAXIMO Y UN MINIMO
 *
 */
char validarEntre2Datos(char dato, char op1,char op2);


/** \brief VALIDAR FLAG
 *
 * \param flag 1
 * \param flag 2
 * \return CARGA DE DATOS EN VARIBLAES OPERADORES
 *
 */

int validarFlags (int bandera1, float operando1,char texto[]);


/////////////////////////////OPERACIONES////////////////////////////


/** \brief SUMAR NUMEROS FLOTANTE
 *
 * \param PRIMER NUMERO
 * \param SEGUNDO NUMERO
 * \return SUMA LISTA
 *
 */

 float sumar( float operador1, float operador2);


/** \brief RESTAR NUMEROS FLOTANTES
 * \param PRIMER NUMERO
 * \param SEGUNDO NUMERO
 * \return SUMA LISTA
 *
 */
  float restar( float operador1, float operador2);


  /** \brief multiplicar NUMEROS FLOTANTE
 *
 * \param PRIMER NUMERO
 * \param SEGUNDO NUMERO
 * \return SUMA LISTA
 *
 */
 float multiplicar( float operador1, float operador2);


/** \brief DIVIDIR NUMEROS FLOTANTES
 *
 * \param PRIMER NUMERO
 * \param SEGUNDO NUMERO
 * \return SUMA LISTA
 *
 */
 float dividir( float operador1, float operador2);


/** \brief FACTORIAL DE 1 NUMERO
 *
 * \param NUMERO
 * \return SUMA LISTA
 *
 */
 float factorial(float operador1);


 /** \brief MOSTRAR OPERADORES INGRESADO
  *
  * \param OPERADOR1
  * \param OPERADOR2
  * \return VOID
  *
  */
  void informarOperadores (float op1, float op2);

   /** \brief MOSTRAR TODAS LAS OPERACIONES JUNTAS
  *
  * \param OPERADOR1
  * \param OPERADOR2
  * \return VOID
  */
  void calcularTodasOperaciones (float , float);


