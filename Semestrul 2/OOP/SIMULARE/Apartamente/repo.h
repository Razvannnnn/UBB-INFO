#ifndef APARTAMENTE_REPO_H
#define APARTAMENTE_REPO_H

#include "domain.h"
#include <vector>

using namespace std;

class Repo {
private:
    vector<Apartament> repo;

    void load_from_file();
    void write_to_file();

public:
    Repo() {
        load_from_file();
    }

    vector<Apartament> get_all() {return repo;}
    void adauga(Apartament &apt);
    void sterge(Apartament &apt);
};

#endif //APARTAMENTE_REPO_H
