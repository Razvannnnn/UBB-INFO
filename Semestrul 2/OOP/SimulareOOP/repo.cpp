#include "repo.h"
#include "fstream"

void Repo::importFromFile() {
    repo.clear();
    ifstream fin(filename);
    while(!fin.eof()) {
        int cod, numar, pret;
        string denumire;
        if(fin.eof()) break;
        fin>>cod;
        if(fin.eof()) break;
        fin>>denumire;
        if(fin.eof()) break;
        fin>>numar;
        if(fin.eof()) break;
        fin>>pret;
        Produs p(cod, denumire, numar, pret);
        repo.push_back(p);
    }
    fin.close();
}

void Repo::writeToFile() {
    ofstream fout(filename);
    for(auto &p : repo) {
        fout<<p.getCod()<<"\n";
        fout<<p.getDenumire()<<"\n";
        fout<<p.getNumar()<<"\n";
        fout<<p.getPret()<<"\n";
    }
    fout.close();
}

void Repo::adauga(Produs &produs) {
    if(cauta(produs)) {
        throw RepoException("Produs existent");
    }
    repo.push_back(produs);
    writeToFile();
}

void Repo::sterge(Produs &produs) {
    if(!cauta(produs)) {
        throw RepoException("Produs inexistent");
    } else {
        int i = 0;
        while (i < repo.size()) {
            if(repo[i].getCod() == produs.getCod() && repo[i].getPret() == produs.getPret() && repo[i].getDenumire() == produs.getDenumire()
               && repo[i].getNumar() == produs.getNumar()) {
                repo.erase(repo.begin() + i);
            }
            i++;
        }
    }
    writeToFile();
}

bool Repo::cauta(Produs &produs) {
    for(auto & p : repo) {
        if(p.getCod() == produs.getCod() && p.getPret() == produs.getPret() && p.getDenumire() == produs.getDenumire()
        && p.getNumar() == produs.getNumar())
            return true;
    }
    return false;
}

