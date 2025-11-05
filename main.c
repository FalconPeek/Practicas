#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

#include "GrabarArchivo.h"
#include "LeerArchivo.h"

int main(){
	inicializarG();
	procesarG();
	finalizarG();

    inicializarL();
    procesarL();
    finalizarL();

	return 0;
}
