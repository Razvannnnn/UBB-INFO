#include <malloc.h>
#include "MyList.h"
#include "domeniu.h"

MyList* creazaVector(){
    MyList* lista = (MyList*)malloc(sizeof(MyList));
    lista->dimensiune = 0;
    lista->capacitate = 2;
    lista->elems = (Element*) malloc(lista->capacitate * sizeof(Element));
    return lista;
}

void distruge(MyList* lista){
    free(lista->elems);
    free(lista);
}

void adauga(MyList* lista, Element el){
    if (lista->dimensiune == lista->capacitate - 1)
        redimensionareLista(lista);
    lista->elems[lista->dimensiune] = el;
    lista->dimensiune += 1;
}

void redimensionareLista(MyList* lista){
    lista->capacitate *= 2;
    lista->elems = realloc(lista->elems, lista->capacitate * sizeof(Element));
}

void sterge(MyList* lista, int poz){
    for (int i = poz; i < lista->dimensiune - 1; i ++)
        lista->elems[i] = lista->elems[i + 1];
    lista->dimensiune--;
}

Element getOferta(MyList lista, int poz) {
    return lista.elems[poz];
}

Element get(MyList* lista, int poz){
    return lista->elems[poz];
}

int size(MyList *lista){
    return lista->dimensiune;
}

MyList* copyList(MyList* lista){
    MyList* copy = creazaVector();
    for (int i = 0; i < lista->dimensiune; i ++)
        adauga(copy, lista->elems[i]);
    return copy;
}
