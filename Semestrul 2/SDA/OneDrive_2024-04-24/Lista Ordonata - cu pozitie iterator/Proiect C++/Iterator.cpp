#include "Iterator.h"
#include "LO.h"
#include <stdexcept>

Iterator::Iterator(const LO& lo, int curent) : lo(lo), curent(curent) {
}

void Iterator::prim(){
    curent = lo.primu;
}

void Iterator::urmator(){
	if(!valid()) {
        throw std::runtime_error("Iteratorul este invalid!");
    }
    curent = lo.urm[curent];
}

bool Iterator::valid() const{
	return curent != -1;
} 

TElement Iterator::element() const{
	if(!valid()) {
        throw std::runtime_error("Iteratorul este invalid!");
    }
    return lo.elemente[curent];
}


