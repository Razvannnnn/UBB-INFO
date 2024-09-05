#ifndef LAB6_PRODUS_H
#define LAB6_PRODUS_H


#include <string>
#include <iostream>
#include <utility>

using std::string;

class Produs {

private:
    string nume;
    string tip;
    double pret;
    string producator;
public:

    double getPret() const;
    string getNume() const;
    string getTip() const;
    string getProducator() const;

    void setPret(double newPret);
    void setNume(const string& newNume);
    void setTip(const string& newTip);
    void setProducator(const string& newProducator);

    Produs();
    Produs(string nume, string tip, double pret, string producator) :nume{std::move(nume)}, tip{std::move(tip)}, pret{pret}, producator{std::move(producator)}{
    }

};

#endif //LAB6_PRODUS_H
