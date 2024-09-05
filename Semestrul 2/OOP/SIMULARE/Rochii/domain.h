#ifndef ROCHII_DOMAIN_H
#define ROCHII_DOMAIN_H

#include <string>

using namespace std;

class Rochie {
private:
    int cod, pret;
    string denumire, marime;
    bool disponibilitate;
public:
    Rochie(int cod, string denumire, string marime, int pret, bool disponibilitate) : cod{ cod }, denumire{ denumire }, marime{ marime }, pret{ pret }, disponibilitate{ disponibilitate } {

    }

    int getCod();
    int getPret();
    string getDenumire();
    string getMarime();
    bool getDisponibilitate();
};

#endif //ROCHII_DOMAIN_H
