#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define TITULO1 "\n*** INFORME DE PERSONAJES ***\n"

// Tipos de datos Personalizados

typedef char tString[20];
 
typedef struct {
    char fecha[9]; //AAAAMMDD 8 carateres + '\0'
    int codigoCliente;
    float importePedido;
} tPedido;

//Declaracion de prototipos
void inicializacion();
void procesoCorte();
void finalizacion();

void principioCorte();
void unUniverso();
void finCorte();

// Declaracion de variables
FILE * pedidos;
tPedido pedido, pedidoAnterior;

int totalDiasRegistrados, totalGralPedidos;

// MAIN FUNCTION
int main(void){
    inicializacion();
    procesoCorte();
    finalizacion();
}

void inicializacion(){
    pedidos = fopen("Pedidos.dat", "rb");

    if(pedidos != NULL){
        fread(&pedidos, sizeof(tPedidos), 1, pedidos);
    } else {
        printf("\nNo se encuentra el archivo!\n")
        exit(EXIT_FAILURE);
    }

    pedidoAnterior = pedido;
    totalDiasRegistrados = 0;
    totalGralPedidos = 0;

    printf("%s", TITULO1)
    tota
}