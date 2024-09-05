#include "Colectie.h"
#include "IteratorColectie.h"
#include <exception>
#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

/**
 * Constructor implicit pentru colectie
 * Preconditii: -
 * Postconditii: colectia este initializata cu capacitatea maxima MAX si vida
 *
 * Complexitati :
 * Caz defavorabil : Θ(m)
 * Caz mediu : Θ(m)
 * Caz favorabil : Θ(m)
 */
Colectie::Colectie() {
	m = MAX;
    n = 0;
    pozOcupate = 0;
    e = new pair<TElem, int>[m];
    for(int i=0;i<m;i++) {
        e[i] = make_pair(NULL_TELEM, 0);
    }
}

/**
 * Functie de hash pentru elemente
 * @param elem - elementul de hash-uit
 * Preconditii: -
 * Postconditii: returneaza codul hash pentru element
 *
 * Complexitati :
 * Caz defavorabil : Θ(1)
 * Caz mediu : Θ(1)
 * Caz favorabil : Θ(1)
 */
int hashCode(TElem elem) {
    return abs(elem);
}

/**
 * Functie de dispersie pentru elemente
 * @param elem - elementul de dispersat
 * @param i - indicele de dispersie
 * Preconditii: -
 * Postconditii: returneaza indicele de dispersie pentru element
 *
 * Complexitati :
 * Caz defavorabil : Θ(1)
 * Caz mediu : Θ(1)
 * Caz favorabil : Θ(1)
 */
int Colectie::d(TElem elem, int i) const {
    const float c1 = 1;
    const float c2 = 0;
    return (int)(hashCode(elem)%m + (c1*i) + (c2*i*i))%m;
}

/**
 * Cauta elementul in colectie
 * @param elem - elementul de cautat
 * Preconditii: -
 * Postconditii: returneaza indicele elementului daca este gasit, -1 altfel
 *
 * Complexitati :
 * Caz defavorabil : Θ(m)
 * Caz mediu : Θ(1)
 * Caz favorabil : Θ(1)
 */
int Colectie::cautare(TElem elem) const {
    int i = 0;
    int j;
    do {
        j = d(elem, i);
        if (e[j].first == elem) {
            return j;
        }
        i++;
    } while (i < m);
    return -1;
}

/**
 * Redimensioneaza colectia
 * Preconditii: -
 * Postconditii: colectia este redimensionata de doua ori capacitatea actuala
 *
 * Complexitati :
 * Caz defavorabil : Θ(m^2)
 * Caz mediu : Θ(m^2)
 * Caz favorabil : Θ(m^2)
 */
void Colectie::resize() {
    int vechi_m = m;
    m = m * 2;

    pair<TElem, int>* nouE = new pair<TElem, int>[m];
    for(int i=0;i<m;i++) {
        nouE[i] = make_pair(NULL_TELEM, 0);
    }

    for(int i=0;i<vechi_m;i++) {
        if(e[i].second != 0) {
            int j=0;
            int nouI;
            do {
                nouI = d(e[i].first, j);
                if(nouE[nouI].second == 0) {
                    nouE[nouI] = e[i];
                    break;
                }
                j++;
            } while (j < m);
        }
    }
    delete[] e;
    e = nouE;
}


/**
 * Adauga un element in colectie
 * @param elem - elementul de adaugat
 * Preconditii: -
 * Postconditii: elementul este adaugat in colectie
 *
 * Complexitati :
 * Caz defavorabil : Θ(m)
 * Caz mediu : Θ(1)
 * Caz favorabil : Θ(1)
 */
void Colectie::adauga(TElem elem) {
    if(pozOcupate == m) {
        resize();
    }
	int i = 0;
    int j;
    do {
        j = d(elem, i);
        if(e[j].second == 0) {
            e[j] = make_pair(elem, 1);
            n++;
            pozOcupate++;
            return;
        } else if(e[j].first == elem) {
            e[j].second++;
            n++;
            return;
        }
        i++;
    } while (i<m);
    throw std::out_of_range("Colectie plina!");
}

