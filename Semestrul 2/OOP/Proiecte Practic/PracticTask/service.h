//
// Created by razva on 21.06.2024.
//

#ifndef PRACTICTASK_SERVICE_H
#define PRACTICTASK_SERVICE_H

#include "repo.h"
#include "domain.h"
#include "algorithm"
#include <vector>

class SrvException {
private:
    string msg;
public:
    SrvException(string msg) : msg{msg} {}
    string getMsg() {
        return msg;
    }
};

class Service {
private:
    Repo& repo;

public:
    Service(Repo& repo) : repo{ repo } {}

    void adauga(int id, string descriere, vector<string> programatori, string stare);

    vector<Task>& filtruNume(string nume) {
        auto Taskuri = getAll();
        vector<Task> rez;
        std::copy_if(Taskuri.begin(), Taskuri.end(), back_inserter(rez), [&](Task t) {
            for(auto& s: t.getProgramatori()) {
                if(s==nume) return true;
            }
            return false;
        });
        return rez;
    }

    vector<Task>& getAll() {
        return repo.getAll();
    }
};

#endif //PRACTICTASK_SERVICE_H
