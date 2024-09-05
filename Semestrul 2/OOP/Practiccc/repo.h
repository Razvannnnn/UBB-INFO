//
// Created by razva on 21.06.2024.
//

#ifndef PRACTICCC_REPO_H
#define PRACTICCC_REPO_H

#include "domain.h"
#include "observer.h"
#include <iostream>
#include <vector>
#include "string"

using namespace std;

class Repo: public Observable{
private:
    vector<Melodie> repo;
    string fileName;

    void load_from_file();
    void write_to_file();
public:
    Repo(string filename): fileName{ filename } {
        load_from_file();
    }
    vector<Melodie>& getAll() {
        return this->repo;
    }
    void adauga(const Melodie& mel) {
        repo.push_back(mel);
        write_to_file();
        this->notify();
    }
    void sterge(int id);
};


#endif //PRACTICCC_REPO_H
