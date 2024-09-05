#ifndef LAB6_REPO_H
#define LAB6_REPO_H

//#include <vector>
#include "vector.h"
#include "produs.h"
#include <string>

//using std::vector;
using std::string;

class RepoException {
    string msg;
public:
    explicit RepoException(string m): msg{m} {
    }

    string getMsg() {
        return msg;
    }
};

class RepoProdus {
private:
    Vector<Produs> produse;
public:
    RepoProdus() = default;

    /**
     * Adauga un produs in lista de produse
     * @param produs - produsul adaugat
     */
    void store(const Produs& produs);

    /**
     * Sterge un produs din lista de produse
     * @param nume - numele produsului pe care il stergem
     * @param tip - tipul produsului pe care il stergem
     * @param producator - producatorul produsului pe care il stergem
     */
    void del(const string& nume, const string& tip, const string& producator);

    /**
     * Modifica un produs din lista de produse
     * @param produs - produsul care se modifica
     * @param produsNou - produsul nou
     */
    void modify(Produs& produs, Produs& produsNou);

    /**
     * Functie care cauta un produs si il returneaza
     * @param nume - numele produsului pe care il stergem
     * @param tip - tipul produsului pe care il stergem
     * @param producator - producatorul produsului pe care il stergem
     */
    Produs cauta(const string& nume, const string& tip, const string& producator);

    /**
     * Functie de sortare pe un anumit criteriu si mod(crescator, descrescator)
     * @param produseSortate - lista de produse pe care o sortam
     * @param criteriu - 1 - Dupa nume
     *                 - 2 - Dupa pret
     *                 - 3 - Dupa nume+tip
     * @param mod
     */
    void sortare(RepoProdus& produseSortate, int criteriu, int mod);

    /**
     * Functii ce returneaza o lista de produse filtrata dupa un anumit criteriu
     * @param produseFiltrate - lista filtrata
     * @param nume, tip, pret, producator - criterii
     */
    void filtrareNume(RepoProdus& produseFiltrate, const string& nume);
    void filtrareTip(RepoProdus& produseFiltrate, const string& tip);
    void filtrarePret(RepoProdus& produseFiltrate, const double& pret);
    void filtrareProducator(RepoProdus& produseFiltrate, const string& producator);

    /**
     * Functie getter
     * @return - un vector cu toate produsele
     */
    Vector<Produs> getAll() {
        return produse;
    }
};

void testeREPO();

#endif //LAB6_REPO_H
