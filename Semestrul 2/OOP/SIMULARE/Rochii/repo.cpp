#include "repo.h"
#include "fstream"

vector<Rochie> Repo::getAll() {
    return repo;
}

void Repo::loadFromFile() {
    repo.clear();
    ifstream fin("rochie.txt");
    while(!fin.eof()) {
        int cod, pret;
        string denumire, marime;
        bool disponibilitate;
        if(fin.eof()) break;
        fin>>cod;
        if(fin.eof()) break;
        fin>>denumire;
        if(fin.eof()) break;
        fin>>marime;
        if(fin.eof()) break;
        fin>>pret;
        if(fin.eof()) break;
        fin>>disponibilitate;
        Rochie rochie(cod, denumire, marime, pret, disponibilitate);
        adauga(rochie);
    }
    fin.close();
}

void Repo::writeToFile() {
    ofstream fout("rochie.txt");
    for(auto &rochie : getAll()) {
        fout << rochie.getCod() << "\n";
        fout << rochie.getDenumire() << "\n";
        fout << rochie.getMarime() << "\n";
        fout << rochie.getPret() << "\n";
        fout << rochie.getDisponibilitate() << "\n";

    }
}

bool Repo::cauta(Rochie rochie) {
    for(auto &r : getAll()) {
        if(rochie.getCod() == r.getCod() && rochie.getMarime() == r.getMarime() && rochie.getPret() == r.getPret() && rochie.getDisponibilitate() == r.getDisponibilitate() && rochie.getDenumire() == r.getDenumire()) {
            return true;
        }
    }
    return false;
}

void Repo::adauga(Rochie rochie) {
    if(cauta(rochie) == true) {
        throw RepoException("Rochia exista deja!");
    }
    repo.push_back(rochie);
    writeToFile();
}

void Repo::sterge(Rochie rochie) {
    if(cauta(rochie) == false) {
        throw RepoException("Rochia nu exista!");
    } else {
        int i = 0;
        while (i < repo.size()) {
            if(rochie.getCod() == repo[i].getCod() && rochie.getMarime() == repo[i].getMarime() && rochie.getPret() == repo[i].getPret() && rochie.getDisponibilitate() == repo[i].getDisponibilitate() && rochie.getDenumire() == repo[i].getDenumire()) {
                repo.erase(repo.begin() + i);
            }
            i++;
        }
    }
    writeToFile();
}
