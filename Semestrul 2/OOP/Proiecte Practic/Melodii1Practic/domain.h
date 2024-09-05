//
// Created by razva on 21.06.2024.
//

#ifndef MELODII1PRACTIC_DOMAIN_H
#define MELODII1PRACTIC_DOMAIN_H

#include <string>

using namespace std;

class Melodie {
private:
    int id;
    string titlu, artist;
    int rank;
public:
    Melodie(int id, string titlu, string artist, int rank) : id{id}, titlu{titlu}, artist{artist}, rank{rank} {}

    int getID() { return id; }
    string getTitlu() { return titlu; }
    string getArtist() { return artist; }
    int getRank() { return rank; }
    void setTitlu(string newTitlu) { titlu = newTitlu; }
    void setRank(int newRank) { rank = newRank; }
};

#endif //MELODII1PRACTIC_DOMAIN_H
