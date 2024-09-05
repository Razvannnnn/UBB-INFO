//
// Created by razva on 21.05.2024.
//

#include "repo.h"
#include "fstream"

void Repo::loadFromFile() {
    repo.clear();
    ifstream fin("elevi.txt");
    while (!fin.eof()) {
        int nrMatricol;
        string nume, scoala;
        if(fin.eof()) break;
        fin>>nrMatricol;
        if(fin.eof()) break;
        fin>>nume;
        if(fin.eof()) break;
        fin>>scoala;
        Elev elev(nrMatricol, nume, scoala);
        adauga(elev);
    }
    fin.close();
}

void Repo::writeToFile() {
    ofstream fout("elevi.txt");
    for(auto & e : repo) {
        fout << e.getNrMatricol() << "\n";
        fout << e.getNume() << "\n";
        fout << e.getScoala() << "\n";
    }
    fout.clear();
}

void Repo::adauga(Elev &elev) {
    if(cauta(elev)) {
        throw RepoException("Elev existent!");
    }
    repo.push_back(elev);
    writeToFile();
}

void Repo::sterge(Elev &elev) {
    if(!cauta(elev)) {
        throw RepoException("Elev inexistent!");
    } else {
        int i=0;
        while (i < repo.size()) {
            if(repo[i].getNume() == elev.getNume() && repo[i].getNrMatricol() == elev.getNrMatricol() && repo[i].getScoala() == elev.getScoala()) {
                repo.erase(repo.begin() + i);
            }
            i++;
        }
    }
}

bool Repo::cauta(Elev &elev) {
    for(auto & e : repo) {
        if(e.getNume() == elev.getNume() && e.getNrMatricol() == elev.getNrMatricol() && e.getScoala() == elev.getScoala()) {
            return true;
        }
    }
    return false;
}
