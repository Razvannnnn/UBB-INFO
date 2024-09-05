#include "Iterator.h"
#include "LO.h"

#include <iostream>
using namespace std;

#include <exception>

LO::LO(Relatie r) : rel(r), primu(-1), ultim(-1), primLiber(0), dimensiune(0){
	for(int i=0;i<capacitate-1;i++) {
        urm[i]=i+1;
        pre[i]=-1;
    }
    urm[capacitate-1] = -1;
    pre[capacitate-1] = -1;
}

// Returneaza o pozitie libera
int LO::aloca() {
    if (primLiber == -1) {
        throw std::runtime_error("Nu mai exista spatiu liber!");
    }
    int pos = primLiber;
    primLiber = urm[primLiber];
    return pos;
}

// Aloca spatiu pentru o pozitie
void LO::dealoca(int poz) {
    urm[poz] = primLiber;
    primLiber = poz;
}

// Creaza un nou nod pentru un element
int LO::creeazaNod(TElement e) {
    int pos = aloca();
    if(pos != -1) {
        this->elemente[pos] = e;
        urm[pos] = -1;
        pre[pos] = -1;
    }
    return pos;
}

// returnare dimensiune
int LO::dim() const {
    int current = primu;
    int dimensiune_nr = 0;
    while(current != -1){
        dimensiune_nr++;
        current = urm[current];
    }
    return dimensiune_nr;
}

// verifica daca LO e vida
bool LO::vida() const {
    if(primu == -1) return true;
    return false;
}

// prima pozitie din LO
Iterator LO::prim() const {
	return Iterator(*this);
}

// returnare element de pe pozitia curenta
//arunca exceptie daca poz nu e valid
TElement LO::element(Iterator poz) const {
	if(!poz.valid()) {
        throw std::runtime_error("Pozitie invalida la element");
    }
	return elemente[poz.current];
}

//sterge element de pe o pozitie poz si returneaza elementul sters
//dupa stergere poz e pozitionat pe elementul de dupa cel sters
//arunca exceptie daca poz nu e valid
TElement LO::sterge(Iterator& poz) {
    if(!poz.valid()) {
        throw std::runtime_error("Pozitie invalida la stergere");
    }

    int Sters = poz.current;
    TElement elementSters = elemente[Sters];

    if(pre[Sters] == -1) {
        primu = urm[Sters];
    } else {
        urm[pre[Sters]] = urm[Sters];
    }

    if(urm[Sters] == -1) {
        ultim = pre[Sters];
    } else {
        pre[urm[Sters]] = pre[Sters];
    }
    dealoca(Sters);
    poz.current = urm[Sters];
    dimensiune--;
	return elementSters;
}


// cauta element si returneaza prima pozitie pe care apare (sau iterator invalid)
Iterator LO::cauta(TElement e) const{
	int current = primu;
    while (current != 1) {
        if(elemente[current] == e) {
            Iterator it(*this);
            it.current = current;
            return it;
        }
        current = urm[current];
    }
    Iterator it(*this);
    it.current = -1;
	return it;
}

// adaugare element in LO
void LO::adauga(TElement e) {
	int newPoz = creeazaNod(e);
    if(primu == -1) {
        primu = newPoz;
        ultim = newPoz;
    } else {
        int current = primu;
        int prev = -1;

        while(current != -1 && !rel(e, elemente[current])) {
            prev = current;
            current = urm[current];
        }

        if(prev == -1) {
            urm[newPoz] = primu;
            pre[newPoz] = newPoz;
            primu = newPoz;
        } else if(current == -1) {
            urm[prev] = newPoz;
            pre[newPoz] = prev;
            ultim = newPoz;
        } else {
            urm[prev] = newPoz;
            pre[current] = newPoz;
            urm[newPoz] = current;
            pre[newPoz] = prev;
        }
    }

    dimensiune++;
}


//destructor
LO::~LO() {
    int current = primu;
    while(current != -1){
        int urmator = urm[current];
        dealoca(current);
        current = urmator;
    }
}
