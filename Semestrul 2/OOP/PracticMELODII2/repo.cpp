#include "repo.h"
#include <sstream>
#include <fstream>

void Repo::sterge(int id) {
    int i = 0;
    for(auto &m : repo) {
        if(id == m.getId()) {
            repo.erase(repo.begin() + i);
            write_to_file();
            return;
        }
        i++;
    }
    write_to_file();
}

void Repo::write_to_file() {
    ofstream fout(fileName);
    for(auto & m: repo) {
        fout<<m.getId()<<","<<m.getTitlu()<<","<<m.getArtist()<<","<<m.getGen()<<"\n";
    }
    fout.close();
}

void Repo::load_from_file() {
    repo.clear();
    ifstream fin(fileName);
    string line;
    while (getline(fin, line)) {
        string titlu, gen, artist;
        int id;
        stringstream linestream(line);
        string curent;
        int nr=0;
        while (getline(linestream, curent, ',')) {
            if(nr == 0) id = stoi(curent);
            if(nr == 1) titlu = curent;
            if(nr == 2) artist = curent;
            if(nr == 3) gen = curent;
            nr++;
        }
        repo.push_back(Melodie(id,titlu,artist,gen));
    }
    fin.close();
}
