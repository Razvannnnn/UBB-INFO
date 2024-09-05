#ifndef PRACTICMELODII2_DOMAIN_H
#define PRACTICMELODII2_DOMAIN_H

#include <iostream>
#include <string>

using namespace std;

class Melodie {
private:
    int id;
    string titlu;
    string artist;
    string gen;

public:
    Melodie(int id, string titlu, string artist, string gen): id{id}, titlu{titlu}, artist{artist}, gen{gen} {}
    //Melodie(Melodie &mel): id{mel.id}, titlu{mel.titlu}, artist{mel.artist}, gen{mel.gen} {}

    int getId() {
        return id;
    }
    string getTitlu() {
        return titlu;
    }
    string getArtist() {
        return artist;
    }
    string getGen() {
        return gen;
    }

    void setId(int newId) {
        this->id = newId;
    }
    void setTitlu(string newTitlu) {
        this->titlu = newTitlu;
    }
    void setArtist(string newArtist) {
        this->artist = newArtist;
    }
    void setGen(string newGen) {
        this->gen = newGen;
    }
};

#endif //PRACTICMELODII2_DOMAIN_H
