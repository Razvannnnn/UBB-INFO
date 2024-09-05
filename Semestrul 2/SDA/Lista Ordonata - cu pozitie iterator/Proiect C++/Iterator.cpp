#include "Iterator.h"
#include "LO.h"
#include <exception>

Iterator::Iterator(const LO& lo) : lista(lo){
    current = lo.primu;
}

void Iterator::prim(){
	current = lista.primu;
}

void Iterator::urmator(){
	if(!valid()) {
        throw std::exception();
    }
    current = lista.urm[current];
}

bool Iterator::valid() const{
    return current != -1;
}

TElement Iterator::element() const{
	return lista.elemente[current];
}


