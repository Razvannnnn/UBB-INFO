#include "repo.h"
#include "fstream"
#include "sstream"

void Repo::add(Produs &p) {
    produse.push_back(p);
    write_to_file();
}

void Repo::remove(int id) {
    int i=0;
    for(auto &p : produse) {
        if(id == p.getId()) {
            produse.erase(produse.begin() + i);
            write_to_file();
            return;
        }
        i++;
    }
    write_to_file();
}

void Repo::load_from_file() {
    produse.clear();
    fstream fin(filename);
    string line;
    while(getline(fin, line)) {
        string nume, tip;
        int id;
        double pret;
        stringstream linestream(line);
        string curent;
        int nr = 0;
        while (getline(linestream, curent, ',')) {
            if(nr == 0) id = stoi(curent);
            if(nr == 1) nume = curent;
            if(nr == 2) tip = curent;
            if(nr == 3) pret = stod(curent);
            nr++;
        }
        produse.push_back(Produs(id,nume, tip, pret));
    }
    fin.close();
}

void Repo::write_to_file() {
    ofstream fout(filename);
    for(auto &p : produse) {
        fout<<p.getId()<<","<<p.getNume()<<","<<p.getTip()<<","<<p.getPret()<<"\n";
    }
    fout.close();
}

