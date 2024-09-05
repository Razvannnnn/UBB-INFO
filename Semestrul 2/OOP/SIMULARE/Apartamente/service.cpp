#include "service.h"

void Service::adauga(int suprafata, string strada, int pret) {
    Apartament apt(suprafata, strada, pret);
    repo.adauga(apt);
}

void Service::sterge(int suprafata, string strada, int pret) {
    Apartament apt(suprafata, strada, pret);
    repo.sterge(apt);
}
