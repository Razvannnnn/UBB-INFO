
#ifndef TRACTOARE_SERVICE_H
#define TRACTOARE_SERVICE_H


#include "repo.h"

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

    void adaugare(int id, string denumire, string tip, int numarRoti);
    vector<Tractor>& getAll() {
        return repo.getAll();
    }
    vector<string> getTipuri();
    int acelasiTip(string tip);
};



#endif //TRACTOARE_SERVICE_H
