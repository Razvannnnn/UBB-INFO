#ifndef ELEVI_REPO_H
#define ELEVI_REPO_H

#include "domain.h"
#include <vector>

using namespace std;

class RepoException {
    string msg;
public:
    RepoException(string msg) : msg{ msg } {

    }

    string getMsg() {
        return msg;
    }
};

class Repo {
private:
    vector<Elev> repo;
public:
    Repo() {
        loadFromFile();
    }

    void loadFromFile();
    void writeToFile();

    void adauga(Elev& elev);
    void sterge(Elev& elev);
    bool cauta(Elev& elev);

    vector<Elev> getAll() {return repo;}
};

#endif //ELEVI_REPO_H
