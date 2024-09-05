#ifndef LAB2_7_REPO_H
#define LAB2_7_REPO_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "valid.h"
#include "cheltuieli.h"

//Functie care adauga o cheltuiala in lista
void adaugare(cheltuiala c, Lista* l);

//Functie care sterge o cheltuiala din lista
void stergere(int nr, Lista* l);

//Functie care modifica o cheltuiala din lista
void modificare(cheltuiala c, Lista* l);


//Functie care filtreaza dupa nr apt
Lista filtrare_propr_nr(Lista* lista, int nr);

//Functie care filtreaza dupa sumar cheltuielii
Lista filtrare_propr_suma(Lista* lista, int suma);

//Functie care filtreaza dupa tip cheltuielii
Lista filtrare_propr_tip(Lista* lista, char* tip);


//Functie de sortare a liste in functie de suma sau tip (crescator/descrescator)
Lista sortare(Lista lista, int propr, int ord);
Lista sortare2(Lista lista, int (*compare)(cheltuiala a, cheltuiala b));
int compare(cheltuiala a, cheltuiala b, int propr, int ord);

int sort_cresc(cheltuiala cheltuialaA, cheltuiala cheltuialaB);
int sort_descresc(cheltuiala cheltuialaA, cheltuiala cheltuialaB);

//Functii de testare
void test_adaugare();
void test_stergere();
void test_modificare();
void test_filtrare_propr_nr();
void test_filtrare_propr_suma();
void test_filtrare_propr_tip();
void test_sortare();
void test_compare();
void test_sortare2();

#endif