#include "repo.h"
#include <cassert>
#include <iostream>
#include <exception>
#include <functional>
#include <algorithm>
#include <fstream>

bool RepoProdus::exist(const Produs& produs) {
    try {
        cauta(produs.getNume(), produs.getTip(), produs.getProducator());
        return true;
    }
    catch (RepoException&) {
        return false;
    }
}

void RepoProdus::store(const Produs& produs) {
    if (exist(produs)) {
        throw RepoException("Produsul exista deja in lista!\n");
    }
    else {
        produse.push_back(produs);
    }
}

void RepoProdus::modify(Produs& produs, Produs& produsNou) {
    if (!exist(produs)) {
        throw RepoException("Produsul nu exista in lista!\n");
    }
    else {
        for (Produs& p : produse) {
            if (p.getNume() == produs.getNume() && p.getTip() == produs.getTip() &&
                p.getProducator() == produs.getProducator() && p.getPret() == produs.getPret()) {
                p.setNume(produsNou.getNume());
                p.setProducator(produsNou.getProducator());
                p.setTip(produsNou.getTip());
                p.setPret(produsNou.getPret());
            }
        }
    }
}

void RepoProdus::del(const Produs& produs) {
    if (!exist(produs)) {
        throw RepoException("Produsul nu exista in lista!\n");
    }
    else {
        int i = 0;
        while (i < produse.size()) {
            if (produse[i].getNume() == produs.getNume() && produse[i].getProducator() == produs.getProducator() && produse[i].getTip() == produs.getTip()) {
                produse.erase(produse.begin() + i);
            }
            i++;
        }
    }
}

Produs& RepoProdus::cauta(const std::string& nume, const std::string& tip, const std::string& producator) {
    auto p = std::find_if(produse.begin(), produse.end(), [&](const Produs& produs) {
        return (produs.getNume() == nume && produs.getTip() == tip && produs.getProducator() == producator);
        });
    if (p != produse.end()) {
        return *p;
    }
    else {
        throw RepoException("Produsul nu exista!\n");
    }
}

void RepoProdusFile::loadFromFile() {
    std::ifstream fin(filename);
    if (!fin.is_open()) throw RepoException("Eroare la deschiderea fisierului!\n");
    while (!fin.eof()) {
        string nume, tip, producator;
        double pret;
        if (fin.eof()) break;
        fin >> nume;
        if (fin.eof()) break;
        fin >> tip;
        if (fin.eof()) break;
        fin >> pret;
        if (fin.eof()) break;
        fin >> producator;
        Produs p(nume, tip, pret, producator);
        RepoProdus::store(p);
    }
    fin.close();
}

void RepoProdusFile::writeToFile() {
    std::ofstream fout(filename);
    if (!fout.is_open()) throw RepoException("Eroare la deschiderea fisierului!\n");
    for (auto& produs : RepoProdus::getAll()) {
        fout << produs.getNume() << "\n";
        fout << produs.getTip() << "\n";
        fout << produs.getPret() << "\n";
        fout << produs.getProducator() << "\n";
    }
    fout.close();
}







void testRepoAdaugare() {
    RepoProdus repo;
    Produs p{ "Apa", "Minerala", 2.99, "Bucovina" };
    repo.store(p);
    assert(repo.getAll().size() == 1);
    try {
        repo.store(p);
    }
    catch (RepoException&) {
        assert(true);
    }
}

void testRepoStergere() {
    RepoProdus repo;
    Produs p{ "Apa", "Minerala", 2.99, "Bucovina" };
    repo.store(p);
    assert(repo.getAll().size() == 1);
    repo.del(p);
    assert(repo.getAll().empty());
    try {
        repo.del(p);
    }
    catch (RepoException&) {
        assert(true);
    }
}

void testRepoModificare() {
    RepoProdus repo;
    Produs p{ "Apa", "Minerala", 2.99, "Bucovina" };
    repo.store(p);
    Produs p2{ "Apa", "Plata", 3.99, "Bucovina" };
    assert(repo.getAll().size() == 1);
    repo.modify(p, p2);
    vector<Produs> produse = repo.getAll();
    assert(repo.getAll().size() == 1);
    assert(produse[0].getNume() == "Apa");
    assert(produse[0].getTip() == "Plata");
    assert(produse[0].getPret() == 3.99);
    assert(produse[0].getProducator() == "Bucovina");
    try {
        repo.modify(p, p2);
    }
    catch (RepoException&) {
        assert(true);
    }
}

void testMSG() {
    std::string Mesaj = "Exemplu";
    RepoException repoException(Mesaj);
    std::string MesajAfisat = repoException.getMsg();
    assert(Mesaj == MesajAfisat);
}

void test_cauta() {
    RepoProdus repo;
    Produs p{ "Apa", "Minerala", 2.99, "Bucovina" };
    repo.store(p);
    assert(repo.getAll().size() == 1);
    auto prod = repo.cauta("Apa", "Minerala", "Bucovina");
    assert(prod.getNume() == "Apa");
    assert(prod.getTip() == "Minerala");
    assert(prod.getProducator() == "Bucovina");
    try {
        auto prod2 = repo.cauta("Apa", "Minerala", "Bucovin");
    }
    catch (RepoException&) {
        assert(true);
    }
}


void testFILErepoWrite() {
    RepoProdusFile repo{ "C:\\Users\\razva\\Desktop\\OOP\\lab8_9\\testFile.txt" };
    assert(repo.getAll().empty());
    Produs produs = { "z", "z", 10, "z" };
    repo.store(produs);
    assert(repo.getAll().size() == 1);
    repo.del(produs);
    assert(repo.getAll().empty());
}

void testFILErepoRead() {
    RepoProdusFile repo{ "C:\\Users\\razva\\Desktop\\OOP\\lab8_9\\test.txt" };
    assert(repo.getAll().size() == 2);
    Produs produs = { "z", "z", 10, "z" };
    repo.store(produs);
    assert(repo.getAll().size() == 3);
    repo.del(produs);
    assert(repo.getAll().size() == 2);
}


void testeREPO() {
    testRepoAdaugare();
    testRepoStergere();
    testRepoModificare();
    testMSG();
    test_cauta();
    testFILErepoWrite();
    testFILErepoRead();
}