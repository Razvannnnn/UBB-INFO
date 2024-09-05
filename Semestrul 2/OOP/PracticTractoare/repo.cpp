#include "repo.h"
#include "fstream"
#include "sstream"
#include "algorithm"

void Repo::add(const Tractor &tr) {
    tractoare.push_back(tr);
    write_to_file();
}

void Repo::load_from_file() {
    tractoare.clear();
    fstream fin(filename);
    string line;
    while (getline(fin, line)) {
        int id, numarRoti;
        string denumire, tip;
        stringstream linestream(line);
        string curent;
        int nr = 0;
        while (getline(linestream, curent, ',')) {
            if(nr == 0) id = stoi(curent);
            if(nr == 1) denumire = curent;
            if(nr == 2) tip = curent;
            if(nr == 3) numarRoti = stoi(curent);
            nr++;
        }
        tractoare.push_back(Tractor(id,denumire,tip,numarRoti));
    }
    fin.close();
}

void Repo::write_to_file() {
    ofstream fout(filename);
    for(auto &tr: tractoare) {
        fout<<tr.getId()<<","<<tr.getDenumire()<<","<<tr.getTip()<<","<<tr.getNumarRoti()<<endl;
    }
    fout.close();
}

vector<Tractor>& Repo::sortare(vector<Tractor>& tract) {
    sort(tract.begin(), tract.end(), [this](Tractor& a, Tractor& b) {
        return a.getDenumire() > b.getDenumire();
    });
}
