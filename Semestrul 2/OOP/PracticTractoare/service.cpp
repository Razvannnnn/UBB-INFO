#include "service.h"
#include "algorithm"

void Service::adaugare(int id, string denumire, string tip, int numarRoti) {
    if(denumire == "" || tip == "") {
        throw SrvException("Tractor invalid!");
    }
    for(auto &tr : repo.getAll()) {
        if(tr.getId() == id) {
            throw SrvException("ID invalid!");
        }
    }
    if(numarRoti % 2 == 1 || numarRoti < 2 || numarRoti > 16) {
        throw SrvException("Numar roti invalid!");
    }
    repo.add(Tractor(id,denumire,tip,numarRoti));
}

