#include "CosProduse.h"
#include <random>
#include <algorithm>

void CosProduse::adaugaProdusCos(const Produs &p) {
    cosProduse.push_back(p);
}

void CosProduse::adaugaRandomProdusCos(vector<Produs> produse, int nr) {
    //std::mt19937 mt{ std::random_device{}() };
    //std::uniform_int_distribution<> dist(0, produse.size()-1);
    //int rndNR = dist(mt);

    shuffle(produse.begin(), produse.end(), std::default_random_engine(std::random_device{}()));
    while (cosProduse.size() < nr && !produse.empty()) {
        cosProduse.push_back(produse.back());
        produse.pop_back();
    }
}

const vector<Produs> &CosProduse::getAllCos() {
    return cosProduse;
}

void CosProduse::stergeCos() {
    cosProduse.clear();
}

