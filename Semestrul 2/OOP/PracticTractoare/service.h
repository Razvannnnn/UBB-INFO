#ifndef PRACTICTRACTOARE_SERVICE_H
#define PRACTICTRACTOARE_SERVICE_H

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
};


#endif //PRACTICTRACTOARE_SERVICE_H
