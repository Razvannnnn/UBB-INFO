//
// Created by razva on 21.06.2024.
//

#ifndef PRACTICTASK_DOMAIN_H
#define PRACTICTASK_DOMAIN_H

#include <string>
#include <vector>

using namespace std;

class Task {
private:
    int id;
    string descriere;
    vector<string> programatori;
    string stare;
public:
    Task(int id, string descriere, vector<string> programatori, string stare) : id{id}, descriere{descriere}, programatori{programatori}, stare{stare} {}

    int getId() { return id; }
    string getDescriere() { return descriere; }
    vector<string> getProgramatori() { return programatori; }
    string getStare() { return stare; }
};

#endif //PRACTICTASK_DOMAIN_H
