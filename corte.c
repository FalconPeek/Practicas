/* 	Este programa realiza el corte sobre una archivo de personajes, 
	ordenado seg�n el campo de control correspondiente al universo */
	 
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define TITULO1 "\n*** INFORME DE PERSONAJES ***\n"

/* Tipos de datos personalizados */ 

typedef char tString[20];

typedef struct {	    
    short codUniverso; 
	tString nombrePersonaje;
	tString nombreTerrestre;
	char genero;
	char codRol;	
	short cantPeliculasAparicion;   
}tPersonaje;	 

/* Declaraci�n de prototipos */
void inicializacion();
void procesoCorte();
void finalizacion();

void principioCorte();
void unUniverso(); // procesar un universo
void finCorte();

/* Declaraci�n de variables */
FILE * personajes;
tPersonaje personaje, personajeAnterior;

int totalHeroes, totalVillanos, subtotalHeroes, subtotalVillanos;

/* Bloque principal */
int main() {		
	inicializacion();	
	procesoCorte();		
	finalizacion();
}

/* Implementaci�n de funciones */

void inicializacion() {
	/*	Actividades al inicio del programa:	
		1. Abrir archivo en modo lectura
		2. Leer el primer registro
		3. Guardar campo de control anterior, en este caso el registro completo anterior
		4. Inicializar contadores/acumuladores generales/totales 
		5. Escribir titulos */
	personajes = fopen("Personajes.dat", "rb");	
	
	if(personajes != NULL ) {
		fread(&personaje, sizeof(tPersonaje), 1, personajes);	
	} else {
		printf("No se encuentra el archivo!\n");
		exit(EXIT_FAILURE);
	}

	personajeAnterior = personaje;
	totalHeroes = 0;
	totalVillanos = 0;
	
	printf("%s", TITULO1);
	
	printf("UNIVERSO\t | PERSONAJE\n");
}

void procesoCorte() {
	/* Recorrer el archivo hasta el final (feof) */
	while (!feof(personajes)) { 
	
		principioCorte(); 
		
		/* Con este while trabajamos con cada grupo  */
	    while(!feof(personajes) && personaje.codUniverso == personajeAnterior.codUniverso) { 
			unUniverso();
			fread(&personaje, sizeof(tPersonaje), 1, personajes);				
		} 
		/* Cuando termina este while significa que termin� un grupo entonces realizamos las actividades del corte */
		
		finCorte();
	}
	/* Cuando termina este while significa que se termin� de recorrer el archivo */
}

void principioCorte() {
	/* 	Actividades antes de recorrer los grupos:
			1. Inicializar los contadores/acumuladores parciales */			
	subtotalHeroes = 0;
	subtotalVillanos = 0;	
}

void unUniverso() {
	/* Actividades por grupo
			1. Actualizar contadores/acumuladores parciales
			2. Mostrar la l�nea del detalle en el caso que sea necesario
			3. Buscar el mayor/menor del grupo (parcial) en el caso que sea necesario */
	printf("%s\t | %s\n", 
			personaje.codUniverso == 1 ? "DC" : "MARVEL", 
			personaje.nombrePersonaje);
			
	if(personaje.codRol == 'H') {
		subtotalHeroes++;
	}else {
		subtotalVillanos++;
	}					
}

void finCorte(){      		
	/* 	Actividades por fin de corte de control
			1. Mostrar subtotales (l�nea de totales del grupo en el caso que el ejercicio lo solicite)
			2. Guardar la clave anterior(campo de control), en este caso codCarrera 		
			3. Calcular promedios/porcentajes parciales en el caso que el problema lo requiera
			4. Actualizar contadores/acumuladores generales			
			5. Buscar el mayor/menor (general) en el caso que el problema lo requiera */ 		
	printf("---------------------------------------------\n");
	printf("%s | Villanos: %d\tHeroes: %d\n", personajeAnterior.codUniverso == 1 ? "DC" : "MARVEL", subtotalVillanos, subtotalHeroes);
	printf("---------------------------------------------\n");
	
	totalHeroes = totalHeroes + subtotalHeroes; // totalHeroes += subtotalHeroes
	totalVillanos = totalVillanos + subtotalVillanos;
	
	personajeAnterior = personaje;
}

void finalizacion(){
	/* 	Actividades al finalizar
			1. Mostrar totales
			2. Calcular promedios/porcentajes generales en el caso que el problema lo requiera
			3. Cerrar el archivo */

	printf("Villanos: %d\tHeroes: %d\n", totalVillanos, totalHeroes);
	printf("---------------------------------------------\n");
	
	fclose(personajes);
}
