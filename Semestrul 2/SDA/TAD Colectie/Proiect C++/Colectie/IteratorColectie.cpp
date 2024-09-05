#include "IteratorColectie.h"
#include "Colectie.h"
#include <math.h>
#include <exception>

using namespace std;

#define NIL -1

IteratorColectie::IteratorColectie(const Colectie& c): col(c) {
	curent = 0;
    deplasare();
}

void IteratorColectie::prim() {
	curent = 0;
    deplasare();
}


void IteratorColectie::urmator() {
	curent++;
    deplasare();
}


bool IteratorColectie::valid() const {
	return (curent < col.m);
}


TElem IteratorColectie::element() const {
    if(!valid()) {
        throw exception();
    }
	return col.e[curent].first;
}

void IteratorColectie::deplasare() {
    while ((curent < col.m) && col.e[curent].second == 0)
        curent++;
}