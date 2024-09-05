#include "service.h"

void Service::adauga(int cod, string denumire, string marime, int pret, bool disponibilitate) {
    Rochie rochie(cod, denumire, marime, pret, disponibilitate);
    repo.adauga(rochie);
}

void Service::sterge(int cod, string denumire, string marime, int pret, bool disponibilitate) {
    Rochie rochie(cod, denumire, marime, pret, disponibilitate);
    repo.sterge(rochie);
}
