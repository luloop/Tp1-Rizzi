#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

/** \brief Funcion de Indice con la carga inicial de 10 Usuarios para poder operar
 *
 * \param estructura de usuarios
 * \param tamanio de array de personas
 * \return VOID
 *
 */
void indiceUsuarios (ePersona usuarios[], int tamanio)
{

    int i;
    for (i=0 ; i<tamanio;i++)
    {
    usuarios[i].estado=0;
    usuarios[i].edad=0;
    usuarios[i].dni=30887699+i;
    }

    strcpy(usuarios[0].nombre, "XOzoz");
    strcpy(usuarios[1].nombre, "Lucila");
    strcpy(usuarios[2].nombre, "MArco");
    strcpy(usuarios[3].nombre, "Caro");
    strcpy(usuarios[4].nombre, "ANA");
    strcpy(usuarios[5].nombre, "Marco");
    strcpy(usuarios[6].nombre, "Caro");
    strcpy(usuarios[7].nombre, "Ana");
    strcpy(usuarios[8].nombre, "Caro");
    strcpy(usuarios[9].nombre, "Ana");
    strcpy(usuarios[10].nombre, "Zozoz");
    strcpy(usuarios[11].nombre, "Lucila");
    strcpy(usuarios[12].nombre, "Marco");
    strcpy(usuarios[13].nombre, "Caro");
    strcpy(usuarios[14].nombre, "Ana");

    usuarios[0].edad=16;
    usuarios[1].edad=17;
    usuarios[2].edad=21;
    usuarios[3].edad=28;
    usuarios[4].edad=45;
    usuarios[5].edad=14;
    usuarios[6].edad=56;
    usuarios[7].edad=36;
    usuarios[8].edad=56;
    usuarios[9].edad=34;
    usuarios[10].edad=15;
    usuarios[11].edad=18;
    usuarios[12].edad=22;
    usuarios[13].edad=39;
    usuarios[14].edad=12;

    for (i=0; i<15; i++)
    {
    usuarios[i].estado=1;
    }
}


/** \brief Alta de usuario
 *
 * \param Estructura de usuario
 * \param tamanio de array de usuarios
 * \return Nuevo Flag
 *
 */
int  altaUsuario (ePersona users[], int tamanio)
{
    int seguir='s';
    int index;
    int flag;
    while (seguir == 's')
        {
            index=searchIndexUsers(users, tamanio);
            if (index != -1)
                {
           //     printf("\n\n---PRUEBA DE INDEX %d \t STATUS %d\n\n",index, users[index].estado);

                printf("\n \nIngrese su Nombre\t");
                fflush(stdin);
                gets(users[index].nombre);

                printf("Ingrese su edad:\t");
                 scanf("%d", &users[index].edad);
                 while (users[index].edad<0 || users[index].edad>100)
                 {
                 printf("Error! Ingrese una edad valida entre 1 y 99:\t");
                 scanf("%d", &users[index].edad);
                 }

                printf("Ingrese su DNI\t");
                scanf("%d",&users[index].dni);
                while (users[index].dni<1000000|| users[index].dni>100000000)
                 {
                 printf("Error! Ingrese una DNI valido entre 1.000.000 y 100.000.000:\t");
                 scanf("%d", &users[index].dni);
                 }

                users[index].estado=1;
                flag=1;

                printf("\t \t Cargar otro usuario? S-N\t");
                fflush(stdin);
                seguir= getche();
                seguir = ValidacionSiNo(seguir,"\n Respuesta Incorrecta - Cargar otro usuario? S-N");
                                }
            else
                {
                printf("\n\n\n===========================\n CUPO DE USUARIOS LLENO\n===========================\n");
                break;
                }
        }
return flag;
}

/** \brief Busqueda de espacio disponible via indice para iniciar la carga segun su esta
 * \param Estructura de personas
 * \param tamanio del array
 * \return primer ubicacion disponible en el array
 *
 */
int searchIndexUsers ( ePersona status[], int tamanio)
{
    int index=-1;
    int i;
    for (i=0 ; i<tamanio ; i++)
            {
                if (status[i].estado==0)
                {
                   index = i;
                   break;
                }
            }
    return index;
}

/** \brief Validar una respuesta por S o N
 *
 * \param respuesta ingresada
 * \param Texto de la validacion
 * \return respuesta validada
 *
 */
 char ValidacionSiNo (char respuesta , char texto [])
{
    while (respuesta != 's' && respuesta !='n')
        {
        printf(" \n %s :\t",texto);
        fflush(stdin);
        respuesta= tolower(getche());
        }
  return respuesta;
}
/** \brief Baja de usuario, pasa el status a Numero 2 para dejar disponible los usuarios borrados
 *
 * \param Estructura de Personas
 * \param tamaño del array
 * \param flag de carga de usuarios
 * \return void
 *
 */
