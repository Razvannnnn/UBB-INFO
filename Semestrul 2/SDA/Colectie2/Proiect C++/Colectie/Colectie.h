#pragma once

#include <utility>

using namespace std;

#define NULL_TELEM -99999
#define MAX 100
typedef int TElem;

class IteratorColectie;

class Colectie
{
	friend class IteratorColectie;

private:
	/* aici e reprezentarea */
    pair<TElem, int>* e;

    int m;  // intervalul maxim
    int n;  // numarul curent de elemente
    int pozOcupate;

    int d(TElem elem, int i) const;
    int cautare(TElem elem) const;
    void resize();
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

        int diferentaMaxMin() const;

};

