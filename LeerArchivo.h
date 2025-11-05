#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
//#define MAX 25
#define LINEA "-------------------------------------------"

/* Declaraci�n de tipos de datos personalizados */
//typedef char tString[MAX];
/*
typedef struct{
	int idPelicula; 
	tString titulo;
	char codGenero;
	int duracion;	
}tPelicula;
*/
/* Declaraci�n de prototipos de funciones */
void inicializarL();
void procesarL();
void finalizarL();

/* Declaraci�n de variables globales */
FILE* peliculas; 

/* Programa principal*/
/*
int main(){
	inicializarL();
	procesarL();
	finalizarL();
	return 0;
}
*/
/* Implementaci�n de funciones */
void inicializarL(){
	peliculas = fopen("Peliculas.dat", "rb");
	
	if(peliculas == NULL){
		printf("Error al abrir el archivo\n");
		exit(EXIT_FAILURE);
	}
	
	printf("Archivo abierto en modo lectura\n");
}

void procesarL() {
	tPelicula pelicula;
	
	printf("\nPeliculas\n");
	printf("%s\n", LINEA);
	printf("Titulo\tGenero\tDuracion\n");
	printf("%s\n", LINEA);
	
	fread(&pelicula, sizeof(tPelicula), 1, peliculas);
	while(!feof(peliculas)){
		printf("%s\t%s\t%dmins\n",
				pelicula.titulo,
				pelicula.codGenero == 'd' ? "Drama" : "Comedia",
				pelicula.duracion);
				
		fread(&pelicula, sizeof(tPelicula), 1, peliculas);
	}
}

void finalizarL() {
	fclose(peliculas);
	printf("Archivo cerrado\n");
}

