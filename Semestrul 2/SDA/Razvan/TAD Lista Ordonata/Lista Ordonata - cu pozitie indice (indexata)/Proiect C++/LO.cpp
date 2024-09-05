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
    prim = -1;
    ultim = -1;

    // Se initializeaza lista spatiului liber - toate elementele sunt libere
    for(int i = 0 ; i < capacitate - 1; i++){
        urm[i] = i + 1;
        pre[i] = -1;
    }
    urm[capacitate - 1] = -1;
    pre[capacitate - 1] = -1;

    // Referinta spre prima pozitie libera din lista
    primLiber = 0;

    // Se initializeaza relatie
    rel = r;

}
/// -----------------------------------------------------------------
/// Metode private

/**
 * Se aloca o pozitie libera
 * @return pozitia libera
 * Complexitati :
 * Caz defavorabil : Θ(1)
 * Caz mediu : Θ(1)
 * Caz favorabil : Θ(1)
 */

int LO::aloca(){
    if(primLiber == -1){
        throw std::runtime_error("Nu mai exista spatiu liber");
        //std::runtime_error("Nu mai exista spatiu liber");
    }
    int poz = primLiber;
    primLiber = urm[primLiber];
    return poz;
}

/**
 * Se dealoca o pozitie
 * @param poz - pozitia de dealocat
 * Complexitati :
 * Caz defavorabil : Θ(1)
 * Caz mediu : Θ(1)
 * Caz favorabil : Θ(1)
 */
void LO::dealoca(int poz){
    urm[poz] = primLiber;
    primLiber = poz;
}

/**
 * Returneaza dimensiunea listei
 * @return dimensiunea listei
 * Complexitati :
 * Caz defavorabil : Θ(n)
 * Caz mediu : Θ(n)
 * Caz favorabil : Θ(n)
 */
int LO::dim() const {
    int curent = prim;
    int dimensiune = 0;
    while(curent != -1){
        dimensiune++;
        curent = urm[curent];
    }
    return dimensiune;
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
    if(prim == -1){
        return true;
    }
	return false;
}

/**
 * Returneaza elementul de pe pozitia i
 * @param i - pozitia elementului
 * @return elementul de pe pozitia i
 * Complexitati :
 * Caz defavorabil : Θ(n)
 * Caz mediu : Θ(n)
 * Caz favorabil : Θ(1)
 *
 * Preconditii: i - pozitie valida , TElement - elementul de pe pozitia i
 * Postconditii: -
 *
 */
TElement LO::element(int i) const{
    if(i < 0 || i >= dim()){
        throw std::runtime_error("Pozitie invalida la element");
    }
    int curent = prim;
    for(int j = 0; j < i; j++){
        curent = urm[curent];
    }
    return elemente[curent];
}

// sterge element de pe o pozitie i si returneaza elementul sters
//arunca exceptie daca i nu e valid
/**
 * Sterge elementul de pe pozitia i
 * @param i - pozitia elementului
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

TElement LO::sterge(int i) {
    if(i < 0 || i >= dim()){
        throw std::runtime_error("Pozitie invalida la stergere");
    }
    int curent = prim;
    for(int j = 0; j < i; j++){
        curent = urm[curent];
    }
    TElement e = elemente[curent];
    if(curent == prim){
        prim = urm[curent];
        pre[prim] = -1;
    } else {
        pre[urm[curent]] = pre[curent];
        urm[pre[curent]] = urm[curent];
    }
    dealoca(curent);
    return e;
}

// cauta element si returneaza prima pozitie pe care apare (sau -1)

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

int LO::cauta(TElement e) const {
    int curent = prim;
    int poz = 0;
    while(curent != -1){
        if(elemente[curent] == e){
            return poz;
        }
        curent = urm[curent];
        poz++;
    }
    return -1;
}

// adaugare element in LO
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

void LO::adauga(TElement e)
{
    int poz = aloca();
    elemente[poz] = e;
    if(prim == -1){
        prim = poz;
        ultim = poz;
        urm[poz] = -1;
        pre[poz] = -1;
    } else {
        int curent = prim;
        int anterior = -1;
        while(curent != -1 && rel(elemente[curent], e)){
            anterior = curent;
            curent = urm[curent];
        }
        if(anterior == -1){
            urm[poz] = prim;
            pre[poz] = -1;
            pre[prim] = poz;
            prim = poz;
        } else {
            urm[poz] = curent;
            pre[poz] = anterior;
            if(curent == -1){
                ultim = poz;
            } else {
                pre[curent] = poz;
            }
            urm[anterior] = poz;
        }
    }

}

// returnare iterator
/**
 * Returneaza un iterator pentru lista
 * @return iterator pentru lista
 * Complexitati :
 * Caz defavorabil : Θ(1)
 * Caz mediu : Θ(1)
 * Caz favorabil : Θ(1)
 *
 * Preconditii: -
 * Postconditii: -
 *
 */

Iterator LO::iterator(){
	return Iterator(*this);
}


//destructor

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
        /* de adaugat */
        int curent = prim;
        while(curent != -1){
            int urmator = urm[curent];
            dealoca(curent);
            curent = urmator;
        }
    }
