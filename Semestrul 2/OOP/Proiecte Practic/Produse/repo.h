#ifndef REPO_H
#define REPO_H

#include <QString>
#include <vector>
#include "produse.h"
#include <string>
#include "Observer.h"

using namespace std;

class Repo: public Observable
{
private:
    vector<Produse> lista;
    string fisier;
public:
    Repo(string fisier1):fisier(fisier1){
        loadFromFile();
    }
    /*
     * functia adauga un produs valid p la finalul listei
     * Produs p: un produs valid
    */
    void adaugare(Produse p){
        lista.push_back(p);
        loadToFile();
        this->notify();
    }
    ///incarca datele din fisier in lista
    void loadFromFile();
    ///incarca datele din lista in fisier
    void loadToFile();

    ///returneaza un un vector ce comntine toate produsele
    vector<Produse> getAll(){
        return this->lista;
    }
};

#endif // REPO_H
