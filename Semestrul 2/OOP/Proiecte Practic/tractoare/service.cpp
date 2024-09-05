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

vector<string> Service::getTipuri() {
    vector<string> tipuri = {};
    for(auto &tr: repo.getAll()) {
        int ok=1;
        for(auto &tip: tipuri) {
            if(tr.getTip() == tip) ok = 0;
        }
        if(ok == 1) tipuri.push_back(tr.getTip());
    }
    return tipuri;
}

int Service::acelasiTip(string tip) {
    int k = 0;
    for(auto &tr : repo.getAll()) {
        if(tr.getTip() == tip) k++;
    }
    return k;
}

