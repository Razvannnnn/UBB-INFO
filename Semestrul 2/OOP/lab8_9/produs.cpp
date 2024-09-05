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

bool cmpNume(const Produs &p1, const Produs &p2) {
    return p1.getNume() < p2.getNume();
}

bool cmpPret(const Produs &p1, const Produs &p2) {
    return p1.getPret() < p2.getPret();
}

bool cmpNumeTip(const Produs &p1, const Produs &p2) {
    if(p1.getNume() == p2.getNume()) {
        return p1.getTip() < p2.getTip();
    }
    return p1.getNume() < p2.getNume();
}