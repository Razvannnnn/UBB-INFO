#include "Colectie.h"
#include "IteratorColectie.h"
#include <exception>
#include <iostream>
#include <cmath>
#include <limits>

using namespace std;
#define NIL -1

Colectie::Colectie() {
    m = MAX;
    e = new pair<TElem, int>[m];
    for (int i = 0; i < m; i++) {
        e[i] = make_pair(NIL, 0);
    }
}

int hashCode(TElem e){
//ptr moment numarul e intreg
    return abs(e);
}

int Colectie::d(TElem elem, int i) const {
    // Funcția de dispersie
    float c1 = 0.5;
    float c2 = 0.5;
    int rez = int((hashCode(elem) % m + (c1 * i) + (c2 * i * i))) % m;
    return rez;
}

int Colectie::cautare(TElem elem) const {
    int i = 0;
    int j;
    do {
        j = d(elem, i);
        if(e[j].first == elem && e[j].second != 0) {
            return j; // Elementul a fost găsit
        }
        if(e[j].first == NIL && e[j].second == 0) {
            return -1;
        }
        i++;
    } while (i < m);
    return -1;
}

void Colectie::adauga(TElem elem) {
    int i = 0;
    int j;
    do {
        j = d(elem, i);
        if (e[j].first == NIL && e[j].second == 0) {
            e[j] = make_pair(elem, 1); // Actualizăm elementul sau îl adăugăm dacă este loc liber sau a fost șters
            return;
        } else if(e[j].first == elem) {
            e[j].second++;
            return;
        }
        i++;
    } while (i < m);
    throw std::out_of_range("Colectie plina!"); // Nu am putut găsi loc pentru element
}


bool Colectie::sterge(TElem elem) {
    int j = cautare(elem);
    if (j != -1) {
        if(e[j].second > 0) {
            e[j].second--;
        } else {
            e[j] = make_pair(NIL, 0);
        }
        return true;
    }
    return false;
}


bool Colectie::cauta(TElem elem) const {
    return cautare(elem) != -1;
}

int Colectie::nrAparitii(TElem elem) const {
    int j = cautare(elem);
    if(j != -1) {
        return e[j].second;
    }
    return 0; // Elementul nu a fost găsit
}


int Colectie::dim() const {
    int count = 0;
    for (int i = 0; i < m; i++) {
        if (e[i].second != 0) {
            count += e[i].second;
        }
    }
    return count;
}


bool Colectie::vida() const {
    return dim() == 0;
}

IteratorColectie Colectie::iterator() const {
	return  IteratorColectie(*this);
}


Colectie::~Colectie() {
	/* de adaugat */
    delete[] e;
}


