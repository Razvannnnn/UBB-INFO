#ifndef PRACTICPRODUSE_REPO_H
#define PRACTICPRODUSE_REPO_H

#include "domain.h"
#include "vector"

using namespace std;

class Repo {
private:
    vector<Produs> produse;
    string filename;

    void load_from_file();
    void write_to_file();
public:
    Repo(string filename): filename{ filename } {
        load_from_file();
    }
    void add(Produs& p);
    void remove(int id);
    vector<Produs> getAll() { return this->produse;}
};

#endif //PRACTICPRODUSE_REPO_H
