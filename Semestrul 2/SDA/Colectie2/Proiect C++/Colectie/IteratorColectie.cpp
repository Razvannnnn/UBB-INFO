#include "IteratorColectie.h"
#include "Colectie.h"
#include "exception"

/**
 * Constructor pentru iterator
 * @param c - colectia
 * Preconditii: -
 * Postconditii: iteratorul este initializat pe prima pozitie a listei
 *
 * Complexitati :
 * Caz defavorabil : Θ(1)
 * Caz mediu : Θ(1)
 * Caz favorabil : Θ(1)
 */
IteratorColectie::IteratorColectie(const Colectie& c): col(c), curent(0), currentFrec(0) {
    urmValid();
}


/**
 * Reseteaza pozitia iteratorului la inceputul containerului
 * Preconditii: -
 * Postconditii: iteratorul este pe prima pozitie valida din container
 *
 * Complexitati :
 * Caz defavorabil : Θ(m)
 * Caz mediu : Θ(m)
 * Caz favorabil : Θ(1)
 */
void IteratorColectie::prim() {
	curent = 0;
    currentFrec = 0;
    urmValid();
}

/**
 * Muta iteratorul la urmatorul element valid din container
 * Preconditii: iteratorul este valid
 * Postconditii: iteratorul este pe urmatoarea pozitie valida din container
 *
 * Complexitati :
 * Caz defavorabil : Θ(m)
 * Caz mediu : Θ(m)
 * Caz favorabil : Θ(1)
 */
void IteratorColectie::urmator() {
	if(valid()) {
        currentFrec++;
        if(currentFrec >= col.e[curent].second) {
            currentFrec = 0;
            curent++;
            urmValid();
        }
    } else {
        throw std::exception();
    }
}

/**
 * Verifica daca iteratorul este valid
 * Preconditii: -
 * Postconditii: returneaza true daca iteratorul este valid, false altfel
 *
 * Complexitati :
 * Caz defavorabil : Θ(1)
 * Caz mediu : Θ(1)
 * Caz favorabil : Θ(1)
 */
bool IteratorColectie::valid() const {
    return curent < col.m;
}

/**
 * Returneaza valoarea elementului din container referit de iterator
 * Preconditii: iteratorul este valid
 * Postconditii: returneaza valoarea elementului curent
 *
 * Complexitati :
 * Caz defavorabil : Θ(1)
 * Caz mediu : Θ(1)
 * Caz favorabil : Θ(1)
 */
TElem IteratorColectie::element() const {
	if(!valid()) {
        throw std::exception();
    }
	return col.e[curent].first;
}

/**
 * Muta iteratorul la urmatoarea pozitie valida din container
 * Preconditii: -
 * Postconditii: iteratorul este pe o pozitie valida sau la sfarsitul containerului
 *
 * Complexitati :
 * Caz defavorabil : Θ(m)
 * Caz mediu : Θ(m)
 * Caz favorabil : Θ(1)
 */
void IteratorColectie::urmValid() {
    while (curent < col.m && col.e[curent].first == NULL_TELEM) {
        curent++;
    }
}