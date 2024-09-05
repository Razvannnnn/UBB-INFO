#ifndef SIMULAREOOP_SERVICE_H
#define SIMULAREOOP_SERVICE_H

#include "repo.h"

class Service {
private:
    Repo& repo;
public:
    Service(Repo& repo) : repo{ repo } {

    }
    /**
     * Adauga un produs in lista de produse
     * Construieste produsul
     * @param cod - int
     * @param denumire - string
     * @param numar - intr
     * @param pret - int
     */
    void adauga(int cod, string denumire, int numar, int pret);

    /**
     * Construieste produsul
     * Il sterge daca exista din lista de produse
     * @param cod - int
     * @param denumire - string
     * @param numar - intr
     * @param pret - int
     */
    void sterge(int cod, string denumire, int numar, int pret);

    /**
     * Returneaza toata lista de produse
     * @return
     */
    vector<Produs>& getAll() {return repo.getAll();}
};

#endif //SIMULAREOOP_SERVICE_H
