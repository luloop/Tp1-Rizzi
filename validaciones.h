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


/** \brief VALIDAR ENTRE 2 FLAGS
 *
 * \param flag 1
 * \param flag 2
 * \return CARGA DE DATOS EN VARIBLAES OPERADORES
 *
 */

int validarFlags (int bandera1, int operando1,char texto[]);
