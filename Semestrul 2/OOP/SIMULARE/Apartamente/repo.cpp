#include "repo.h"
#include <fstream>

void Repo::adauga(Apartament &apt) {
    int ok = 0;
    for(auto &apartament: repo) {
        if( apartament.get_pret() == apt.get_pret() && apartament.get_strada() == apt.get_strada() && apartament.get_suprafata() == apt.get_suprafata()) {
            ok = 1;
        }
    }
    repo.push_back(apt);
    write_to_file();
}

void Repo::sterge(Apartament &apt) {
    int i = 0;
    while (i < repo.size()) {
        if( repo[i].get_pret() == apt.get_pret() && repo[i].get_strada() == apt.get_strada() && repo[i].get_suprafata() == apt.get_suprafata()) {
            repo.erase(repo.begin() + i);
        }
        i++;
    }
    write_to_file();
}

void Repo::load_from_file() {
    repo.clear();
    ifstream fin("apartamente.txt");
    //Exceptie
    while (!fin.eof()) {
        string strada;
        int pret, suprafata;
        if(fin.eof()) break;
        fin>>strada;
        if(fin.eof()) break;
        fin>>suprafata;
        if(fin.eof()) break;
        fin>>pret;
        Apartament apt(suprafata, strada, pret);
        Repo::adauga(apt);
    }
    fin.close();
}

void Repo::write_to_file() {
    ofstream fout("apartamente.txt");
    for(auto &apt : get_all()) {
        fout<<apt.get_suprafata()<<"\n"<<apt.get_strada()<<"\n"<<apt.get_pret()<<"\n";
    }
    fout.close();
}
