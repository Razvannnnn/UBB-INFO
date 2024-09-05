#include "Iterator.h"
#include "LO.h"
#include <stdexcept>


Iterator::Iterator(const LO& lo) : lo(lo), current(lo.head){
}

/*
 * Reseteaza pozitia iteratorului la inceputul LO
 * Complexitate: O(1)
 */
void Iterator::prim(){
    current = lo.head;
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
    current = current->next;
}

/*
 * Verifica daca iteratorul e valid
 * Complexitate: O(1)
 */
bool Iterator::valid() const{
	return current != nullptr;
}

/*
 * Returneaza valoarea elementului referit de iterator
 * Complexitate: O(1)
 */
TElement Iterator::element() const{
	if(!valid()) {
        throw std::out_of_range("Iteratorul nu este valid");
    }
	return current->value;
}


