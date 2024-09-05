#include "Iterator.h"
#include "LO.h"
#include <exception>

Iterator::Iterator(const LO& lo) : lo(lo){
    current = lo.primR;
}

void Iterator::prim(){
	current = lo.primR;
}

void Iterator::urmator(){
	if(current == -1)
        throw std::exception();
    current = lo.urm[current];
}

bool Iterator::valid() const{
	if(current == -1)
	    return false;
    return true;
}

TElement Iterator::element() const{
	if(!valid())
        throw std::exception();
	return lo.elem[current];
}


