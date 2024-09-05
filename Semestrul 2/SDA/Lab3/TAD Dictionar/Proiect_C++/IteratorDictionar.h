#pragma once
#include "Dictionar.h"
#define i64 long long

class IteratorDictionar
{
	friend class Dictionar;
private:

	const Dictionar& dict;
    Node* curent;

    IteratorDictionar(const Dictionar& d) : dict(d), curent(d.head){
    }
public:

		//reseteaza pozitia iteratorului la inceputul containerului
		void prim();

		//muta iteratorul in container
		// arunca exceptie daca iteratorul nu e valid
		void urmator();

		//verifica daca iteratorul e valid (indica un element al containerului)
		bool valid() const;

		//returneaza valoarea elementului din container referit de iterator
		//arunca exceptie daca iteratorul nu e valid
		TElem element() const;
};
