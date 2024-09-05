#ifndef SIMULAREOOP_DOMAIN_H
#define SIMULAREOOP_DOMAIN_H

#include <string>

using namespace std;

class Produs {
private:
    int cod, numar, pret;
    string denumire;
public:
    Produs(int cod, string denumire, int numar, int pret) : cod{ cod }, denumire{ denumire }, numar{ numar }, pret{ pret } {}

    int getCod() {return cod;}
    int getNumar() {return numar;}
    int getPret() {return pret;}
    string getDenumire() {return denumire;};
};

#endif //SIMULAREOOP_DOMAIN_H
