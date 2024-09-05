#ifndef LAB6_SERVICE_H
#define LAB6_SERVICE_H

#include <string>
#include "repo.h"
#include "produs.h"
#include "vector.h"
#include "validare.h"

using std::string;

class serviceProdus {
private:
    RepoProdus& repo;
    Valid validare;
public:
    explicit serviceProdus(RepoProdus& repo): repo{ repo } {
    }

    serviceProdus() = default;

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
     * @param producator - producatorul produsului
     */
    void stergere(const string& nume, const string& tip, const string& producator);

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
    Produs cauta(const string& nume, const string& tip, const string& producator);

    /**
     * Functie care returneaza lista sortata dupa un criteriu
     * @param criteriu
     * @param mod
     * @return
     */
    RepoProdus sortare(int criteriu, int mod);

    /**
     * Functie care filtreaza produsele dupa un criteriu
     * @param criteriu - 1 - Nume
     *                 - 2 - Tip
     *                 - 3 - Pret
     *                 - 4 - Producator
     * Returneaza o lista cu produsele filtrate
     */
    RepoProdus fltrareUnCriteriu(const int& criteriu, const string& nume, const string& tip, double pret, const string& producator);

    /**
     * Getter care returneaza un vector cu lista de produse
     * @return - lista produse
     */
    Vector<Produs> getAll() {
        return repo.getAll();
    }
};

void testeService();

#endif //LAB6_SERVICE_H
