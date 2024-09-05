#include "Multime.h"
#include "IteratorMultime.h"

#include <iostream>

/**
 * Constructor implicit pentru multime
 * Preconditii: -
 * Postconditii: multimea este initializata vida
 *
 * Complexitati :
 * Caz defavorabil : Θ(1)
 * Caz mediu : Θ(1)
 * Caz favorabil : Θ(1)
 */
Multime::Multime() : rad(nullptr) {

}

/**
 * Functie recursiva de adaugare a unui element in arbore
 * @param p - nodul radacina al subarborelui
 * @param elem - elementul de adaugat
 * @param adaugat - referinta catre o variabila booleana care indica daca elementul a fost adaugat
 * Preconditii: -
 * Postconditii: elementul este adaugat in arbore
 *
 * Complexitati :
 * Caz defavorabil : Θ(h)
 * Caz mediu : Θ(h)
 * Caz favorabil : Θ(h)
 */
Nod* adauga_rec(Nod* p, TElem elem, bool& adaugat) {
    if(p == nullptr) {
        Nod* nou = new Nod{elem, nullptr, nullptr};
        adaugat = true;
        return nou;
    }
    if(elem < p->e) {
        p->st = adauga_rec(p->st, elem, adaugat);
    } else if(elem > p->e) {
        p->dr = adauga_rec(p->dr, elem, adaugat);
    }
    return p;
}

/**
 * Adauga un element in multime
 * @param elem - elementul de adaugat
 * Preconditii: -
 * Postconditii: elementul este adaugat in multime daca nu exista deja
 *
 * Complexitati :
 * Caz defavorabil : Θ(h)
 * Caz mediu : Θ(h)
 * Caz favorabil : Θ(h)
 */
bool Multime::adauga(TElem elem) {
	bool adaugat = false;
    rad = adauga_rec(rad, elem, adaugat);
    return adaugat;
}

/**
 * Functie recursiva de stergere a unui element din arbore
 * @param p - nodul radacina al subarborelui
 * @param elem - elementul de sters
 * @param sters - referinta catre o variabila booleana care indica daca elementul a fost sters
 * Preconditii: -
 * Postconditii: elementul este sters din arbore daca exista
 *
 * Complexitati :
 * Caz defavorabil : Θ(h)
 * Caz mediu : Θ(h)
 * Caz favorabil : Θ(h)
 */
Nod* sterge_rec(Nod* p, TElem elem, bool& sters) {
    if (p == nullptr) return nullptr;
    if (elem < p->e) {
        p->st = sterge_rec(p->st, elem, sters);
    } else if (elem > p->e) {
        p->dr = sterge_rec(p->dr, elem, sters);
    } else {
        sters = true;
        if (p->st == nullptr) {  //cazul cu doar nod in dreapta sau niciun nod
            Nod* temp = p->dr;
            delete p;
            return temp;
        } else if (p->dr == nullptr) {   //cazul cu nod doar in stanga
            Nod* temp = p->st;
            delete p;
            return temp;
        } else {                         //caz cu nod in ambele parti
            Nod* succ = p->dr;
            while (succ->st != nullptr) {
                succ = succ->st;
            }
            p->e = succ->e;
            delete succ;
        }
    }
    return p;
}

/**
 * Sterge un element din multime
 * @param elem - elementul de sters
 * Preconditii: -
 * Postconditii: returneaza true daca elementul a fost sters, false altfel
 *
 * Complexitati :
 * Caz defavorabil : Θ(h)
 * Caz mediu : Θ(h)
 * Caz favorabil : Θ(h)
 */
bool Multime::sterge(TElem elem) {
    bool sters = false;
    rad = sterge_rec(rad, elem, sters);
    return sters;
}

/**
 * Functie recursiva de cautare a unui element in arbore
 * @param p - nodul radacina al subarborelui
 * @param elem - elementul de cautat
 * Preconditii: -
 * Postconditii: returneaza true daca elementul exista in arbore, false altfel
 *
 * Complexitati :
 * Caz defavorabil : Θ(h)
 * Caz mediu : Θ(h)
 * Caz favorabil : Θ(1)
 */
