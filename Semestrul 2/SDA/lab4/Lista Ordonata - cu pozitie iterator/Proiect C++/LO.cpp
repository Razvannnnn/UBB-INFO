#include "Iterator.h"
#include "LO.h"

#include <iostream>
using namespace std;

#include <exception>

LO::LO(Relatie r) : rel(r), head(nullptr), tail(nullptr), size(0) {}

/*
 * Returneaza dimensiunea listei
 * Complexitate: 0(1)
 */
int LO::dim() const {
	return size;
}

/*
 * Verifica daca LO este vida
 * Complexitate: 0(1)
 */
bool LO::vida() const {
    return size == 0;
}

/*
 * Returneaza prima pozitie din LO
 * Complexitate: 0(1)
 */
Iterator LO::prim() const {
	Iterator it(*this);
    it.current = head;
	return it;
}

/*
 * Returneaza elementul de pe pozitia curenta
 * Arunca exceptie daca pozitia nu este valida
 * Complexitate: 0(1)
 */
TElement LO::element(Iterator poz) const {
	if(!poz.valid()) {
        throw std::out_of_range("Pozitie invalida a iteratorului");
    }
    return poz.current->value;
}

/*
 * Sterge elementul de pe o pozitie poz si returneaza elementul sters
 * Dupa stergere poz e pozitionat pe elementul de dupa cel sters
 * Arunca excptie daca poz nu e valid
 * caz favorabil : Teta(1)
 * caz defavorabil : Teta(n)
 * caz mediu : Teta(n)
 * overall case : 0(n)
 */
TElement LO::sterge(Iterator& poz) {
	if(!poz.valid()) {
        throw std::out_of_range("Nu se poate sterge, iterator invalid!");
    }

    Node* NodStergere = poz.current;
    TElement deletedValue = NodStergere->value;

    if(NodStergere == head) {
        head = head->next;
        if(head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
    } else if(NodStergere == tail) {
        tail = tail->prev;
        if(tail) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
    } else {
        NodStergere->prev->next = NodStergere->next;
        NodStergere->next->prev = NodStergere->prev;
    }
    delete NodStergere;
    size--;

    poz.urmator();
	return deletedValue;
}


/*
 * Cauta element si returneaza prima pozitie pe care apare (sau iterator invalid)
 * caz favorabil : Teta(1)
 * caz defavorabil : Teta(n)
 * caz mediu : Teta(n)
 * overall case : 0(n)
 */
Iterator LO::cauta(TElement e) const{
    Iterator it(*this);
    Node* current = head;

    while (current != nullptr) {
        if(current->value == e) {
            it.current = current;
            return it;
        }
        current = current->next;
    }
    it.current = nullptr;
    return it;
}

/*
 * Adauga element in LO
 * caz favorabil : Teta(1)
 * caz defavorabil : Teta(n)
 * caz mediu : Teta(n)
 * overall case : 0(n)
 */
void LO::adauga(TElement e) {
	Node* nouNod = new Node(e);

    if(head == nullptr) {
        head = tail = nouNod;
    } else {
        Node* current = head;
        while(current != nullptr && rel(current->value, e)) {
            current = current->next;
        }
        if(current == head) {
            nouNod->next = head;
            head->prev = nouNod;
            head = nouNod;
        } else if(current == nullptr) {
            tail->next = nouNod;
            nouNod->prev = tail;
            tail = nouNod;
        } else {
            nouNod->next = current;
            nouNod->prev = current->prev;
            current->prev->next = nouNod;
            current->prev = nouNod;
        }
    }
    size++;
}


/*
 * Destructorul
 * Elibereaza memoria
 * Complexitate: 0(n)
 */
LO::~LO() {
    while (head != nullptr) {
        Node* Sters = head;
        head = head->next;
        delete Sters;
    }
    tail = nullptr;
    size = 0;
}
