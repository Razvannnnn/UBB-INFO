#include "Iterator.h"
#include "LO.h"

#include <iostream>
using namespace std;

#include <exception>

LO::LO(Relatie r, int capacitateInitiala) : rel(r), size(0), capacitate(capacitateInitiala) {
    elemente = new TElement[capacitate];
}

void LO::resize() {
    capacitate *= 2;
    TElement* newElements = new TElement[capacitate];
    std::copy(elemente, elemente + size, newElements);
    delete[] elemente;
    elemente = newElements;
}

/*
 * Returneaza dimensiunea listei
 * Complexitate: 0(1)
 */
int LO::dim() const {
	return size;
}

/*
 * Verifica daca LO este vida
 * Complexitate: 0(1)
 */
bool LO::vida() const {
    return size == 0;
}

/*
 * Returneaza prima pozitie din LO
 * Complexitate: 0(1)
 */
Iterator LO::prim() const {
	Iterator it(*this);
    it.indexCurent = 0;
	return it;
}

/*
 * Returneaza elementul de pe pozitia curenta
 * Arunca exceptie daca pozitia nu este valida
 * Complexitate: 0(1)
 */
TElement LO::element(Iterator poz) const {
	if(!poz.valid()) {
        throw std::out_of_range("Pozitie invalida a iteratorului");
    }
    return elemente[poz.indexCurent];
}

/*
 * Sterge elementul de pe o pozitie poz si returneaza elementul sters
 * Dupa stergere poz e pozitionat pe elementul de dupa cel sters
 * Arunca excptie daca poz nu e valid
 * caz favorabil : Teta(1)
 * caz defavorabil : Teta(n)
 * caz mediu : Teta(n)
 * overall case : 0(n)
 */
TElement LO::sterge(Iterator& poz) {
	if(!poz.valid()) {
        throw std::out_of_range("Nu se poate sterge, iterator invalid!");
    }

    int indexSters = poz.indexCurent;
    TElement valoareSters = elemente[indexSters];

    for(int i=indexSters;i<size - 1;i++) {
        elemente[i] = elemente[i+1];
    }
    size--;

    if(indexSters >= size) {
        poz.indexCurent = -1;
    } else {
        poz.indexCurent = indexSters;
    }

    return valoareSters;
}


/*
 * Cauta element si returneaza prima pozitie pe care apare (sau iterator invalid)
 * caz favorabil : Teta(1)
 * caz defavorabil : Teta(n)
 * caz mediu : Teta(n)
 * overall case : 0(n)
 */
Iterator LO::cauta(TElement e) const{
    for(int i=0;i<size;i++) {
        if(elemente[i] == e) {
            Iterator it(*this);
            it.indexCurent = i;
            return it;
        }
    }

    Iterator it(*this);
    it.indexCurent = -1;
    return it;
}

/*
 * Adauga element in LO
 * caz favorabil : Teta(1)
 * caz defavorabil : Teta(n)
 * caz mediu : Teta(n)
 * overall case : 0(n)
 */
void LO::adauga(TElement e) {
	if(size == capacitate) {
        resize();
    }

    int i=0;
    while(i<size && rel(elemente[i], e)) {
        i++;
    }

    for(int j=size;j>i;j--) {
        elemente[j] = elemente[j-1];
    }
    elemente[i] = e;
    size++;
}


/*
 * Destructorul
 * Elibereaza memoria
 * Complexitate: 0(n)
 */
LO::~LO() {
    delete[] elemente;
}
