#include "Iterator.h"
#include "LO.h"
#include <stdexcept>

/**
 * Constructor pentru iterator
 * @param lo - lista ordonata
 * @param pozStart - prima pozitie
 * Preconditii: lo - lista ordonata
 * Postconditii: iteratorul este initializat pe prima pozitie a listei
 *
 * Complexitati :
 * Caz defavorabil : Θ(1)
 * Caz mediu : Θ(1)
 * Caz favorabil : Θ(1)
 */
Iterator::Iterator(const LO& lo, int pozStart) : lo(lo) {
    this->curent = pozStart;
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
void Iterator::prim(){
    this->curent = this->lo.primu;
}

/**
 * Muta iteratorul la urmatorul element
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
    if(!valid()) {
        throw std::exception();
    }
    this->curent = this->lo.urm[curent];
}

/**
 * Verifica daca iteratorul e valid
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
    return this->curent != -1;
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
    if(!valid()) {
        throw std::exception();
    }
    return this->lo.elemente[curent];
}

/**
 * Avanseaza iteratorul cu k pasi inainte
 * Arunca o excepție daca iteratorul nu este valid sau daca k este zero sau negativ
 * Dacă exista mai putin de k elemente rămase în lista, iteratorul devine nevalid
 * Complexitati:
 * Caz defavorabil : Θ(k)
 * Caz mediu : Θ(k)
 * Caz favorabil : Θ(k)
 *
 * @param k - numarul de pasi cu care sa avanseze iteratorul
 * Preconditii: k > 0
 * Postconditii: -
 */
void Iterator::avanseazaKPasi(int k) {
    if (k <= 0) {
        throw std::invalid_argument("Numarul de pasi trb sa fie pozitiv!");
    }
    for (int i = 0; i < k; ++i) {
        if (!valid()) {
            throw std::exception();
        }
        urmator();
    }
}