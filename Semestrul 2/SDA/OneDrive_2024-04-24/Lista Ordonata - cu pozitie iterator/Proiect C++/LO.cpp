#include "Iterator.h"
#include "LO.h"

#include <iostream>
using namespace std;

#include <exception>

int LO::aloca() {
    int i = primLiber;
    if(i == -1) {
        redimensionare();
    }
    primLiber = urm[i];
    urm[i] = -1;
    pre[i] = -1;
    return i;
}

void LO::dealoca(int poz) {
    urm[poz] = primLiber;
    primLiber = poz;
}

void LO::redimensionare() {
    int noua_capacitate = 2 * CAPACITATE;
    TElement* noi_elemente = new TElement[noua_capacitate];
    int* noi_urm = new int[noua_capacitate];
    int* noi_pre = new int[noua_capacitate];

    for (int i = 0; i < CAPACITATE; i++) {
        noi_elemente[i] = elemente[i];
        noi_urm[i] = urm[i];
        noi_pre[i] = pre[i];
    }

    for (int i = CAPACITATE; i < noua_capacitate - 1; i++) {
        noi_urm[i] = i + 1;
    }
    noi_urm[noua_capacitate - 1] = -1;

    delete[] elemente;
    delete[] urm;
    delete[] pre;

    elemente = noi_elemente;
    urm = noi_urm;
    pre = noi_pre;

    CAPACITATE = noua_capacitate;
}

LO::LO(Relatie r) : rel(r) {
    this->CAPACITATE = 10;
    this->elemente = new TElement[CAPACITATE];
    urm = new int[CAPACITATE];
    pre = new int[CAPACITATE];

    for(int i=0;i<CAPACITATE - 1;i++) {
        urm[i] = i+1;
        pre[i] = -1;
    }
    urm[CAPACITATE - 1] = -1;
    pre[CAPACITATE - 1] = -1;
    this->primLiber = 0;
    this->primu = -1;
    this->ultim = -1;
    this->dimensiune = 0;
}

// returnare dimensiune
int LO::dim() const {
	return this->dimensiune;
}

// verifica daca LO e vida
bool LO::vida() const {
    return this->dimensiune == 0;
}

// prima pozitie din LO
Iterator LO::prim() const {
	Iterator it(*this);
    if(primu != -1) {
        it.curent = primu;
    }
	return it;
}

// returnare element de pe pozitia curenta
//arunca exceptie daca poz nu e valid
TElement LO::element(Iterator it) const {
    int poz = it.curent;
	if(poz < 0 || poz >= CAPACITATE) {
        throw std::runtime_error("Pozitia nu este valida!");
    }
	return elemente[poz];
}

//sterge element de pe o pozitie poz si returneaza elementul sters
//dupa stergere poz e pozitionat pe elementul de dupa cel sters
//arunca exceptie daca poz nu e valid
TElement LO::sterge(Iterator& it) {
    int poz = it.curent;
    if(!it.valid()) {
        throw std::runtime_error("Iterator invalid!");
    }
    TElement element_sters = elemente[poz];
    if(pre[poz] != -1) {
        urm[pre[poz]] = urm[poz];
    } else {
        primu = urm[poz];
    }
    if(urm[poz] != -1) {
        pre[urm[poz]] = pre[poz];
    } else {
        ultim = pre[poz];
    }
    urm[poz] = primLiber;
    primLiber = poz;
    dimensiune--;
	return element_sters;
}


// cauta element si returneaza prima pozitie pe care apare (sau iterator invalid)
Iterator LO::cauta(TElement e) const{
	int current = primu;
    while (current != -1) {
        if(elemente[current] == e) {
            return Iterator(*this, current);
        }
        current = urm[current];
    }
	return Iterator(*this, -1);
}

// adaugare element in LO
void LO::adauga(TElement e) {
	int i = aloca();
    elemente[i] = e;

    if(dimensiune == 0) {
        primu = i;
        ultim = i;
    } else {
        int current = primu;
        int prev = -1;
        while(current != -1 && rel(elemente[current], e)) {
            prev = current;
            current = urm[current];
        }
        if(prev == -1) {
            urm[i] = primu;
            pre[primu] = i;
            primu = i;
        } else {
            urm[i] = current;
            urm[prev] = i;
            if(current != -1) {
                pre[current] = i;
            } else {
                ultim = i;
            }
        }
    }
    dimensiune++;
}


//destructor
LO::~LO() {
    delete[] elemente;
    delete[] urm;
    delete[] pre;
}
