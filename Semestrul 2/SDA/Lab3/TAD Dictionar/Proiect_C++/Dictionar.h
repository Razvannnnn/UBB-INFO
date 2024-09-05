#pragma once
#define i64 long long

#define NULL_TVALOARE -1
typedef int TCheie;
typedef int TValoare;
typedef bool (*Conditie)(TCheie);

class IteratorDictionar;

#include <utility>
typedef std::pair<TCheie,TValoare> TElem;

struct Node {
    TElem element;
    Node* next;

    Node(const TElem& e, Node* n = nullptr) : element(e), next(n) {
    }
};

class Dictionar {
	friend class IteratorDictionar;

private:
	/* aici e reprezentarea */
    Node* head;
    i64 dimensiunea;

public:

	// constructorul implicit al dictionarului
	Dictionar();

	// adauga o pereche (cheie, valoare) in dictionar	
	//daca exista deja cheia in dictionar, inlocuieste valoarea asociata cheii si returneaza vechea valoare
	// daca nu exista cheia, adauga perechea si returneaza null: NULL_TVALOARE
	TValoare adauga(TCheie c, TValoare v);

	//cauta o cheie si returneaza valoarea asociata (daca dictionarul contine cheia) sau null: NULL_TVALOARE
	TValoare cauta(TCheie c) const;

	//sterge o cheie si returneaza valoarea asociata (daca exista) sau null: NULL_TVALOARE
	TValoare sterge(TCheie c);

	//returneaza numarul de perechi (cheie, valoare) din dictionar 
	int dim() const;

    /*
     * Conditia este o functie care primeste ca parametru o cheie si returneaza
     * adevarat sau fals (adevarat daca cheia respecta conditia si fals, altfel)
     */
    void filtreaza(Conditie cond);

	//verifica daca dictionarul e vid 
	bool vid() const;

	// se returneaza iterator pe dictionar
	IteratorDictionar iterator() const;


	// destructorul dictionarului	
	~Dictionar();

};


