#ifndef APARTAMENTE_DOMAIN_H
#define APARTAMENTE_DOMAIN_H

#include <iostream>
#include <stdlib.h>

using namespace std;

class Apartament {
private:
    int suprafata, pret;
    string strada;
public:
    Apartament(int suprafata, std::string strada, int pret) : suprafata{ suprafata }, pret{ pret }, strada{ strada } {
    }
    int get_suprafata() {return suprafata;}
    string get_strada() {return strada;}
    int get_pret() {return pret;}
};

#endif //APARTAMENTE_DOMAIN_H
