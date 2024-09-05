#pragma once

class Iterator;

typedef int TComparabil;
typedef TComparabil TElement;

typedef bool (*Relatie)(TElement, TElement);

const int CAPACITATE = 1000;

#define NULL_TELEMENT -1

class LO {
private:
	friend class Iterator;
private:
	/* aici reprezentarea */
    static const int capacitate = CAPACITATE;

    TElement elemente[capacitate];
    int urm[capacitate];
    int pre[capacitate];

    int primLiber;

    int primu;
    int ultim;

    int dimensiune;

    Relatie rel;

    int aloca();
    void dealoca(int poz);
    int creeazaNod(TElement e);

public:
		// constructor
		LO (Relatie r);

		// returnare dimensiune
		int dim() const;

		// verifica daca LO e vida
		bool vida() const;

		// prima pozitie din LO
		Iterator prim() const;

		// returnare element de pe pozitia curenta
		//arunca exceptie daca poz nu e valid
		TElement element(Iterator poz) const;

		// adaugare element in LO a.i. sa se pastreze ordinea intre elemente
		void adauga(TElement e);

		// sterge element de pe o pozitie poz si returneaza elementul sters
		//dupa stergere poz e pozitionat pe elementul de dupa cel sters
		//arunca exceptie daca poz nu e valid
		TElement sterge(Iterator& poz);

		// cauta element si returneaza prima pozitie pe care apare (sau iterator invalid)
		Iterator cauta(TElement e) const;

		//destructor
		~LO();

};
