#include <exception>
#include "IteratorLP.h"
#include "Lista.h"

#include <iostream>


Lista::Lista() {
	dimensiune = 0;
	primR = -1;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		urm[i] = i + 1;
		elem[i] = NULL_TELEM;
	}
	urm[MAX_SIZE - 1] = -1;

	primLiber = 0;
}


//Worst case Theta(1), Best case Theta(1), Overall Theta(1)
int Lista::aloca() {
	int i = primLiber;
	primLiber = urm[primLiber];
	return i;
}


//Worst case Theta(1), Best case Theta(1), Overall Theta(1)
void Lista::dealoca(int i) {
	urm[i] = primLiber;
	primLiber = i;
}


//Worst case Theta(1), Best case Theta(1), Overall Theta(1)
int Lista::creeazaNod(TElem e) {
	int i = aloca();
	if (i != -1)
	{
		this->elem[i] = e;
		urm[i] = -1;
	}
	return i;
}


//Worst case Theta(1), Best case Theta(1), Overall Theta(1)
int Lista::dim() const {
	return dimensiune;
}


//Worst case Theta(1), Best case Theta(1), Overall Theta(1)
bool Lista::vida() const {
	if(dimensiune == 0)
		return true;
	return false;
}


//Worst case Theta(1), Best case Theta(1), Overall Theta(1)
IteratorLP Lista::prim() const {
	return IteratorLP(*this);
}


//Worst case Theta(1), Best case Theta(1), Overall Theta(1)
TElem Lista::element(IteratorLP poz) const {
	return poz.element();
}

//Worst case Theta(n), Best case Theta(1), Overall O(n)
TElem Lista::sterge(IteratorLP& poz) {
	if (!poz.valid())
		throw std::exception();

	IteratorLP p(*this);
	int poz_ant = p.current;
	TElem toDel = poz.element();

	while (p.current != poz.current)
	{
		poz_ant = p.current;
		p.urmator();
	}

	urm[poz_ant] = urm[poz.current];
	int toDealoc = poz.current;
	poz.current = urm[poz.current];
	dealoca(toDealoc);

	dimensiune--;

	return toDel;	
}


IteratorLP Lista::cauta(TElem e) const {
	IteratorLP p(*this);
	while (p.valid())
	{
		int x = p.element();
		if (p.element() == e)
			break;
		else
			p.urmator();
	}
	return p;	
}


//Worst case Theta(1), Best case Theta(1), Overall Theta(1)
TElem Lista::modifica(IteratorLP poz, TElem e) {
	if (!poz.valid())
		throw std::exception();

	TElem toRet = poz.element();
	elem[poz.current] = e;
	return toRet;
}


//Worst case Theta(n), Best case Theta(1), Overall O(n)
void Lista::adauga(IteratorLP& poz, TElem e) {
	if (!poz.valid())
		throw std::exception();


	if (dimensiune == 0)
		adaugaInceput(e);

	int i = creeazaNod(e);

	if (i != -1)
	{
		IteratorLP p(*this);
		int poz_ant = p.current;

		while (p.current != poz.current)
		{
			poz_ant = p.current;
			p.urmator();
		}

		urm[poz_ant] = i;
		urm[i] = p.current;
		poz.current = i;
		dimensiune++;


	}

}


//Best case Theta(1), Worst case Theta(1), Overall Theta(1)
void Lista::adaugaInceput(TElem e) {
	/* de adaugat */
	int i = creeazaNod(e);
	
	if (i != -1)
	{
		urm[i] = primR;
		primR = i;
		dimensiune++;
	}
}

void Lista::view() {
	int i = primR;
	while (urm[i] != -1)
	{
		std::cout << elem[i] << ' ';
		i = urm[i];
	}
	std::cout << elem[i] << '\n';
}

//Worst case Theta(n), Best case Theta(n), Overall Theta(n)
void Lista::adaugaSfarsit(TElem e) {
	/* de adaugat */
	if (dimensiune == 0)
	{
		adaugaInceput(e);
		return;
	}

	int i = creeazaNod(e);
	if (i != -1)
	{
		int p = primR;
		while (urm[p] != -1)
		{
			p = urm[p];
		}
		urm[p] = i;
		dimensiune++;
	}

}

Lista::~Lista() {
	/* de adaugat */
}
