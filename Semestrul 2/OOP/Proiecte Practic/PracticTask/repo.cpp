//
// Created by razva on 21.06.2024.
//

#include "repo.h"
#include "fstream"
#include "sstream"
#include "algorithm"

void Repo::add(Task task) {
    repo.push_back(task);
    write_to_file();
}

void Repo::load_from_file() {
    repo.clear();
    fstream fin(filename);
    string line;
    while (getline(fin, line)) {
        int id;
        string descriere;
        vector<string> programatori;
        string stare;
        stringstream linestream(line);
        int nr = 0;
        string curent;
        while (getline(linestream, curent, ',')) {
            if(nr == 0) id = stoi(curent);
            if(nr == 1) descriere = curent;
            if(nr == 2) stare = curent;
            if(nr == 3) programatori.push_back(curent);
            if(nr == 4) programatori.push_back(curent);
            if(nr == 5) programatori.push_back(curent);
            if(nr == 6) programatori.push_back(curent);
            nr++;
        }
        repo.push_back(Task(id,descriere,programatori,stare));
    }
    fin.close();
}

void Repo::write_to_file() {
    ofstream fout(filename);
    for(auto &task : repo) {
        fout<<task.getId()<<","<<task.getDescriere()<<","<<task.getStare();
        for(auto &pr : task.getProgramatori()) {
            fout<<","<<pr;
        }
        fout<<endl;
    }
    fout.close();
}

vector<Task> &Repo::sortare(vector<Task> &taskuri) {
    sort(taskuri.begin(), taskuri.end(),[this](Task& t1, Task& t2) {
        return t1.getStare() < t2.getStare();
    });
    return taskuri;
}
