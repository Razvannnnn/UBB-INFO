#include "TestScurt.h"

#include <assert.h>
#include <exception>


#include "Lista.h"
#include "IteratorLP.h"
#include <iostream>



using namespace std;

void testAll() {
  /*  Lista lista = Lista();
    lista.adaugaInceput(5);
    lista.adaugaInceput(3);
    lista.adaugaInceput(2);
    lista.adaugaInceput(22);
    lista.adaugaInceput(20);
    lista.view();
    lista.adaugaSfarsit(12);
    lista.adaugaInceput(23);
    lista.adaugaSfarsit(15);
    lista.view();

    IteratorLP lp = lista.cauta(2);
    lista.modifica(lp, 123);
    lista.view();
    lista.adauga(lp, 321);
    lista.adauga(lp, 121);
    lista.adauga(lp, 381);
    lista.view();

    lista.sterge(lp);
    lista.view();

    lista.sterge(lp);
    lista.view();*/


    Lista lista = Lista();
    assert(lista.dim() == 0);
    assert(lista.vida());

    lista.adaugaSfarsit(1);
    assert(lista.dim() == 1);
    assert(!lista.vida());

    IteratorLP it = lista.cauta(1);
    assert(it.valid());
    assert(it.element() == 1);
    it.urmator();
    assert(!it.valid());
    it.prim();
    assert(it.valid());
    assert(it.element() == 1);

    assert(lista.sterge(it) == 1);
    assert(lista.dim() == 0);
    assert(lista.vida());

    lista.adaugaInceput(1);
    assert(lista.dim() == 1);
    assert(!lista.vida());
}

