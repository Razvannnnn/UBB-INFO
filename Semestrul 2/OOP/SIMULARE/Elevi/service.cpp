//
// Created by razva on 21.05.2024.
//

#include "service.h"

void Service::adauga(int nrMatricol, string nume, string scoala) {
    Elev elev(nrMatricol, nume, scoala);
    repo.adauga(elev);
}

void Service::sterge(int nrMatricol, string nume, string scoala) {
    Elev elev(nrMatricol, nume, scoala);
    repo.sterge(elev);
}
