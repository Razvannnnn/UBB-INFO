//
// Created by razva on 21.06.2024.
//

#ifndef MELODII1PRACTIC_SERVICE_H
#define MELODII1PRACTIC_SERVICE_H

#include "domain.h"
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

    void add(int id, string titlu, string artist, int rank);
    void modify(int id, string titlu, int rank) {
        repo.modify(id, titlu, rank);
    }
    vector<Melodie>& getAll() {
        return repo.getAll();
    }
};

#endif //MELODII1PRACTIC_SERVICE_H