bool cauta_rec(Nod* p, TElem elem) {
    if(p == nullptr) return false;
    if(elem == p->e) return true;
    if(elem < p->e) return cauta_rec(p->st, elem);
    else return cauta_rec(p->dr, elem);
}

/**
 * Verifica daca un element se afla in multime
 * @param elem - elementul de cautat
 * Preconditii: -
 * Postconditii: returneaza true daca elementul exista in multime, false altfel
 *
 * Complexitati :
 * Caz defavorabil : Θ(h)
 * Caz mediu : Θ(h)
 * Caz favorabil : Θ(1)
 */
bool Multime::cauta(TElem elem) const {
    return cauta_rec(rad, elem);
}

/**
 * Functie recursiva de calculare a dimensiunii arborelui
 * @param p - nodul radacina al subarborelui
 * Preconditii: -
 * Postconditii: returneaza numarul de noduri din subarbore
 *
 * Complexitati :
 * Caz defavorabil : Θ(n)
 * Caz mediu : Θ(n)
 * Caz favorabil : Θ(n)
 */
int dim_rec(Nod* p) {
    if(p == nullptr) return 0;
    return 1 + dim_rec(p->st) + dim_rec(p->dr);
}

/**
 * Returneaza numarul de elemente din multime
 * Preconditii: -
 * Postconditii: returneaza numarul de elemente din multime
 *
 * Complexitati :
 * Caz defavorabil : Θ(n)
 * Caz mediu : Θ(n)
 * Caz favorabil : Θ(n)
 */
int Multime::dim() const {
	return dim_rec(rad);
}

/**
 * Verifica daca multimea este vida
 * Preconditii: -
 * Postconditii: returneaza true daca multimea este vida, false altfel
 *
 * Complexitati :
 * Caz defavorabil : Θ(1)
 * Caz mediu : Θ(1)
 * Caz favorabil : Θ(1)
 */
bool Multime::vida() const {
    return rad == nullptr;
}

/**
 * Functie recursiva de distrugere a arborelui
 * @param p - nodul radacina al subarborelui
 * Preconditii: -
 * Postconditii: toate nodurile din arbore sunt distruse
 *
 * Complexitati :
 * Caz defavorabil : Θ(n)
 * Caz mediu : Θ(n)
 * Caz favorabil : Θ(n)
 */
void distruge_rec(Nod* p) {
    if(p != nullptr) {
        distruge_rec(p->st);
        distruge_rec(p->dr);
        delete p;
    }
}

/**
 * Destructorul multimii
 * Preconditii: -
 * Postconditii: memoria ocupata de multime este eliberata
 *
 * Complexitati :
 * Caz defavorabil : Θ(n)
 * Caz mediu : Θ(n)
 * Caz favorabil : Θ(n)
 */
Multime::~Multime() {
    distruge_rec(rad);
}

/**
 * Returneaza un iterator pe multime
 * Preconditii: -
 * Postconditii: returneaza un iterator pe multime
 *
 * Complexitati :
 * Caz defavorabil : Θ(1)
 * Caz mediu : Θ(1)
 * Caz favorabil : Θ(1)
 */
IteratorMultime Multime::iterator() const {
	return IteratorMultime(*this);
}

/**
* Complexitati:
* Caz defavorabil: Θ(h)
* Caz mediu: Θ(h)
* Caz favorabil: Θ(1)
*/
Nod* maximNod(Nod* p) {
    while(p->dr != nullptr) {
        p = p->dr;
    }
    return p;
}

/**
* Complexitati:
* Caz defavorabil: Θ(h)
* Caz mediu: Θ(h)
* Caz favorabil: Θ(1)
*/
Nod* minimNod(Nod* p) {
    while(p->st != nullptr) {
        p = p->st;
    }
    return p;
}

/**
* Complexitati:
* Caz defavorabil: Θ(h)
* Caz mediu: Θ(h)
* Caz favorabil: Θ(1)
*/
int Multime::diferentaMaxMin() const {
    if(rad == nullptr) {
        return -1;
    }
    Nod* min = minimNod(rad);
    Nod* max = maximNod(rad);

    return max->e - min->e;
}

