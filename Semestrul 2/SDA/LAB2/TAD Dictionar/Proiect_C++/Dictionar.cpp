#include "Dictionar.h"
#include <iostream>
#include "IteratorDictionar.h"
/*
 * Constructorul clasei Dictionar
 * Inițializează dimensiunea și capacitatea cu 0 și 2, respectiv.
 * Complexitate: Θ(1)
 */
Dictionar::Dictionar() {
    dimensiune = 0;
    capacitate = 2;
    dictionar = new TElem[capacitate];
    keys = new int[capacitate];
    values = new int[capacitate];
}

/*
 * Destructorul clasei Dictionar
 * Eliberează memoria alocată pentru chei, valori și perechi.
 * Complexitate: Θ(1)
 */
Dictionar::~Dictionar() {
    delete [] keys;
    delete [] values;
    delete [] dictionar;
}

/*
 * Adaugă o pereche (cheie, valoare) în dicționar.
 * Dacă cheia există deja în dicționar, înlocuiește valoarea asociată cheii și returnează vechea valoare.
 * Dacă cheia nu există, adaugă perechea și returnează NULL_TVALOARE.
 * caz favorabil : Teta(1)
 * caz defavorabil : Teta(n)
 * caz mediu : Teta(n)
 * overall case : O(n)
 */
TValoare Dictionar::adauga(TCheie c, TValoare v) {
    // Verificăm dacă avem nevoie să realocăm spațiu
    if (dimensiune == capacitate) {
        capacitate *= 2; // Dublăm capacitatea

        // Alocăm noi spații pentru chei, valori și perechi
        int *keysNou = new int[capacitate];
        int *valuesNou = new int[capacitate];
        TElem *dictionarNou = new TElem[capacitate];

        // Copiem datele existente în noile spații
        for (i64 i = 0; i < dimensiune; i++) {
            keysNou[i] = keys[i];
            valuesNou[i] = values[i];
            dictionarNou[i] = dictionar[i];
        }

        // Eliberăm spațiile vechi
        delete[] keys;
        delete[] values;
        delete[] dictionar;

        // Actualizăm pointerii să pointeze la noile spații
        keys = keysNou;
        values = valuesNou;
        dictionar = dictionarNou;
    }
    // daca exista deja cheia in dictionar, inlocuieste valoarea asociata cheii
    // si returneaza vechea valoare
    for (i64 i = 0; i < dimensiune; i++) {
        if (keys[i] == c) {
            TValoare val = values[i];
            values[i] = v;
            dictionar[i] = std::make_pair(c, v);
            return val;
        }
    }
    // Adăugăm noua pereche la sfârșitul dicționarului
    dictionar[dimensiune] = std::make_pair(c, v);
    keys[dimensiune] = c;
    values[dimensiune] = v;
    dimensiune++;

    return NULL_TVALOARE; // de modificat pentru a returna
}

/*
 * Caută o cheie și returnează valoarea asociată (dacă dicționarul conține cheia) sau NULL_TVALOARE.
 * caz favorabil : Teta(1)
 * caz defavorabil : Teta(n)
 * caz mediu : Teta(n)
 * overall case : O(n)
 */
TValoare Dictionar::cauta(TCheie c) const{
    for (i64 i = 0; i < dimensiune; i++) {
        if (keys[i] == c) {
            return values[i];
        }
    }
	return NULL_TVALOARE;
}

/*
 * Șterge o cheie și returnează valoarea asociată (dacă există) sau NULL_TVALOARE.
 * caz favorabil : Teta(n)
 * caz defavorabil : Teta(n)
 * caz mediu : Teta(n)
 * overall case : Teta(n)
 */
TValoare Dictionar::sterge(TCheie c){
    for (i64 i = 0; i < dimensiune; i++) {
        if (keys[i] == c) {
            TValoare val = values[i];

            // Mutăm toate elementele de după elementul pe care vrem să-l ștergem cu o poziție în față
            for (i64 j = i; j < dimensiune - 1; j++) {
                keys[j] = keys[j + 1];
                values[j] = values[j + 1];
                dictionar[j] = dictionar[j + 1];
            }

            dimensiune--;
            return val;
        }
    }
	return NULL_TVALOARE;
}

/*
 * Returnează numărul de perechi (cheie, valoare) din dicționar.
 * Complexitate: Θ(1)
 */
int Dictionar::dim() const {
    return this->dimensiune;
}

/*
 * Returneaza numarul de perechi adaugate (cheie, valoare) in dictionarul curent dintr un dictionar d
 * caz favorabil : T(1)
 * caz defavorabil : T(m*n) // m - nr elemente dictionar d, n - nr elemente dictionar dict_curent
 * caz mediu : T(n)
 * overall case : O(m*n)
 */
int Dictionar::adaugaInexistente(Dictionar &d) {
    int perechiAdaugate = 0;

    IteratorDictionar it = d.iterator();
    while(it.valid())
    {
        TElem elem = it.element();
        TCheie cheie = elem.first;
        TValoare valoare = elem.second;

        if(cauta(cheie) == NULL_TVALOARE) {
            adauga(cheie, valoare);
            perechiAdaugate++;
        }
        it.urmator();
    }
    return perechiAdaugate;
}

/*
 * Verifică dacă dicționarul este vid.
 * Complexitate: Θ(1)
 */
bool Dictionar::vid() const{
    if (dimensiune == 0) {
        return true;
    }
	return false;
}

/*
 * Returnează un iterator pe dicționar.
 * Complexitate: Θ(1)
 */
IteratorDictionar Dictionar::iterator() const {
	return  IteratorDictionar(*this);
}


