#ifndef TRACTOARE_DOMAIN_H
#define TRACTOARE_DOMAIN_H

#include <string>

using namespace std;

class Tractor {
private:
    int id;
    string denumire, tip;
    int numarRoti;
public:
    Tractor(int id, string denumire, string tip, int numarRoti): id{id}, denumire{denumire}, tip{tip}, numarRoti{numarRoti} {}

    int getId() { return id; }
    string getDenumire() { return denumire; }
    string getTip() { return tip; }
    int getNumarRoti() { return numarRoti; }
};

#endif //TRACTOARE_DOMAIN_H
