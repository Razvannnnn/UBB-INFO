#pragma once

#include <utility>
#include <cmath>

#define MAX 100000
#define NIL -1

using namespace std;

typedef int TElem;

class IteratorColectie;

class Colectie
{
	friend class IteratorColectie;

private:
	/* aici e reprezentarea */
    int m;     //numarul de locatii din tabela de dispersie
    pair<TElem, int>* e;    //vectorul elementelor

    int d(TElem e, int i) const;
    int cautare(TElem elem) const;
public:
		//constructorul implicit
		Colectie();

		//adauga un element in colectie
		void adauga(TElem e);

		//sterge o aparitie a unui element din colectie
		//returneaza adevarat daca s-a putut sterge
		bool sterge(TElem e);

		//verifica daca un element se afla in colectie
		bool cauta(TElem elem) const;

		//returneaza numar de aparitii ale unui element in colectie
		int nrAparitii(TElem elem) const;


		//intoarce numarul de elemente din colectie;
		int dim() const;

		//verifica daca colectia e vida;
		bool vida() const;

		//returneaza un iterator pe colectie
		IteratorColectie iterator() const;

		// destructorul colectiei
		~Colectie();

};

