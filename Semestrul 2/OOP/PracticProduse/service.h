#ifndef PRACTICPRODUSE_SERVICE_H
#define PRACTICPRODUSE_SERVICE_H

#include "repo.h"

using namespace std;

class SrvException {
private:
    string msg;
public:
    SrvException(string msg) : msg{ msg } {}

    string getMsg() {
        return msg;
    }
};

class Service {
private:
    Repo& repo;
public:
    Service(Repo& repo) : repo{repo} {}

    void add(int id, string &nume, string &tip, double Pret);
    void remove(int id);
    vector<Produs> sortare(vector<Produs> produse);
    vector<Produs> getAll() {return sortare(repo.getAll());}
};

#endif //PRACTICPRODUSE_SERVICE_H