/**
 * Sterge o aparitie a unui element din colectie
 * @param elem - elementul de sters
 * Preconditii: -
 * Postconditii: returneaza true daca elementul a fost sters, false altfel
 *
 * Complexitati :
 * Caz defavorabil : Θ(m)
 * Caz mediu : Θ(1)
 * Caz favorabil : Θ(1)
 */
bool Colectie::sterge(TElem elem) {
    int j = cautare(elem);
    if(j != -1) {
        if(e[j].second > 1) {
            e[j].second--;
            n--;
        }
        else {
            e[j] = make_pair(NULL_TELEM, 0);
            n--;
            pozOcupate--;
        }
        return true;
    }
	return false;
}

/**
 * Verifica daca un element se afla in colectie
 * @param elem - elementul de cautat
 * Preconditii: -
 * Postconditii: returneaza true daca elementul este gasit, false altfel
 *
 * Complexitati :
 * Caz defavorabil : Θ(m)
 * Caz mediu : Θ(1)
 * Caz favorabil : Θ(1)
 */
bool Colectie::cauta(TElem elem) const {
	return cautare(elem) != -1;
}

/**
 * Returneaza numarul de aparitii ale unui element in colectie
 * @param elem - elementul de cautat
 * Preconditii: -
 * Postconditii: returneaza numarul de aparitii ale elementului
 *
 * Complexitati :
 * Caz defavorabil : Θ(m)
 * Caz mediu : Θ(1)
 * Caz favorabil : Θ(1)
 */
int Colectie::nrAparitii(TElem elem) const {
	int j = cautare(elem);
    if(j != -1) {
        return e[j].second;
    }
	return 0;
}

/**
 * Returneaza numarul de elemente din colectie
 * Preconditii: -
 * Postconditii: returneaza numarul de elemente din colectie
 *
 * Complexitati :
 * Caz defavorabil : Θ(1)
 * Caz mediu : Θ(1)
 * Caz favorabil : Θ(1)
 */
int Colectie::dim() const {
    return n;
}

/**
 * Verifica daca colectia este vida
 * Preconditii: -
 * Postconditii: returneaza true daca colectia este vida, false altfel
 *
 * Complexitati :
 * Caz defavorabil : Θ(1)
 * Caz mediu : Θ(1)
 * Caz favorabil : Θ(1)
 */
bool Colectie::vida() const {
	return n == 0;
}

/**
 * Returneaza un iterator pe colectie
 * Preconditii: -
 * Postconditii: returneaza un iterator pe colectie
 *
 * Complexitati :
 * Caz defavorabil : Θ(1)
 * Caz mediu : Θ(1)
 * Caz favorabil : Θ(1)
 */
IteratorColectie Colectie::iterator() const {
	return  IteratorColectie(*this);
}

/**
 * Destructorul colectiei
 * Preconditii: -
 * Postconditii: memoria ocupata de colectie este eliberata
 *
 * Complexitati :
 * Caz defavorabil : Θ(1)
 * Caz mediu : Θ(1)
 * Caz favorabil : Θ(1)
 */
Colectie::~Colectie() {
	delete[] e;
}

/**
 * Returneaza diferenta dintre valoarea maxima si cea minima in colectie
 * Preconditii: -
 * Postconditii: returneaza diferenta dintre valoarea maxima si cea minima, -1 daca colectia este vida
 *
 * Complexitati :
 * Caz defavorabil : theta(m)
 * Caz mediu : theta(m)
 * Caz favorabil : theta(m)
 */
int Colectie::diferentaMaxMin() const {
    if (vida()) {
        return -1;
    }
    TElem minElem = std::numeric_limits<TElem>::max();
    TElem maxElem = std::numeric_limits<TElem>::min();

    for (int i = 0; i < m; ++i) {
        if (e[i].second > 0) {
            if (e[i].first < minElem) {
                minElem = e[i].first;
            }
            if (e[i].first > maxElem) {
                maxElem = e[i].first;
            }
        }
    }

    return maxElem - minElem;
}
