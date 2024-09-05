//
// Created by razva on 22.05.2024.
//

#include "service.h"

void Service::adauga(int cod, string denumire, int numar, int pret) {
    Produs p(cod, denumire, numar, pret);
    repo.adauga(p);
}

void Service::sterge(int cod, string denumire, int numar, int pret) {
    Produs p(cod, denumire, numar, pret);
    repo.sterge(p);
}
