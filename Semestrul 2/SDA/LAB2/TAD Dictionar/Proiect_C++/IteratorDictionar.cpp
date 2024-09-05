#include "IteratorDictionar.h"
#include "Dictionar.h"
#include <exception>
#include <iostream>
using namespace std;

/*
 * Constructorul primeste o referinta catre Container
 * iteratorul va referi primul element din container
 * Complexitate: O(1)
 */
IteratorDictionar::IteratorDictionar(const Dictionar& d) : dict(d){
    curent = 0;
}

/*
 * Reseteaza pozitia iteratorului la inceputul containerului
 * Complexitate: O(1)
 */
void IteratorDictionar::prim() {
    curent = 0;
}

/*
 * Muta iteratorul in container
 * Arunca exceptie daca iteratorul nu e valid
 * Complexitate: O(1)
 */
void IteratorDictionar::urmator() {
    if(valid())curent++;
    else throw std::runtime_error("Iteratorul nu este valid!");
}

/*
 * Verifica daca iteratorul e valid (indica un element al containerului)
 * Complexitate: O(1)
 */
TElem IteratorDictionar::element() const {
    if (!valid()) {
        throw std::runtime_error("Iteratorul nu este valid!");
    }
    return dict.dictionar[curent];
}

/*
 * Returneaza valoarea elementului din container referit de iterator
 * Arunca exceptie daca iteratorul nu e valid
 * Complexitate: O(1)
 */
bool IteratorDictionar::valid() const {
    if(curent < dict.dim()) return true;
	return false;
}

