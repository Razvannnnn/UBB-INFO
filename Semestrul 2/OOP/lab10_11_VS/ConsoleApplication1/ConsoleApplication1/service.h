#pragma once


#include <string>
#include <algorithm>
#include "repo.h"
#include "produs.h"
#include "vector.h"
#include "validare.h"
#include "CosProduse.h"
#include "Error.h"
#include "undo.h"
#include <unordered_map>
#include <memory>

using std::string;

class serviceProdus {
private:
    RepoAbstract& repo;
    CosProduse& cosCurent;
    Valid validare;
    vector<std::unique_ptr<ActiuneUndo>> undoAct;
public:
    explicit serviceProdus(class RepoAbstract& repo, CosProduse& cosCurent) : repo{ repo }, cosCurent{ cosCurent } {
    }

    serviceProdus() = delete;

    /**
     * Adauga un produs in lista de produse
     * @param nume - numele produsului
     * @param tip - tipul produsului
     * @param pret - pretul produsului
     * @param producator - producatorul produsului
     */
    void adaugare(string nume, string tip, double pret, string producator);

    /**
     * Sterge un produs din lista de produse
     * @param nume - numele produsului
     * @param tip - tipul produsului
     * @param pret - pretul produsului
     * @param producator - producatorul produsului
     */
    void stergere(string nume, string tip, double pret, string producator);

    /**
     * Modifica un produs din lista de produse
     * @param nume - numele produsului pe care il schimbam
     * @param tip - tipul produsului pe care il schimbam
     * @param pret - pretul produsului pe care il schimbam
     * @param producator - producatorul produslui pe care il schimbam
     * @param numeNou - numele produsului nou
     * @param tipNou - tipul produsului nou
     * @param pretNou - pretul produsului nou
     * @param producatorNou - producatorul produslui nou
     */
    void modificare(string nume, string tip, double pret, string producator,
        string numeNou, string tipNou, double pretNou, string producatorNou);

    /**
     * Functie care cauta un produs si il returneaza
     * @param nume - numele produsului
     * @param tip - tipul produsului
     * @param producator - producatorul produsului
     */
    Produs& cauta(const string& nume, const string& tip, const string& producator);


    /**
     * Functii de sortare
     * @return o lista de tip vector
     */
    vector<Produs> sortNume();
    vector<Produs> sortPret();
    vector<Produs> sortNumeTip();

    /**
     * Functie de filtrare in functie de nume
     * @param nume
     * @return
     */
    vector<Produs> filtrareNume(const string& nume);

    /**
     * Functie de filtrare in functie de tip
     * @param tip
     * @return
     */
    vector<Produs> filtrareTip(const string& tip);

    /**
     * Functie de filtrare in functie de pret
     * @param pret
     * @return
     */
    vector<Produs> filtrarePret(double pret);

    /**
     * Functie de filtrare in functie de producator
     * @param producator
     * @return
     */
    vector<Produs> filtrareProducator(const string& producator);

    /**
     * Getter care returneaza un vector cu lista de produse
     * @return - lista produse
     */
    vector<Produs>& getAll() {
        return repo.getAll();
    }

    /**
     * Returneaza nr de produse de tipul tip
     * @return
     */
    unordered_map<string, int> raportTip();

    /**
     * Adauga un produs cu numele nume, de tipul tip si cu producatorul producator in cos
     * @param nume
     * @param tip
     * @param producator
     */
    void cosAdauga(const string& nume, const string& tip, const string& producator);

    /**
     * Adauga un numar random de produse in cos
     * @param nr
     * @return
     */
    int cosAdaugaRandom(int nr);

    /**
     * Goleste produsele din cos
     */
    void cosSterge();

    /**
     * Returneaza toate produsele din cos
     * @return
     */
    const vector<Produs>& getAllCos();

    /**
     * Exporta tot cosul intr un fisier dat ca parametru
     * @param filename - calea catre fisier
     */
    void cosExport(const string& filename);

    /**
     * Realizeaza operatia de undo
     */
    void undo();
};

void testeService();
