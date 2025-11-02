#include <stdio.h>
#include "commons.h"

// Declaración de la funciones
void mostrar(Item i);
void pedirDats(Item* i);

//Variables
Item item1 = {.id = 32, .name = "Jeje"};
Item item2;


int main(void){
    pedirDats(&item2);
    mostrar(item1);
    mostrar(item2);
    return 0;
}


void mostrar(Item i){
    printf("ID: %d\n", i.id);
    printf("Name: %s\n", i.name);
}

void pedirDats(Item* i){
    printf("Ingrese ID: ");
    scanf("%d", &i->id);
    fflush(stdin);
    printf("Ingrese Name: ");
    scanf("%s", &i->name);
}