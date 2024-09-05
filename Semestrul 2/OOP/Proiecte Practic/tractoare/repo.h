//
// Created by razva on 21.06.2024.
//

#ifndef TRACTOARE_REPO_H
#define TRACTOARE_REPO_H


#include "domain.h"
#include <utility>
#include <vector>
#include "string"

using namespace std;

class Repo {
private:
    vector<Tractor> tractoare;
    string filename;

    void load_from_file();
    void write_to_file();
public:
    Repo(string filename): filename{ filename } {
        load_from_file();
    }

    void add(const Tractor& tr);
    vector<Tractor>& sortare(vector<Tractor>& tract);
    vector<Tractor>& getAll() {
        return sortare(this->tractoare);
    }
};


#endif //TRACTOARE_REPO_H