#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include "tad.h"
#define MAX 25

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
void inicializarG();
void procesarG();
void finalizarG();

/* Declaraci�n de variables globales */
FILE* archPeliculas; 

/* Programa principal*/
/*
int main(){
	inicializarG();
	procesarG();
	finalizarG();
	return 0;
}
*/
/* Implementaci�n de funciones */
void inicializarG(){
	archPeliculas = fopen("Peliculas.dat", "wb");
	
	if(archPeliculas == NULL){
		printf("Error al abrir el archivo\n");
		exit(EXIT_FAILURE);
	}
	
	printf("Archivo abierto en modo escritura\n");
}

void procesarG() {
	// Grabar registros de peliculas en el archivo
	tPelicula pelicula = { 	 
		.idPelicula = 111,
	 	.titulo = "El Padrino",
	 	.codGenero = 'd', // drama 
	 	.duracion = 180 // minutos
	};
	
	fwrite(&pelicula, sizeof(tPelicula), 1, archPeliculas);
	
	pelicula.idPelicula = 222;
	strcpy(pelicula.titulo, "Ricky Stinicky");
	pelicula.codGenero = 'c'; // drama 
	pelicula.duracion = 140; // minutos
	
	fwrite(&pelicula, sizeof(tPelicula), 1, archPeliculas);
	
}

void finalizarG() {
	fclose(archPeliculas);
	printf("Archivo cerrado\n");
}

