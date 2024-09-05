#include "validare.h"


#include <cassert>

bool Valid::non_negative(double pret) {
    return pret > 0;
}

bool Valid::non_vid(const std::string& x) {
    if (!x.empty()) return true;
    else return false;
}

void Valid::validProdus(std::string& nume, std::string& tip, double pret, std::string& producator) {
    string errori;

    if (!non_vid(nume)) errori.append("Nume invalid!\n");
    if (!non_vid(tip)) errori.append("Tip invalid!\n");
    if (!non_negative(pret)) errori.append("Pret invalid!\n");
    if (!non_vid(producator)) errori.append("Producator invalid!\n");

    if (!errori.empty()) throw Exception(errori);
}


void test_vid(Valid valid) {
    assert(valid.non_vid("abc") == true);
    assert(valid.non_vid("2314") == true);
    assert(valid.non_vid("dada") == true);
    assert(valid.non_vid("") == false);
}

void test_negative(Valid valid) {
    assert(valid.non_negative(23) == true);
    assert(valid.non_negative(1000) == true);
    assert(valid.non_negative(1) == true);
    assert(valid.non_negative(-23) == false);
}

void teste_validare(Valid valid) {
    test_negative(valid);
    test_vid(valid);
}