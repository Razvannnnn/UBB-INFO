#ifndef ELEVI_SERVICE_H
#define ELEVI_SERVICE_H

#include "repo.h"

class Service {
private:
    Repo& repo;
public:
    Service(Repo& repo) : repo{ repo } {

    }

    void adauga(int nrMatricol, string nume, string scoala);
    void sterge(int nrMatricol, string nume, string scoala);

    vector<Elev> getAll() { return repo.getAll();}
};

#endif //ELEVI_SERVICE_H
