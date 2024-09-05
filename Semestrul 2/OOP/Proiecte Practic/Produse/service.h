#ifndef SERVICE_H
#define SERVICE_H

#include <QString>
#include <vector>
#include "produse.h"
#include <string>
#include "repo.h"

class Service
{
public:
    Repo repo;
    Service(Repo& r): repo(r){}
    /// o functie care verifica datele de intrare pentru un produs si il adauga il repo daca e valid
    /// returneaza un QString cu toate erorile din validator, respectiv un Qstring gol daca e bine
    QString adaugare(int id, QString nume, QString tip, double pret);
    /// o functie care verifica datele de intrare pentru un produs
    /// returneaza un QString cu toate erorile din validator, respectiv un Qstring gol daca e bine
    QString validator(int id, QString nume, QString tip, double pret);
    ///returneaza un un vector ce comntine toate produsele
    vector<Produse> getAll(){
        return this->repo.getAll();
    }
    vector<Produse> filtrare(int x);
};

#endif // SERVICE_H
