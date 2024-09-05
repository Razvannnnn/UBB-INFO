#ifndef APARTAMENTE_SERVICE_H
#define APARTAMENTE_SERVICE_H

#include "repo.h"
#include <vector>

class Service {
private:
    Repo& repo;
public:
    Service(Repo& repo) : repo{ repo } {}

    void adauga(int suprafata, string strada, int pret);
    void sterge(int suprafata, string strada, int pret);

    vector<Apartament> get_all() {return repo.get_all();};
};

#endif //APARTAMENTE_SERVICE_H
