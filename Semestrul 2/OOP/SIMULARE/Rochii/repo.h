#ifndef ROCHII_REPO_H
#define ROCHII_REPO_H

#include "domain.h"
#include "vector"

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
    vector<Rochie> repo;
public:
    Repo() {
        loadFromFile();
    }

    vector<Rochie> getAll();
    void loadFromFile();
    void writeToFile();

    bool cauta(Rochie rochie);
    void adauga(Rochie rochie);
    void sterge(Rochie rochie);
};

#endif //ROCHII_REPO_H
