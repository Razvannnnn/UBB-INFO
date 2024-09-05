#include "Iterator.h"
#include "LO.h"

#include <iostream>
using namespace std;

#include <exception>

/**
 * Constructor pentru LO cu o relatie data de ordine intre elemente
 * @param r - relatie de ordine intre elemente
 * Preconditii: r - relatie de ordine intre elemente
 * Postconditii: Lista vida
 *
 * Complexitati :
 * Caz defavorabil : Θ(capacitate)
 * Caz mediu : Θ(capacitate)
 * Caz favorabil : Θ(capacitate)
 */
LO::LO(Relatie r) {
    this->capacitate = 10;
    this->dimensiune = 0;
    this->primu = -1;
    this->ultim = -1;
    this->rel = r;
    this->elemente = new TElement[this->capacitate];
    this->urm = new int[this->capacitate];
    this->pre = new int[this->capacitate];

    for(int i=0;i< this->capacitate;i++) {
        this->urm[i] = i + 1;
        this->pre[i] = i - 1;
    }

    this->urm[this->capacitate - 1] = -1;
    this->primLiber = 0;
}

/**
 * Returneaza dimensiunea listei
 * @return dimensiunea listei
 * Complexitati :
 * Caz defavorabil : Θ(1)
 * Caz mediu : Θ(1)
 * Caz favorabil : Θ(1)
 */
int LO::dim() const {
    return this->dimensiune;
}

/**
 * Verifica daca lista e vida
 * @return true daca lista e vida, false altfel
 * Complexitati :
 * Caz defavorabil : Θ(1)
 * Caz mediu : Θ(1)
 * Caz favorabil : Θ(1)
 *
 * Preconditii: -
 * Postconditii: -
 *
 */
bool LO::vida() const {
    return this->dimensiune == 0;
}

/**
 * Returneaza primul element din lista
 * Complexitati :
 * Caz defavorabil : Θ(1)
 * Caz mediu : Θ(1)
 * Caz favorabil : Θ(1)
 *
 * Preconditii: -
 * Postconditii: -
 *
 */
Iterator LO::prim() const {
    return Iterator(*this, this->primu);
}

/**
 * Returneaza elementul de pe pozitia iteratorului
 * Complexitati :
 * Caz defavorabil : Θ(1)
 * Caz mediu : Θ(1)
 * Caz favorabil : Θ(1)
 *
 * Preconditii: i - pozitie valida , TElement - elementul de pe pozitia i
 * Postconditii: -
 *
 */
TElement LO::element(Iterator it) const {
    return it.element();
}

/**
 * Sterge elementul de pe pozitia poz
 * @param poz - pozitia elementului
 * @return elementul sters
 * Complexitati :
 * Caz defavorabil : Θ(n)
 * Caz mediu : Θ(n)
 * Caz favorabil : Θ(1)
 *
 * Preconditii: i - pozitie valida , TElement - elementul de pe pozitia i
 * Postconditii: -
 *
 */
TElement LO::sterge(Iterator& poz) {
    if (!poz.valid())
        throw exception();

    int removePosition = poz.curent;
    TElement oldValue = this->elemente[removePosition];


    if (removePosition == this->primu) {            //cazul in care e pe prima poz
        this->primu = this->urm[this->primu];
    }
    else if(removePosition == this->ultim) {        //cazul in care e pe ultima poz
        this->ultim = this->pre[this->ultim];
    }
    else {
        int prec = -1, current_i = this->primu;

        while (current_i != -1 && current_i != removePosition) {
            prec = current_i;
            current_i = this->urm[current_i];           //gasim pozitia elem ce trb sters
        }
        if (current_i != -1) {                          //daca gasim il stergem
            this->urm[prec] = this->urm[current_i];
        }
    }

    poz.urmator();

    this->pre[this->primLiber] = removePosition;        //actualizam pozlibera, pred si urm
    this->urm[removePosition] = this->primLiber;
    this->primLiber = removePosition;
    this->dimensiune--;

    return oldValue;
}

/**
 * Cauta elementul e in lista
 * @param e - elementul cautat
 * @return prima pozitie pe care apare elementul sau -1
 * Complexitati :
 * Caz defavorabil : Θ(n)
 * Caz mediu : Θ(n)
 * Caz favorabil : Θ(1)
 *
 * Preconditii: e - elementul cautat
 * Postconditii: -
 *
 */
Iterator LO::cauta(TElement e) const{
    int current_i = this->primu;
    while (current_i != -1) {
        if(this->elemente[current_i] == e) {
            Iterator it = Iterator(*this, current_i);
            return it;
        }
        current_i = this->urm[current_i];
    }
    Iterator it = Iterator(*this, -1);
    return it;
}

/**
 * Adauga elementul e in lista
 * @param e - elementul adaugat
 * Complexitati :
 * Caz defavorabil : Θ(n)
 * Caz mediu : Θ(n)
 * Caz favorabil : Θ(1)
 *
 * Preconditii: e - elementul adaugat
 * Postconditii: -
 *
 */
void LO::adauga(TElement e) {
    if(this->dimensiune == this->capacitate)
        redimensionare();

    int new_i = this->primLiber;  //adaugam elementul pe prima pozitie libera
    this->elemente[new_i] = e;
    this->primLiber = urm[this->primLiber];

    int prec = -1;
    int current_i = this->primu;
    while (current_i != -1 && this->rel(this->elemente[current_i], e)) {
        prec = current_i;
        current_i = this->urm[current_i];    //gasim pozitia urmatorului element si predec
    }

    if(prec == -1) {
        this->urm[new_i] = this->primu;      //daca e la inceput de lista
        this->primu = new_i;
        this->ultim = new_i;
    } else {
        this->urm[new_i] = this->urm[prec];     //actualizam urm
        this->urm[prec] = new_i;                //actualizam pred
    }
    this->dimensiune++;
}

/**
 * Redimensioneaza lista dubla inlantuita prin dublarea capacitatii sale.
 * Complexitati:
 * Caz defavorabil: Θ(n)
 * Caz mediu: Θ(n)
 * Caz favorabil: Θ(n)
 *
 * Preconditii: -
 * Postconditii: Lista este redimensionata si memoria veche este eliberata.
 */
void LO::redimensionare() {
    int newCapacitate = this->capacitate * 2;
    auto* newElemente = new TElement[newCapacitate];
    int* newUrm = new int[newCapacitate];
    int* newPre = new int[newCapacitate];

    for(int i=0;i<newCapacitate;i++) {
        newUrm[i] = i + 1;
        newPre[i] = i - 1;
    }
    newUrm[newCapacitate - 1] = -1;

    for(int i=0;i<this->capacitate;i++) {
        newElemente[i] = this->elemente[i];
        newUrm[i] = this->urm[i];
        newPre[i] = this->pre[i];
    }

    delete[] this->elemente;
    delete[] this->urm;
    delete[] this->pre;

    this->elemente = newElemente;
    this->urm = newUrm;
    this->pre = newPre;

    int current_i = this->primu;
    while (this->urm[current_i] != -1) {
        current_i = this->urm[current_i];
    }

    this->urm[current_i] = -1;
    this->primLiber = this->capacitate;
    this->capacitate = newCapacitate;

}

/**
 * Destructor pentru LO
 * Complexitati :
 * Caz defavorabil : Θ(n)
 * Caz mediu : Θ(n)
 * Caz favorabil : Θ(n)
 *
 * Preconditii: -
 * Postconditii: -
 *
 */
LO::~LO() {
    delete[] this->elemente;
    delete[] this->urm;
    delete[] this->pre;
}
