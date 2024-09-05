#ifndef LAB2_7_LISTA_H
#define LAB2_7_LISTA_H

#include "cheltuieli.h"

//Definim structura Lista
typedef struct {
    int len;
    int capacitate;
    cheltuiala *array;
} Lista;

//Creeaza o noua lista
Lista createLista();

//Distruge o lista
void destroyLista(Lista* lista);

#endif