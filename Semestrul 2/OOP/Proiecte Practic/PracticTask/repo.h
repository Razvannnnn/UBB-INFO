//
// Created by razva on 21.06.2024.
//

#ifndef PRACTICTASK_REPO_H
#define PRACTICTASK_REPO_H

#include "domain.h"
#include <vector>

using namespace std;

class Repo {
private:
    vector<Task> repo;
    string filename;

    void load_from_file();
    void write_to_file();
public:
    Repo(string filename) : filename{filename} {
        load_from_file();
    }

    void add(Task task);

    vector<Task>& sortare(vector<Task>& taskuri);

    vector<Task>& getAll() {
        load_from_file();
        return sortare(this->repo);
    }
};

#endif //PRACTICTASK_REPO_H
