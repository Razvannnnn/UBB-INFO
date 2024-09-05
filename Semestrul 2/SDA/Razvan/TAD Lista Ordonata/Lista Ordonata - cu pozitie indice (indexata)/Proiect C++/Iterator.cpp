#include <exception>
#include "Iterator.h"
#include "LO.h"

/**
 * Constructor pentru iterator
 * @param lo - lista ordonata
 * Preconditii: lo - lista ordonata
 * Postconditii: iteratorul este initializat pe prima pozitie a listei
 *
 * Complexitati :
 * Caz defavorabil : Θ(1)
 * Caz mediu : Θ(1)
 * Caz favorabil : Θ(1)
 */
Iterator::Iterator(const LO& lo) : lista(lo){
    curent = lo.prim;
}

/**
 * Reseteaza pozitia iteratorului la inceputul containerului
 * Complexitati :
 * Caz defavorabil : Θ(1)
 * Caz mediu : Θ(1)
 * Caz favorabil : Θ(1)
 *
 * Preconditii: -
 * Postconditii: iteratorul este pe prima pozitie a listei
 *
 */
void Iterator::prim() {
    curent = lista.prim;
}

/**
 * Muta iteratorul in container
 * arunca exceptie daca iteratorul nu e valid
 * Complexitati :
 * Caz defavorabil : Θ(1)
 * Caz mediu : Θ(1)
 * Caz favorabil : Θ(1)
 *
 * Preconditii: iteratorul este valid
 * Postconditii: iteratorul este pe urmatoarea pozitie a listei
 *
 */
void Iterator::urmator(){
    if(!valid()){
        throw std::exception();
    }
    curent = lista.urm[curent];
}

/**
 * Verifica daca iteratorul e valid (indica un element al containerului)
 * Complexitati :
 * Caz defavorabil : Θ(1)
 * Caz mediu : Θ(1)
 * Caz favorabil : Θ(1)
 *
 * Preconditii: -
 * Postconditii: -
 *
 */
bool Iterator::valid() const{
    if(curent != -1){
        return true;
    }
	return false;
}

/**
 * Returneaza valoarea elementului din container referit de iterator
 * arunca exceptie daca iteratorul nu e valid
 * Complexitati :
 * Caz defavorabil : Θ(1)
 * Caz mediu : Θ(1)
 * Caz favorabil : Θ(1)
 *
 * Preconditii: iteratorul este valid
 * Postconditii: -
 *
 */
TElement Iterator::element() const{
    return lista.elemente[curent];
}