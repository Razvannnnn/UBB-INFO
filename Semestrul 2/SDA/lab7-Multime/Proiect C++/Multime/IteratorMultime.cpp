#include "IteratorMultime.h"
#include "Multime.h"
#include "exception"


/**
 * Constructor pentru iterator
 * @param m - multimea
 * Preconditii: -
 * Postconditii: iteratorul este initializat pe prima pozitie a listei
 *
 * Complexitati :
 * Caz defavorabil : Θ(1)
 * Caz mediu : Θ(1)
 * Caz favorabil : Θ(1)
 */
IteratorMultime::IteratorMultime(const Multime& m) : multime(m), curent(nullptr) {
    prim();
}

/**
 * Gaseste nodul cu valoarea minima dintr-un subarbore
 * @param p - nodul radacina al subarborelui
 * Preconditii: -
 * Postconditii: returneaza nodul cu valoarea minima din subarbore
 *
 * Complexitati :
 * Caz defavorabil : Θ(h)
 * Caz mediu : Θ(h)
 * Caz favorabil : Θ(h)
 */
Nod* minim(Nod* p) {
    if(p == nullptr) return nullptr;
    while (p->st != nullptr) {
        p = p->st;
    }
    return p;
}

/**
 * Reseteaza pozitia iteratorului la inceputul containerului
 * Preconditii: -
 * Postconditii: iteratorul este pe prima pozitie valida din container
 *
 * Complexitati :
 * Caz defavorabil : Θ(h)
 * Caz mediu : Θ(h)
 * Caz favorabil : Θ(1)
 */
void IteratorMultime::prim() {
    curent = minim(multime.rad);
}

/**
 * Muta iteratorul la urmatorul element valid din container
 * Preconditii: iteratorul este valid
 * Postconditii: iteratorul este pe urmatoarea pozitie valida din container
 *
 * Complexitati :
 * Caz defavorabil : Θ(h)
 * Caz mediu : Θ(h)
 * Caz favorabil : Θ(1)
 */
void IteratorMultime::urmator() {
    if(!valid()) {
        throw std::exception();
    }
    if(curent->dr != nullptr) {
        curent = minim(curent->dr);
    } else {
        Nod* suc = nullptr;
        Nod* pred = multime.rad;
        while (pred != curent) {
            if(curent->e < pred->e) {
                suc = pred;
                pred = pred->st;
            } else {
                pred = pred->dr;
            }
        }
        curent = suc;
    }
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
TElem IteratorMultime::element() const {
	if(!valid()) {
        throw std::exception();
    } else {
        return curent->e;
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
bool IteratorMultime::valid() const {
	return curent != nullptr;
}
