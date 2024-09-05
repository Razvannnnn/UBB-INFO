#ifndef ROCHII_SERVICE_H
#define ROCHII_SERVICE_H

#include "repo.h"

class Service {
private:
    Repo& repo;
public:
    Service(Repo& repo) : repo{ repo } {

    }

    void adauga(int cod, string denumire, string marime, int pret, bool disponibilitate);
    void sterge(int cod, string denumire, string marime, int pret, bool disponibilitate);

    vector<Rochie> getAll() {return repo.getAll();}
};

#endif //ROCHII_SERVICE_H
