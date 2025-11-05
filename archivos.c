/* 	Este c�digo contiene el esquema para realizar el corte sobre una archivo determinado,
	ordenado seg�n el campo de control correspondiente al c�digo de carrera */
	
#include <stdio.h> 
#include <string.h>

/* Tipos de datos personalizados */

typedef char tString[40];

typedef struct {	    
    /* completar con los campos seg�n corresponda */
    
}tRegistro;	 

/* Declaraci�n de prototipos */
void inicializacion();
void procesoCorte();
void finalizacion();

void principioCorte();
void unGrupo();
void finCorte();

/* Declaraci�n de variables */

tRegistro registro;

FILE * archivo;

int  codCampoControlAnt;

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
		3. Guardar campo de control anterior
		4. Inicializar contadores/acumuladores generales/totales 
		5. Escribir titulos */
			
	
}

void procesoCorte() {
	/* Recorrer el archivo hasta el final (feof) */
	while (!feof(archivo)) { 
	
		principioCorte(); 
		
		/* Con este while trabajamos con cada grupo  */
	    while(!feof(archivo) && registro.codCampoControl == codCampoControlAnt) { 
			/* 	unGrupo() 
				leer otro registro */					
		} 
		/* Cuando termina este while significa que termin� un grupo entonces realizamos las actividades del corte */
		
		finCorte();
	}
	/* Cuando termina este while significa que se termin� de recorrer el archivo */
}

void principioCorte() {
	/* 	Actividades antes de recorrer los grupos:
			1. Inicializar los contadores/acumuladores parciales */			
			
}

void unGrupo() {
	/* Actividades por grupo
			1. Actualizar contadores/acumuladores parciales
			2. Mostrar la l�nea del detalle en el caso que sea necesario
			3. Buscar el mayor/menor del grupo (parcial) en el caso que sea necesario
			4. Leer otro registro (leerRegistro) */
					
}

void finCorte(){      		
	/* 	Actividades por fin de corte de control
			1. Mostrar subtotales (l�nea de totales del grupo en el caso que el ejercicio lo solicite)
			2. Guardar la clave anterior(campo de control), en este caso codCarrera 		
			3. Calcular promedios/porcentajes parciales en el caso que el problema lo requiera
			4. Actualizar contadores/acumuladores generales			
			5. Buscar el mayor/menor (general) en el caso que el problema lo requiera */ 		
	
	
}

void finalizacion(){
	/* 	Actividades al finalizar
			1. Mostrar totales
			2. Calcular promedios/porcentajes generales en el caso que el problema lo requiera
			3. Cerrar el archivo */
	
}
