#include "TestScurt.h"
#include <iostream>
#include <assert.h>
#include "Dictionar.h"
#include "IteratorDictionar.h"

bool conditie(TCheie cheie) {
    return cheie % 2==0;
}

void testAll() { //apelam fiecare functie sa vedem daca exista
	Dictionar d;
	assert(d.vid() == true);
	assert(d.dim() == 0); //adaug niste elemente
	assert(d.adauga(5,5)==NULL_TVALOARE); //
	assert(d.adauga(1,111)==NULL_TVALOARE);
	assert(d.adauga(10,110)==NULL_TVALOARE);
	assert(d.adauga(7,7)==NULL_TVALOARE); //
	assert(d.adauga(1,1)==111);
	assert(d.adauga(10,10)==110); //
	assert(d.adauga(-3,-3)==NULL_TVALOARE);//
	assert(d.dim() == 5);
	assert(d.cauta(10) == 10);
	assert(d.cauta(16) == -1);
	assert(d.sterge(1) == 1);
	assert(d.sterge(6) == -1);
	assert(d.dim() == 4);

    //TESTE FILTREAZA
    Dictionar filtr;
    assert(filtr.adauga(4,10) == NULL_TVALOARE);
    assert(filtr.adauga(3,50) == NULL_TVALOARE);
    assert(filtr.adauga(-2,10) == NULL_TVALOARE);
    assert(filtr.adauga(123,10) == NULL_TVALOARE);
    assert(filtr.adauga(6,10) == NULL_TVALOARE);
    assert(filtr.dim() == 5);
    filtr.filtreaza(conditie);
    assert(filtr.dim() == 3);
    assert(filtr.adauga(4, 20) == 10);
    assert(filtr.adauga(-2, 30) == 10);
    assert(filtr.adauga(6, 20) == 10);

	TElem e;
	IteratorDictionar id = d.iterator();
	id.prim();
	int s1 = 0, s2 = 0;
	while (id.valid()) {
		e = id.element();
		s1 += e.first;
		s2 += e.second;
		id.urmator();
	}
	assert(s1 == 19);
	assert(s2 == 19);

}

