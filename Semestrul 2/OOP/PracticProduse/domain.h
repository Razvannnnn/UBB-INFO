#ifndef PRACTICPRODUSE_DOMAIN_H
#define PRACTICPRODUSE_DOMAIN_H

#include <string>

using namespace std;

class Produs {
private:
    int id;
    string nume, tip;
    double pret;
public:
    Produs(int id, string nume, string tip, double pret) : id{ id }, nume{ nume }, tip{ tip }, pret{ pret } {}

    int getId(){ return id;}
    string getNume(){return nume;}
    string getTip(){return tip;}
    double getPret(){return pret;}

    void setId(int newId){ this->id = newId;}
    void setNume(string newNume){ this->nume = newNume;}
    void setTip(string newTip){ this->tip = newTip;}
    void setPret(double newPret){ this->pret = newPret;}

    int getVocale() {
        int k = 0;
        for(char &x: nume) {
            if(x == 'a') k++;
            if(x == 'e') k++;
            if(x == 'i') k++;
            if(x == 'o') k++;
            if(x == 'u') k++;
            if(x == 'A') k++;
            if(x == 'E') k++;
            if(x == 'I') k++;
            if(x == 'O') k++;
            if(x == 'U') k++;
        }
        return k;
    }
};

#endif //PRACTICPRODUSE_DOMAIN_H
