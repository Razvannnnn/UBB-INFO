#pragma once

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