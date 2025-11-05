#include <stdio.h>
#include <stdbool.h>

/*
// Struct para Inventario.dat
typedef struct {
    char fecha[9]; //fecha en formato AAAAMMDD (8 caracteres + '\0')
    int entrantes; // Cantidad de artículos entrantes
    int salientes; // Cantidad de artículos salientes
} Movimiento;

// Struct para Pedidos.dat
typedef struct {
    char fecha[9]; //fecha en formato AAAAMMDD (8 caracteres + '\0')
    int codigoCliente; // Código del cliente
    float importePedido; // Importe del pedido en pesos
} Pedido;
*/
//Grafo Ponderado - Puntos de interes Ciudad

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

//Declaracion de funciones del Grafo Ciudad

void inicializarGrafo( tGrafoPonderado* );
void agregarVertice( tGrafoPonderado*, tVertice ); 
void agregarArista( tGrafoPonderado*, tArista ); 
void borrarVertice( tGrafoPonderado*, tVertice ); 
void borrarArista( tGrafoPonderado*, tArista ); 

int maximoVertice( tGrafoPonderado );
void visualizarMatrizAdyacencia( tGrafoPonderado );
void visualizarMatrizPesos( tGrafoPonderado );
bool existeVertice( tGrafoPonderado, tVertice );
bool existeArista( tGrafoPonderado, tArista );