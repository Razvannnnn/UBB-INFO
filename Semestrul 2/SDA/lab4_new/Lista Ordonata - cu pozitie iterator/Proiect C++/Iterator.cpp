#include "Iterator.h"
#include "LO.h"
#include <stdexcept>

Iterator::Iterator(const LO& lo) : lo(lo), indexCurent(0) {}

/*
 * Reseteaza pozitia iteratorului la inceputul LO
 * Complexitate: O(1)
 */
void Iterator::prim(){
    indexCurent = 0;
}

/*
 * Muta iteratorul
 * Arunca exceptie daca iteratorul nu e valid
 * Complexitate: O(1)
 */
void Iterator::urmator(){
	if(!valid()) {
        throw std::out_of_range("Iteratorul nu este valid");
    }
    indexCurent++;
}

/*
 * Verifica daca iteratorul e valid
 * Complexitate: O(1)
 */
bool Iterator::valid() const{
	return indexCurent >= 0 && indexCurent < lo.dim();
}

/*
 * Returneaza valoarea elementului referit de iterator
 * Complexitate: O(1)
 */
TElement Iterator::element() const{
	if(!valid()) {
        throw std::out_of_range("Iteratorul nu este valid");
    }
	return lo.elemente[indexCurent];
}


