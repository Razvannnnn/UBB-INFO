#include "Iterator.h"
#include "LO.h"

#include <iostream>
using namespace std;

#include <exception>

LO::LO(Relatie r) {
    dimensiune = 0;
    primR = -1;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        urm[i] = i + 1;
        elem[i] = NULL_TELEMENT;
    }
    urm[MAX_SIZE - 1] = -1;

    primLiber = 0;
}

//Worst case Theta(1), Best case Theta(1), Overall Theta(1)
int LO::aloca() {
    int i = primLiber;
    primLiber = urm[primLiber];
    return i;
}


//Worst case Theta(1), Best case Theta(1), Overall Theta(1)
void LO::dealoca(int i) {
    urm[i] = primLiber;
    primLiber = i;
}


//Worst case Theta(1), Best case Theta(1), Overall Theta(1)
int LO::creeazaNod(TElement e) {
    int i = aloca();
    if (i != -1)
    {
        this->elem[i] = e;
        urm[i] = -1;
    }
    return i;
}


// returnare dimensiune
int LO::dim() const {
    return dimensiune;
}

// verifica daca LO e vida
bool LO::vida() const {
	if(dimensiune == 0)
        return true;
    return false;
}

// prima pozitie din LO
Iterator LO::prim() const {
    return Iterator(*this);
}

// returnare element de pe pozitia curenta
//arunca exceptie daca poz nu e valid
TElement LO::element(Iterator poz) const {
    return poz.element();
}

//sterge element de pe o pozitie poz si returneaza elementul sters
//dupa stergere poz e pozitionat pe elementul de dupa cel sters
//arunca exceptie daca poz nu e valid
TElement LO::sterge(Iterator& poz) {
    if (!poz.valid())
        throw std::exception();

    Iterator p(*this);
    int poz_ant = p.current;
    TElement toDel = poz.element();

    while (p.current != poz.current)
    {
        poz_ant = p.current;
        p.urmator();
    }

    urm[poz_ant] = urm[poz.current];
    int toDealoc = poz.current;
    poz.current = urm[poz.current];
    dealoca(toDealoc);

    dimensiune--;

    return toDel;
}


// cauta element si returneaza prima pozitie pe care apare (sau iterator invalid)
Iterator LO::cauta(TElement e) const{
    Iterator p(*this);
    while (p.valid())
    {
        int x = p.element();
        if (p.element() == e)
            break;
        else
            p.urmator();
    }
    return p;
}

// adaugare element in LO
void LO::adauga(TElement e) {
    Iterator poz(*this);

    if (!poz.valid())
        throw std::exception();

    int i = creeazaNod(e);

    if (dimensiune == 0) {
        if (i != -1)
        {
            urm[i] = primR;
            primR = i;
            dimensiune++;
        }
    }
    if(i != -1)
    {
        Iterator p(*this);
        int poz_ant = p.current;

        while (p.current != poz.current)
        {
            poz_ant = p.current;
            p.urmator();
        }

        urm[poz_ant] = i;
        urm[i] = p.current;
        poz.current = i;
        dimensiune++;


    }
}


//destructor
LO::~LO() {
	/* de adaugat */
}
