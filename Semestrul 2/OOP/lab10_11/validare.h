#ifndef LAB6_VALIDARE_H
#define LAB6_VALIDARE_H

#include <cstring>
#include <iostream>
#include <utility>
using std::string;

class Exception {
    string msg;
public:
    explicit Exception(string m) : msg{ m } {
    }

    string getMsg() {
        return msg;
    }
};

class Valid {
public:
    /**
     * Verificare daca parametru x este nevid
     * @param x - string
     * @return
     */
    static bool non_vid(const std::string& x);

    /**
     * Verifica daca parametru este mai mare ca 0
     * @param pret - double
     * @return
     */
    static bool non_negative(double pret);

    /**
     * Functie de validare a intregului produs
     * @param nume
     * @param tip
     * @param pret
     * @param producator
     */
    static void validProdus(std::string& nume, std::string &tip, double pret, std::string &producator);
};

void teste_validare(Valid valid);

#endif //LAB6_VALIDARE_H