void bajaUsuario (ePersona users[], int tamanio, int flag)
{
int flagDelete;
int i;
int idAux;
int confirm;

     if(flag==0)
            {
               printf("\n\n\n======================\n NO HAY USUARIOS CARGADOS\n======================\n");
            }
        else
            {
               listadoDeUsuarios(users, tamanio);
                printf("\n========================================================================\n");

                printf("\n========================================================================\n");
                printf("\n\n Ingrese el DNI del Usuarios que desea dar de BAJA:\t");
                scanf("%d", &idAux);
                printf("\n========================================================================\n");
                    flagDelete=0;
                        for (i=0; i<tamanio;i++)
                            {
                                if (users[i].dni== idAux && users[i].estado ==1)
                                    {
                                    printf(" \nSeguro que desea borrar al usuario %s ? S/N\t", users[i].nombre);
                                    fflush(stdin);
                                    confirm= tolower(getche());
                                    confirm =ValidacionSiNo(confirm,(" Respuesta incorrecta - Seguro que desea borrar al ussuario %s:\t", users[i].nombre));
                                     if (confirm == 's')
                                        {
                                        users[i].estado=2;
                                        printf("\n\n======================================\n");
                                        printf("Usuario borrado: %s, con el DNI  Nro: %d", users[i].nombre, users[i].dni);
                                        printf("\n======================================\n");
                                        flagDelete=1;
                                        break;
                                        }
                                    else if (confirm == 'n')
                                        {
                                        printf("\n\n==========================================\n");
                                        printf("Operacion Cancelada");
                                        printf("\n==========================================\n");
                                        flagDelete=1;
                                        break;
                                        }
                                    }
                            }

                    if (flagDelete==0)
                    {
                            printf("\n\n==========================================\n");
                            printf("El users que desea borrar no existe");
                            printf("\n==========================================\n");
                    }


            }

}


/** \brief Listado de usuarios cargados, busca estado 1 y publica
 *
 * \param Estructura de personas
 * \param tamaño del array de personas
 * \return
 *
 */

void listadoDeUsuarios (ePersona users [], int tamanio)
 {
      int i;
      printf("\n\n\n========================\n USUARIOS CARGADOS\n========================\n");
                for (i=0; i<tamanio; i++)
                {
                    if (users[i].estado==1)
                    {
                        showOneUser(users[i]);
                    }
                }
 }
/** \brief Muestra un solo usuario, complementaria al listado
 *
 * \param Estructura de personas
 * \return Void
 *
 */
  void showOneUser (ePersona usuarios)
{
 printf("\nNombre: %s \t Edad:%d \t Dni:%d \t Estado:%d"  , usuarios.nombre , usuarios.edad, usuarios.dni, usuarios.estado);
}


/** \brief Ordena por burbujeo alfabeticamente
 *
 * \param Vector Estructura de personas
 * \param tamanio del array de personas
 * \param Flag de estado de carga de usuaarios
 * \return
 *
 */
void mostrarOrdenadoPorNombre (ePersona usuarios [], int CantUsuario, int flag)
{
    int i;
    int j;
    ePersona aux;
    if (flag ==1)
    {
         printf(" \n \n---El orden de los usuarios por nombre---\n");
       for (i=0; i<CantUsuario-1;i++)
        {
           for (j=i+1; j<CantUsuario;j++)
            {
                if (strncmp( strlwr(usuarios[j].nombre) , strlwr(usuarios[i].nombre), 50)<0)
                {
                   aux=usuarios[i];
                   usuarios[i]=usuarios[j];
                   usuarios[j]=aux;
                }
            }
        }
        listadoDeUsuarios(usuarios, CantUsuario);
    }
    else
    {
         printf("\n\n\n======================\n NO HAY USUARIOS CARGADOS\n======================\n");
    }
}

/** \brief Grafico de que muestra la edad de los usuarios
 *
 * \param Vector Estructura de personas
 * \param tamanio del array de personas
 * \return void
 *
 */

void graficos (ePersona personas [], int CantUsuario)
{
    int i;
    int menor18=0;
    int de18a35=0;
    int mas35=0;
    char menor[CantUsuario][2];
    char joven[CantUsuario][2];
    char adulto[CantUsuario][2];
    int contador=0;

  for(i=0; i<CantUsuario; i++)
     {
        strcpy(menor[i] , " ");
        strcpy(joven[i] , " ");
        strcpy(adulto[i] , " ");
     }

    for(i=0; i<CantUsuario; i++)
    {
        if (personas [i].edad <=18 && personas [i].edad >0 &&personas [i].estado ==1 )
        {
            menor18++;
        }
        else if (personas [i].edad >18&&personas [i].edad <35 &&personas [i].estado ==1 )
                 {
            de18a35++;
        }
        else if (personas [i].edad >35 &&personas [i].estado ==1 )
        {
            mas35++;
        }

    }

    for(i=0; i<menor18; i++)
    {
        if (i==0)
        {
         strcpy(menor[i] , "*");
        }
        else{
         strcpy(menor[i], "*") ;
        }

    }
    for(i=0; i<de18a35; i++)
    {
        if (i==0)
        {
            strcpy(joven[i], "*");
        }
        else
        {
           strcpy(joven[i], "*") ;
        }
    }
    for(i=0; i<mas35; i++)
    {
        if (i==0)
        {
            strcpy(adulto[i], "*");
        }
        else{
           strcpy(adulto[i], "*") ;
        }
    }
   if (menor18 <= de18a35)
   {
     contador = de18a35;
   }
   else if (de18a35<=mas35)
   {
   contador = mas35;
   }
   else
    {
     contador=menor18;
    }
    for(i=contador; i>=0; i--)
    {
      printf(" \n\t%s \t  %s\t %s", menor[i] , joven[i] , adulto[i]);
    }
  printf("\n     <18  18y35 \t>35 \n \n" );
  cleanScreen();

}


/** \LIMPIA LA PANTALLA
 */
void cleanScreen (void)
{
            printf("\n");
            system ("pause");
            system ("cls");
}
