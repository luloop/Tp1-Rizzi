
#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED

#define TEXTOSCORTOS 20
#define TEXTOSDESCRIPCION 200
#define TEXTOSLINK 50




typedef struct{
    char titulo[TEXTOSCORTOS];
    char genero[TEXTOSCORTOS];
    int duracion;
    char descripcion[TEXTOSDESCRIPCION];
    float puntaje;
    char linkImagen[TEXTOSLINK];
    int estado;
    int idPelicula;
    char nombreArchivo[TEXTOSCORTOS*2];
    int htmlCreado;

}EMovie;

void indiceUsuarios (EMovie[], int);
char preguntarSiNo ( char texto []);
int agregarPelicula(EMovie [], int );
void mostrarPeliculaIndividual(EMovie peli);

int bajaPelicula(EMovie [], int, int, int );

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
