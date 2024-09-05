#include "produs.h"

double Produs::getPret() const {
    return pret;
}

string Produs::getNume() const{
    return nume;
}

string Produs::getTip() const{
    return tip;
}

string Produs::getProducator() const{
    return producator;
}

void Produs::setPret(double newPret) {
    pret = newPret;
}

void Produs::setNume(const string& newNume) {
    nume = newNume;
}

void Produs::setTip(const string& newTip) {
    tip = newTip;
}

void Produs::setProducator(const string& newProducator) {
    producator = newProducator;
}

Produs::Produs() {
    pret = 0;
    nume = "";
    tip = "";
    producator = "";
}