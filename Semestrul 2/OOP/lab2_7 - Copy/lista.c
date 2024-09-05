#include "lista.h"
#include <string.h>
#include <stdlib.h>

Lista createLista() {
    /*
     * Functie care creeaza o lista si o returneaza
     * postconditii: Lista
     */
    Lista lista;
    lista.len = 0;
    lista.capacitate = 2;
    lista.array = (cheltuiala*)malloc(sizeof(cheltuiala) * 2);
    return lista;
}

void destroyLista(Lista* lista) {
    /*
     * Distruge o lista
     * preconditii - lista de tip Lista
     * postconditii -
     */
    for(int i=0; i<lista->len; i++) {
        destroyCheltuiala(&lista->array[i]);
    }
    free(lista->array);
}