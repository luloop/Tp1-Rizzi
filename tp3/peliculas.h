
#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED



typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    float puntaje;
    char linkImagen[50];
    int estado;
    int idPelicula;
    char nombreArchivo[42];
    int htmlCreado;

}EMovie;

void indiceUsuarios (EMovie[], int);
char preguntarSiNo ( char texto []);
int agregarPelicula(EMovie [], int );
void mostrarPeliculaIndividual(EMovie peli);

int bajaPelicula(EMovie [], int, int );

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
//int borrarPelicula(EMovie movie);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
//void generarPagina(EMovie lista[], char nombre[]);


























#endif // peliculas_H_INCLUDED
