//
// Created by razva on 21.06.2024.
//

#include "repo.h"
#include "fstream"
#include "sstream"
#include "algorithm"

void Repo::add(Melodie mel) {
    repo.push_back(mel);
    write_to_file();
}

void Repo::write_to_file() {
    ofstream fout(filename);
    for(auto &mel : repo) {
        fout<<mel.getID()<<","<<mel.getTitlu()<<","<<mel.getArtist()<<","<<mel.getRank()<<endl;
    }
    fout.close();
}

void Repo::load_from_file() {
    repo.clear();
    string line;
    fstream fin(filename);
    while (getline(fin, line)) {
        int id, rank;
        string titlu, artist;
        stringstream linestream(line);
        string curent;
        int nr = 0;
        while (getline(linestream, curent, ',')) {
            if(nr == 0) id = stoi(curent);
            if(nr == 1) titlu = curent;
            if(nr == 2) artist = curent;
            if(nr == 3) rank = stoi(curent);
            nr++;
        }
        repo.push_back(Melodie(id, titlu, artist, rank));
    }
    fin.close();
}

vector<Melodie> &Repo::sortareRank(vector<Melodie> &lista) {
    sort(lista.begin(), lista.end(), [this](Melodie& a, Melodie&b) {
        return a.getRank() < b.getRank();
    });
    return lista;
}
