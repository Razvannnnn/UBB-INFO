//
// Created by razva on 21.06.2024.
//

#ifndef MELODII1PRACTIC_REPO_H
#define MELODII1PRACTIC_REPO_H

#include "domain.h"
#include <vector>

using namespace std;

class Repo {
private:
    vector<Melodie> repo;
    string filename;

    void write_to_file();
    void load_from_file();
public:
    Repo(string filename) : filename{filename} {
        load_from_file();
    }

    void add(Melodie mel);
    void modify(int id, string titlu, int rank) {
        for(auto &mel : repo) {
            if(id == mel.getID()) {
                mel.setRank(rank);
                mel.setTitlu(titlu);
            }
        }
        write_to_file();
    }
    vector<Melodie>& sortareRank(vector<Melodie>& lista);
    vector<Melodie>& getAll() {
        return sortareRank(repo);
    }
};


#endif //MELODII1PRACTIC_REPO_H
