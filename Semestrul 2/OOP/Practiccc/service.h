//
// Created by razva on 21.06.2024.
//

#ifndef PRACTICCC_SERVICE_H
#define PRACTICCC_SERVICE_H

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
    Service(Repo& repo) : repo{ repo }  {}

    void add(string titlu, string artist, string gen);
    void remove(int id);
    vector<Melodie>& getAll() {
        return repo.getAll();
    }
};

#endif //PRACTICCC_SERVICE_H
