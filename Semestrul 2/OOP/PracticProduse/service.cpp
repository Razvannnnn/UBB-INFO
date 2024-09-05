#include "service.h"
#include "algorithm"

void Service::add(int id, string &nume, string &tip, double pret) {
    if(id > 0 && nume != "" && pret >= 1.0 && pret <= 100.0) {
        for(auto &p : repo.getAll()) {
            if(id == p.getId()){
                throw SrvException("Id invalid!");
            }
        }
        Produs p = Produs(id, nume, tip, pret);
        repo.add(p);
    } else {
        throw SrvException("Produs invalid!");
    }
}

void Service::remove(int id) {
    repo.remove(id);
}

vector<Produs> Service::sortare(vector<Produs> produse) {
    sort(produse.begin(), produse.end(), [this](Produs& a, Produs& b) {
       return a.getPret() < b.getPret();
    });
    return produse;
}
