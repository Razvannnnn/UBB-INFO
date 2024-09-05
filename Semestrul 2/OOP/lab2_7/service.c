#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "service.h"
#include "lista.h"
#include "cheltuieli.h"
#include "repo.h"
#include "valid.h"

/*
 * Functie ce valideaza o cheltuiala si o adauga in lista o cheltuieli
 */
int srv_adaugare(Lista* lista, cheltuiala cheltuiala) {
    if(validare_cheltuiala(cheltuiala) == 1) {
        adaugare(cheltuiala, lista);
        return 1;
    }
    else return 0;
}

/*
 * Functie ce sterge din lista o cheltuiala
 */
int srv_stergere(Lista* lista, int nr) {
    stergere(nr, lista);
    return 1;
}

/*
 * Functie ce modifica o cheltuiala si o valideaza
 */
int srv_modificare(Lista* lista, cheltuiala cheltuiala) {
    if(validare_cheltuiala(cheltuiala) == 1) {
        modificare(cheltuiala, lista);
        return 1;
    }
    return 0;
}

// TESTE

void test_srv_adaugare() {
    Lista lista_ad = createLista();
    cheltuiala c = createCheltuiala();
    c.nr = 250;
    c.suma = 300;
    strcpy(c.tip, "incalzire");

    assert(lista_ad.len == 0);
    srv_adaugare(&lista_ad, c);
    assert(lista_ad.len == 1);
    cheltuiala c1 = createCheltuiala();
    c1.nr = 30;
    c1.suma = -100;
    strcpy(c1.tip, "apa");
    assert(srv_adaugare(&lista_ad, c1) == 0);

    destroyCheltuiala(&c1);
    destroyLista(&lista_ad);
}

void test_srv_stergere() {
    Lista lista_st = createLista();
    cheltuiala c = createCheltuiala();
    c.nr = 250;
    c.suma = 300;
    strcpy(c.tip, "incalzire");

    assert(lista_st.len == 0);
    srv_adaugare(&lista_st, c);
    assert(lista_st.len == 1);
    srv_stergere(&lista_st, 250);
    assert(lista_st.len == 0);

    destroyLista(&lista_st);
}

void test_srv_modificare() {
    Lista lista_mod = createLista();
    cheltuiala c = createCheltuiala();
    c.nr = 250;
    c.suma = 300;
    strcpy(c.tip, "incalzire");

    cheltuiala c1 = createCheltuiala();
    c1.nr = 250;
    c1.suma = 400;
    strcpy(c1.tip, "apa");

    cheltuiala c2 = createCheltuiala();
    c2.nr = 250;
    c2.suma = -100;
    strcpy(c2.tip, "apa");

    assert(lista_mod.len == 0);
    srv_adaugare(&lista_mod, c);
    assert(lista_mod.len == 1);
    srv_modificare(&lista_mod, c1);
    assert(lista_mod.len == 1);
    assert(lista_mod.array[0].nr == 250 && lista_mod.array[0].suma == 400 && strcmp(lista_mod.array[0].tip, "apa") == 0);
    assert(srv_modificare(&lista_mod, c2) == 0);

    destroyCheltuiala(&c1);
    destroyCheltuiala(&c2);
    destroyLista(&lista_mod);
}