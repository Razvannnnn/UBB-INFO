#include "Dictionar.h"
#include <iostream>
#include "IteratorDictionar.h"
/*
 * Constructorul clasei Dictionar
 * Inițializează dimensiunea și valoarea header-ului
 * Complexitate: Θ(1)
 */
Dictionar::Dictionar() {
    head = nullptr;
    dimensiunea = 0;
}

/*
 * Destructorul clasei Dictionar
 * Eliberează memoria alocată pentru nodurile din lista.
 * Complexitate: Θ(n)
 */
Dictionar::~Dictionar() {
    while (head != nullptr) {
        Node* next = head->next;
        delete head;
        head = next;
    }
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
    Node* current = head;
    while (current != nullptr) {
        if(current->element.first == c) {
            TValoare oldValue = current->element.second;
            current->element.second = v;
            return oldValue;
        }
        current = current->next;
    }

    Node* newNode = new Node(std::make_pair(c, v));
    newNode->next = head;
    head = newNode;
    dimensiunea++;
    return NULL_TVALOARE;
}

/*
 * Caută o cheie și returnează valoarea asociată (dacă dicționarul conține cheia) sau NULL_TVALOARE.
 * caz favorabil : Teta(1)
 * caz defavorabil : Teta(n)
 * caz mediu : Teta(n)
 * overall case : O(n)
 */
TValoare Dictionar::cauta(TCheie c) const{
    Node* current = head;
    while (current != nullptr) {
        if (current->element.first == c) {
            return current->element.second;
        }
        current = current->next;
    }
    return NULL_TVALOARE;
}

/*
 * Șterge o cheie și returnează valoarea asociată (dacă există) sau NULL_TVALOARE.
 * caz favorabil : Teta(1)
 * caz defavorabil : Teta(n)
 * caz mediu : Teta(n)
 * overall case : Teta(n)
 */
TValoare Dictionar::sterge(TCheie c){
    Node* pre = nullptr;
    Node* current = head;
    while (current != nullptr) {
        if (current->element.first == c) {
            if (pre != nullptr) {
                pre->next = current->next;
            } else {
                head = current->next;
            }
            TValoare val = current->element.second;
            delete current;
            dimensiunea--;
            return val;
        }
        pre = current;
        current = current->next;
    }
    return NULL_TVALOARE;
}

/*
 * Conditia este o functie care primeste ca parametru o cheie si returneaza
 * adevarat sau fals (adevarat daca cheia respecta conditia si fals, altfel)
 * caz favorabil : Teta(n)
 * caz defavorabil : Teta(n)
 * caz mediu : Teta(n)
 * overall case : Teta(n)
 */
void Dictionar::filtreaza(Conditie cond) {
    Node* pre = nullptr;
    Node* current = head;

    while (current != nullptr) {
        if(!cond(current->element.first)) {
            Node* next = current->next;
            delete current;
            if(pre != nullptr) {
                pre->next = next;
            } else {
                head = next;
            }
            current = next;
            dimensiunea--;
        } else {
            pre = current;
            current = current->next;
        }
    }
}

/*
 * Returnează numărul de perechi (cheie, valoare) din dicționar.
 * Complexitate: Θ(1)
 */
int Dictionar::dim() const {
    return dimensiunea;
}

/*
 * Verifică dacă dicționarul este vid.
 * Complexitate: Θ(1)
 */
bool Dictionar::vid() const{
    return dimensiunea == 0;
}

/*
 * Returnează un iterator pe dicționar.
 * Complexitate: Θ(1)
 */
IteratorDictionar Dictionar::iterator() const {
    return IteratorDictionar(*this);
}


