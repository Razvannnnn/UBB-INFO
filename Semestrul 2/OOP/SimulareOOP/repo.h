#ifndef SIMULAREOOP_REPO_H
#define SIMULAREOOP_REPO_H

#include "domain.h"
#include <vector>

using namespace std;

class RepoException {
    string msg;
public:
    RepoException(string msg) : msg{ msg } {

    }
    string getMsg(){return msg;}
};

class Repo {
private:
    vector<Produs> repo;
    string filename;
public:
    Repo(string filename) : filename{filename} {
        importFromFile();
    }
    /**
     * Citeste lista de produse dintr un fisier
     */
    void importFromFile();

    /**
     * Scrie lista de produse intr un fisier
     */
    void writeToFile();
    /**
     * Funtie de adaugare
     * @param produs - produsul adaugat
     */
    void adauga(Produs& produs);

    /**
     * Functie de stergere
     * @param produs - produsul sters
     */
    void sterge(Produs& produs);

    /**
     * Functie de cautare
     * @param produs - produsul cautat
     * @return true - daca exista
     *         false - daca nu exista
     */
    bool cauta(Produs& produs);

    /**
     * Returneaza lista de produse
     * @return
     */
    vector<Produs>& getAll() {return repo;}
};

#endif //SIMULAREOOP_REPO_H
