#include "domain.h"

int Rochie::getCod() {
    return cod;
}

int Rochie::getPret() {
    return pret;
}

string Rochie::getDenumire() {
    return std::string(denumire);
}

string Rochie::getMarime() {
    return std::string(marime);
}

bool Rochie::getDisponibilitate() {
    return disponibilitate;
}
