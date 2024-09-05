#pragma once

#include "lista.h"
#include "cheltuieli.h"
#include "repo.h"
/*
 * Functie ce valideaza o cheltuiala si o adauga in lista o cheltuieli
 */
int srv_adaugare(Lista* lista, cheltuiala cheltuiala);

/*
 * Functie ce modifica o cheltuiala si o valideaza
 */
int srv_modificare(Lista* lista, cheltuiala cheltuiala);

/*
 * Functie ce sterge din lista o cheltuiala
 */
int srv_stergere(Lista* lista, int nr);

//Functii de comparare
int compareSuma(cheltuiala a, cheltuiala b);
int compareTip(cheltuiala a, cheltuiala b);

//Functie de sortare
Lista srv_sortare(Lista lista, int sortare);


/*
 * Functii de testare
 */
void test_srv_adaugare();
void test_srv_stergere();
void test_srv_modificare();