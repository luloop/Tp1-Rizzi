#include <stdio.h>
#include <stdlib.h>

void funcionBienvenida (char* nombre); // puede estar vacio, recibe por defecto un entero // CONSISTENTE 0
void funcionDespedida (char* nombre);

void funcionDelegado ( void (*nombreDeLaFuncion)  (char*)  );

int main()
{
    void (*f1)(char*);

    /*f1=funcion1; //devuelve la direccion de memoria de la funcion // CONSISTENTE

    f1("hola hola");*/

    funcionDelegado(funcionBienvenida);
    printf("\n\n\n");
    funcionDelegado(funcionDespedida);

    printf("\n");printf("\n");

    return 0;
}

////////////////////////////////////////////////////////////////////////////

void funcionDelegado ( void (*nombreDeLaFuncion)  (char* texto)  )
{
    nombreDeLaFuncion("lucila");
}

/////////////////////////////////////////////////////////////////////////////

void funcionBienvenida(char * nombre) // CONSISTENTE
{
    printf("Bienvenido %s", nombre);
    return 0;
}


void funcionDespedida(char * nombre) // CONSISTENTE
{
    printf("Chau %s", nombre);
    return 0;
}


