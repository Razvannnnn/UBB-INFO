#include "IteratorDictionar.h"
#include "Dictionar.h"
#include <exception>
#include <iostream>
using namespace std;

/*
 * Reseteaza pozitia iteratorului la inceputul dictionarului
 * Complexitate: O(1)
 */
void IteratorDictionar::prim() {
    curent = dict.head;
}

/*
 * Muta iteratorul
 * Arunca exceptie daca iteratorul nu e valid
 * Complexitate: O(1)
 */
void IteratorDictionar::urmator() {
    if (valid()) {
        curent = curent->next;
    } else {
        throw std::runtime_error("Iteratorul nu este valid!");
    }
}

/*
 * Verifica daca iteratorul e valid
 * Complexitate: O(1)
 */
TElem IteratorDictionar::element() const {
    if (!valid()) {
        throw std::runtime_error("Iteratorul nu este valid!");
    }
    return curent->element;
}

/*
 * Returneaza valoarea elementului referit de iterator
 * Complexitate: O(1)
 */
bool IteratorDictionar::valid() const {
    return curent != nullptr;
}

