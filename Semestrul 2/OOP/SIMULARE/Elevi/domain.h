#ifndef ELEVI_DOMAIN_H
#define ELEVI_DOMAIN_H

#include "string"

using namespace std;

class Elev {
private:
    int nrMatricol;
    string nume, scoala;
public:
    Elev(int nrMatricol, string nume, string scoala) : nrMatricol{ nrMatricol }, nume{ nume }, scoala{ scoala } {

    }

    int getNrMatricol() {return nrMatricol;}
    string getNume() {return nume;}
    string getScoala() {return scoala;}
};


#endif //ELEVI_DOMAIN_H
