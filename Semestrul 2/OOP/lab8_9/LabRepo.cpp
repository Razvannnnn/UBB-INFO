#include "repo.h"
#include <stdlib.h>
#include <cassert>
#include <iostream>
#include <exception>
#include <functional>
#include <algorithm>
#include <fstream>


void LabRepo::random() const {
    double random = ((double) rand() / (RAND_MAX));
    if (random > probabilitate) {
        random *= 100;
        std::cout << "Probabilitatea: " << random <<" \n";
        throw RepoException("Nu se poate executa aceasta functie!\n");
    }
}

bool LabRepo::exist(const Produs &produs) {
    random();
    try {
        cauta(produs.getNume(), produs.getTip(), produs.getProducator());
        return true;
    }
    catch (RepoException &) {
        return false;
    }
}

void LabRepo::setProbabilitate(double prob) {
    probabilitate = prob;
}

void LabRepo::store(const Produs &p) {
    random();
    if (exist(p)) {
        throw RepoException("Produsul exista deja in lista.");
    }
    int poz = int(produse.size());
    produse.insert(std::make_pair(poz, p));
}


void LabRepo::modify(Produs &produs, Produs &produsNou) {
    random();
    if (!exist(produs)) {
        throw RepoException("Produsul nu exista in lista.");
    }
    int i=0;
    while (i < produse.size() && produse.at(i).getNume() != produs.getNume() &&
           produse.at(i).getTip() != produs.getTip() && produse.at(i).getProducator() != produs.getTip()) i++;
    if (i > produse.size()) throw RepoException("Produsul nu exista!");
    else {
        produse.at(i).setNume(produsNou.getNume());
        produse.at(i).setProducator(produsNou.getProducator());
        produse.at(i).setTip(produsNou.getTip());
        produse.at(i).setPret(produsNou.getPret());
    }
}


void LabRepo::del(const Produs &produs) {
    random();
    int i = 0;
    while (i < produse.size() && produse.at(i).getNume() != produs.getNume() &&
           produse.at(i).getTip() != produs.getTip() && produse.at(i).getProducator() != produs.getTip()) i++;
    if (i > produse.size()) throw RepoException("Produsul nu exista!");
    for (int j = i; j < produse.size() - 1; j++) {
        produse.at(j) = produse.at(j + 1);
    }
    produse.erase((int) produse.size() - 1);
}

Produs &LabRepo::cauta(const string& nume, const string& tip, const string& producator) {
    random();
    auto it = find_if(produse.begin(), produse.end(), [=](const std::pair<int, Produs> p) {
        return p.second.getNume() == nume && p.second.getTip() == tip && p.second.getProducator() == producator;
    });
    if (it == produse.end())
        throw RepoException("Produsul nu exista.");
    return (*it).second;
}

vector<Produs> ProduseVect;

vector<Produs> &LabRepo::getAll() {
    random();
    ProduseVect.clear();
    for (auto &p: produse) {
        ProduseVect.push_back(p.second);
    }
    return ProduseVect;
}


void testLabRepoAdaugare() {
    LabRepo repo;
    repo.setProbabilitate(1);
    Produs p{"Apa", "Minerala", 2.99, "Bucovina"};
    repo.store(p);
    assert(repo.getAll().size() == 1);
    try {
        repo.store(p);
    }
    catch (RepoException&) {
        assert(true);
    }
}

void testLabRepoStergere() {
    LabRepo repo;
    repo.setProbabilitate(1);
    Produs p{"Apa", "Minerala", 2.99, "Bucovina"};
    Produs p2{"Apa", "Plata", 3.19, "Aquavia"};
    repo.store(p);
    assert(repo.getAll().size() == 1);
    repo.store(p2);
    assert(repo.getAll().size() == 2);
    repo.del(p);
    assert(repo.getAll().size() == 1);
}

void testLabRepoModificare() {
    LabRepo repo;
    repo.setProbabilitate(1);
    Produs p{"Apa", "Minerala", 2.99, "Bucovina"};
    Produs p3{"Apa", "Plata", 1.99, "Kaufland"};
    repo.store(p);
    repo.store(p3);
    Produs p2{"Apa", "Plata", 3.99, "Bucovina"};
    assert(repo.getAll().size() == 2);
    repo.modify(p3, p2);
    vector<Produs> produse = repo.getAll();
    assert(repo.getAll().size() == 2);
    assert(produse[1].getNume() == "Apa");
    assert(produse[1].getTip() == "Plata");
    assert(produse[1].getPret() == 3.99);
    assert(produse[1].getProducator() == "Bucovina");
    try {
        repo.modify(p, p2);
    }
    catch (RepoException&) {
        assert(true);
    }
}


void testLab_cauta() {
    LabRepo repo;
    repo.setProbabilitate(1);
    Produs p{"Apa", "Minerala", 2.99, "Bucovina"};
    repo.store(p);
    assert(repo.getAll().size() == 1);
    auto prod = repo.cauta("Apa", "Minerala", "Bucovina");
    assert(prod.getNume() == "Apa");
    assert(prod.getTip() == "Minerala");
    assert(prod.getProducator() == "Bucovina");
    try {
        auto prod2 = repo.cauta("Apa", "Minerala", "Bucovin");}
    catch (RepoException&) {
        assert(true);
    }
}

void testRandom() {
    LabRepo repo;
    repo.setProbabilitate(0);
    try {
        repo.random();
    } catch (RepoException ex) {
        assert(true);
    }
}

void testeLABREPO() {
    testLabRepoAdaugare();
    testLabRepoStergere();
    testLabRepoModificare();
    testLab_cauta();
    testRandom();
}