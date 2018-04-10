


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
 int pedirEnteroSintope (char texto[]);
