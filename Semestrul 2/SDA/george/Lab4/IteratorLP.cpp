#include "IteratorLP.h"
#include "Lista.h"
#include <exception>
#include <iostream>

IteratorLP::IteratorLP(const Lista& l) :lista(l) {
	current = lista.primR;
}

void IteratorLP::prim() {
	current = lista.primR;
}

void IteratorLP::urmator() {
	if (current == -1)
		throw std::exception();
	current = lista.urm[current];
}

bool IteratorLP::valid() const {
	if(current == -1)
		return false;
	return true;
}

TElem IteratorLP::element() const {
	if (!valid())
		throw std::exception();
	//std::cout << current << ' ';
	return lista.elem[current];
}


