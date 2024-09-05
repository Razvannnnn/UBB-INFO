#ifndef LAB2_4_OOP_REPOSITORY_H
#define LAB2_4_OOP_REPOSITORY_H

#include "domeniu.h"
#include "MyList.h"

MyList* creazaLista();
 /**
 * functia initializeaza lista de oferte
 * */

void distrugeLista(MyList* listaOferte);

void distrugeListaUndo(MyList* undolist);

void adaugare_oferta(MyList* listaOferte, struct Oferta oferta);
/**
 * fuctia adauga oferta in lista
 * */

void stergere_oferta(MyList* listaOferte, int id);
/**
 * functia sterge oferta dupa id
 * */

void modificare_oferta(MyList* listaOferte, int id, struct Oferta oferta);
/**
 * functia modifica oferta dupa id
 * */

void get_all_oferte(MyList* listaOferte, struct Oferta* oferte_copie, int *dim);
/**
 * functia returneaza toate ofertele
 * */

void dimensiune(MyList* listaOferte, int *dim);
/**
 * functia returneaza dimensiunea vectorului
 * */

MyList* copylista(MyList* lista);

#endif //LAB2_4_OOP_REPOSITORY_H
