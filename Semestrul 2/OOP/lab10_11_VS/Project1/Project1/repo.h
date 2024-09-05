#pragma once

//#include <vector>
#include "produs.h"
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_map>


using std::vector;
using std::string;

class RepoException {
    string msg;
public:
    explicit RepoException(string m) : msg{ std::move(m) } {
    }

    string getMsg() {
        return msg;
    }
};


class RepoAbstract {
public:
    RepoAbstract() = default;

    RepoAbstract(RepoAbstract& repo) = delete;

    virtual void store(const Produs& produs) = 0;

    virtual void modify(Produs& produs, Produs& produsNou) = 0;

    virtual void del(const Produs& produs) = 0;

    virtual Produs& cauta(const string& nume, const string& tip, const string& producator) = 0;

    virtual vector<Produs>& getAll() = 0;
};


class RepoProdus : public RepoAbstract {
private:
    vector<Produs> produse;
public:
    RepoProdus() = default;

    bool exist(const Produs& produs);

    /**
     * Adauga un produs in lista de produse
     * @param produs - produsul adaugat
     */
    void store(const Produs& produs) override;

    /**
     * Sterge un produs din lista de produse
     * @param nume - numele produsului pe care il stergem
     * @param tip - tipul produsului pe care il stergem
     * @param producator - producatorul produsului pe care il stergem
     */
    void del(const Produs& produs) override;

    /**
     * Modifica un produs din lista de produse
     * @param produs - produsul care se modifica
     * @param produsNou - produsul nou
     */
    void modify(Produs& produs, Produs& produsNou) override;

    /**
     * Functie care cauta un produs si il returneaza
     * @param nume - numele produsului pe care il stergem
     * @param tip - tipul produsului pe care il stergem
     * @param producator - producatorul produsului pe care il stergem
     */
    Produs& cauta(const string& nume, const string& tip, const string& producator) override;

    /**
     * Functie getter
     * @return - un vector cu toate produsele
     */
    vector<Produs>& getAll() override {
        return produse;
    }
};

class LabRepo : public RepoAbstract {
private:
    std::unordered_map<int, Produs> produse;
    double probabilitate;

    bool exist(const Produs& produs);

public:
    LabRepo() = default;

    void random() const;

    void setProbabilitate(double prob);

    /**
     * Adauga un produs in lista de produse
     * @param produs - produsul adaugat
     */
    void store(const Produs& produs) override;

    /**
     * Sterge un produs din lista de produse
     * @param nume - numele produsului pe care il stergem
     * @param tip - tipul produsului pe care il stergem
     * @param producator - producatorul produsului pe care il stergem
     */
    void del(const Produs& produs) override;

    /**
     * Modifica un produs din lista de produse
     * @param produs - produsul care se modifica
     * @param produsNou - produsul nou
     */
    void modify(Produs& produs, Produs& produsNou) override;

    /**
     * Functie care cauta un produs si il returneaza
     * @param nume - numele produsului pe care il stergem
     * @param tip - tipul produsului pe care il stergem
     * @param producator - producatorul produsului pe care il stergem
     */
    Produs& cauta(const string& nume, const string& tip, const string& producator) override;

    /**
     * Functie getter
     * @return - un vector cu toate produsele
     */
    vector<Produs>& getAll() override;
};



class RepoProdusFile : public RepoProdus {
private:
    string filename;
    void loadFromFile();
    void writeToFile();

public:
    explicit RepoProdusFile(string filename) : RepoProdus(), filename{ std::move(filename) } {
        loadFromFile();
    }

    void store(const Produs& produs) override {
        RepoProdus::store(produs);
        writeToFile();
    }

    void del(const Produs& produs) override {
        RepoProdus::del(produs);
        writeToFile();
    }
};


void testeREPO();
void testeLABREPO();
