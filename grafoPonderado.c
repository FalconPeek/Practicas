//RESOLUCION DEL PUNTO 1 DEL TEMA 1 PARCIAL 2 AED2

#include <stdio.h>
#include <stdbool.h>

//Variables Globales
#define MAX_STG 25
typedef char tString[MAX_STG];

//Grafo.h
#define N 90

typedef int tVertice;

typedef struct{
    float traficoPromedio;
    int distanciaMts;
}tPeso;

typedef struct{
    tVertice origen;
    tVertice destino;
    tPeso peso;
}tArista;

typedef bool tConjuntoVertices[N];
typedef tPeso tConjuntoAristas[N][N];

typedef struct{
    tConjuntoVertices vertices;
    tConjuntoAristas aristas;
}tGrafoPonderado;


//Prototipos
void runApp();
//Prototipos para grafos ----------------------------------
void inicializarGrafo(tGrafoPonderado* );
void agregarVertice( tGrafoPonderado*, tVertice ); 
void agregarArista( tGrafoPonderado*, tArista ); 
void borrarVertice( tGrafoPonderado*, tVertice ); 
void borrarArista( tGrafoPonderado*, tArista ); 

int maximoVertice( tGrafoPonderado );
void visualizarMatrizAdyacencia( tGrafoPonderado );
void visualizarMatrizPesos( tGrafoPonderado );
bool existeVertice( tGrafoPonderado, tVertice );
bool existeArista( tGrafoPonderado, tArista );

void pruebaGrafos();
//Fin prototipos para grafo-----------------------------

int main(void){
    runApp();
    return 0;
}


//Funciones ------------------------------------------------

bool existeVertice( tGrafoPonderado grafoP, tVertice pVertice){
    return grafoP.vertices[pVertice] == true;
}


bool existeArista( tGrafoPonderado grafoP, tArista pArista){
    return ((grafoP.aristas[pArista.origen][pArista.destino]).traficoPromedio != -1 && (grafoP.aristas[pArista.origen][pArista.destino]).distanciaMts != -1)
    && existeVertice(grafoP, pArista.origen)
    && existeVertice(grafoP, pArista.destino);
}

void inicializarGrafo( tGrafoPonderado* grafoP){
    int x, y;

    for(x=0; x<N; x++){
        grafoP->vertices[x] = false;
        for(y=0; y<N; y++){
            grafoP->aristas[x][y].distanciaMts = -1;
            grafoP->aristas[x][y].traficoPromedio = -1.0;
        }
    }
    printf("\nGrafo inicializado correctamente.\n");
}


void agregarVertice( tGrafoPonderado* grafoP, tVertice vertice){
    grafoP->vertices[vertice] = true;
    printf("\nVértice %d agregado correctamente.\n", vertice);
}


void agregarArista( tGrafoPonderado* grafoP, tArista pArista){
    bool aristaValida = existeVertice(*grafoP, pArista.origen) && existeVertice(*grafoP, pArista.destino);
    if(aristaValida){
        grafoP->aristas[pArista.origen][pArista.destino] = pArista.peso;
        printf("\nArista Activada!\n");
    } else {
        printf("\nArista no valida | Alguno de los nodos no esta activo\n");
    }

}


void borrarVertice( tGrafoPonderado* grafoP, tVertice pVertice){
    grafoP->vertices[pVertice] = false;

    printf("\nVertice desactivado: %d\n", pVertice);
}


void borrarArista( tGrafoPonderado* grafoP, tArista pArista){
    if(existeArista(*grafoP, pArista)){
        tPeso pesoInicial = {.distanciaMts = -1, .traficoPromedio = -1};
        grafoP->aristas[pArista.origen][pArista.destino] = pesoInicial;
    } else {
        printf("\nNo existe la arista a borrar\n");
    }
} 


int maximoVertice(tGrafoPonderado grafoP){ //Devuelve el indice del verticeMaximo.
    int x;
    int max = 0;
    for(x=1; x<N; x++){
        if(grafoP.vertices[x] == true){
            max = x;
        }
    }
    return max;
}


void visualizarMatrizAdyacencia(tGrafoPonderado grafoP){
    int x, y;
    int maxVertice = maximoVertice(grafoP);
    printf("\n*** MATRIZ DE ADYACENCIA ***\n");
    for(x=0;x<=maxVertice;x++){
        for(y=0;y<=maxVertice;y++){
            tArista aristaActual = { .origen = x, .destino = y};
          //  aristaActual.origen = x;
         //   aristaActual.destino = y;
            if(existeArista(grafoP, aristaActual)){
                printf("1\t");
            } else {
                printf("0\t");
            }
         }
         printf("\n");
    }
}


void visualizarMatrizPesos(tGrafoPonderado grafoP){
    int x, y;
    int maxVertice = maximoVertice(grafoP);
    printf("\n*** MATRIZ DE PESOS ***\n");
    printf("M = Distancia en metros\nT = Trafico promedio por minuto");
    for(x=0;x<=maxVertice;x++){
        for(y=0;y<=maxVertice;y++){
            tPeso pesoActual = grafoP.aristas[x][y];
            tArista aristaActual = { .origen = x, .destino = y, .peso = pesoActual};
            if(existeArista(grafoP, aristaActual)){
                printf("(M:%d , T:%f)\t", aristaActual.peso.distanciaMts, aristaActual.peso.traficoPromedio);
            } else {
                printf("(S/C , S/C)");
            }
        }
        printf("\n");
    }
}

void pruebaGrafos(){
    printf("\n\n-- Iniciando prueba de Grafos --\n\n");
    tGrafoPonderado grafoP;
    inicializarGrafo(&grafoP);

    agregarVertice(&grafoP, 1);
    agregarVertice(&grafoP, 2);
    agregarVertice(&grafoP, 3);

    tPeso peso = { .distanciaMts = 50, .traficoPromedio = 12.5};
    tArista arista = { .origen = 2, .destino = 1, .peso = peso};
    agregarArista(&grafoP, arista);

    peso.distanciaMts = 20;
    peso.traficoPromedio = 22.3;
    arista.origen = 1;
    arista.destino = 3;
    arista.peso = peso;
    agregarArista(&grafoP, arista);

    visualizarMatrizAdyacencia(grafoP);

    visualizarMatrizPesos(grafoP);

    borrarVertice(&grafoP, 2);

    visualizarMatrizPesos(grafoP);

    printf("\n-- Prueba de Grafos Finalizada con Exito --\n");
}

void runApp() {
    printf("Iniciando app.....\n\n");
    printf("Grafo Ponderado - Puntos de interes Ciudad\n");

    //Prueba de grafos
    pruebaGrafos();
}