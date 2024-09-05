#pragma once

#include "produs.h"
#include <vector>

using std::vector;

class CosProduse {
private:
    vector<Produs> cosProduse;
public:
    /**
     * Constructorul cosului
     */
    CosProduse() = default;

    void adaugaProdusCos(const Produs& p);

    void adaugaRandomProdusCos(vector<Produs> produse, int nr);

    const vector<Produs>& getAllCos();

    void stergeCos();
};

