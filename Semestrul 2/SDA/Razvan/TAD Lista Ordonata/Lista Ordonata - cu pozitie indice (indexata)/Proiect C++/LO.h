#pragma once

class Iterator;

typedef int TComparabil;
typedef TComparabil TElement;

typedef bool (*Relatie)(TElement, TElement);

#define NULL_TELEMENT -1
#define CAPACITATE 10000
class LO {
private:
	friend class Iterator;
private:
	/* aici e reprezentarea */
    static const int capacitate = CAPACITATE;

    // Vectorul de elemente
    TElement elemente[CAPACITATE];

    // Vectorul de urmatoarele elemente
    int urm[CAPACITATE];

    // Vectorul de predecesori
    int pre[CAPACITATE];

    // primul element liber
    int primLiber;

    // referinta catre primul element al listei
    int prim;

    // referinta catre ultimul element al listei
    int ultim;

    // dimensiunea listei
    int dimensiune;

    Relatie rel;

    // Metode private
    // se returneaza o pozitie libera
    int aloca();

    // se elibereaza o pozitie
    void dealoca(int poz);

    // functie care creeaza un nod in lista inlantuita
    int creeazaNod(TElement e);
public:
	// constructor
	LO(Relatie r);

	// returnare dimensiune
	int dim() const;

	// verifica daca LO e vida
	bool vida() const;

	// returnare element
	//arunca exceptie daca i nu e valid
	TElement element(int i) const;

	// adaugare element in LO a.i. sa se pastreze ordinea intre elemente
	void adauga(TElement e);

	// sterge element de pe o pozitie i si returneaza elementul sters
	//arunca exceptie daca i nu e valid
	TElement sterge(int i);

	// cauta element si returneaza prima pozitie pe care apare (sau -1)
	int cauta(TElement e) const;

	// returnare iterator
	Iterator iterator();

	//destructor
	~LO();

};
