#include <iostream>
#include <string>
#include <vector>
#include "algorithm"

using namespace std;



class Participant {
public:
    Participant() = default;
    virtual void tipareste() = 0;
    virtual bool eVoluntar() {
        return true;
    }
};

class Personal: public Participant {
private:
    string nume;
public:
    Personal(string nume) : nume{ nume } {}

    void tipareste() override {
        cout<<nume;
    }
};

class Director: public Personal {
public:
    Director(string nume) : Personal(nume) {
    }
    void tipareste() override {
        Personal::tipareste();
        cout<<" Director";
    }
};

class Administrator: public Personal {
public:
    Administrator(string nume) : Personal(nume) {}
    void tipareste() override {
        Personal::tipareste();
        cout<<" Administrator";
    }
};

class Angajat: public Participant {
private:
    Participant* p;
public:
    Angajat(Participant* part) : p{part} {}
    bool eVoluntar() override {
        return false;
    }
    void tipareste() override {
        p->tipareste();
        cout<<" angajat";
    }
};

class ONG {
private:
    vector<Participant*> v;
public:
    ONG() = default;
    void add(Participant* p) {
        v.push_back(p);
    }
    vector<Participant*> getAll(bool voluntar) {
        vector<Participant*> rez;
        if(voluntar) {
            for(auto &p : v) {
                if(p->eVoluntar() == voluntar) rez.push_back(p);
            }
        }
        return rez;
    }
};





template <typename TElem>

class Cos {
private:
    vector<TElem> v;
public:
    Cos& operator + (TElem elem) {
        v.push_back(elem);
        return *this;
    }
    Cos& undo() {
        if(v.size() > 0)
            v.pop_back();
        return *this;
    }
    void tipareste(ostream& out) {
        for(auto &e : v) {
            out<<e<<" ";
        }
    }
};











class Pizza {
private:
    int pret;
public:
    Pizza(int pret) : pret{pret} {}

    virtual int getPret() {
        return pret;
    }
    virtual string descriere() = 0;
    virtual ~Pizza() = default;
};

class PizzaCuPeperoni: public Pizza {
private:
    Pizza* piz;
public:
    PizzaCuPeperoni(Pizza* piz) : Pizza{piz->getPret()}, piz{piz} {}
    string descriere() override {
        return piz->descriere()+"cu peperoni";
    }
    int getPret() override {
        return piz->getPret()+2;
    }
    ~PizzaCuPeperoni() override {
        delete piz;
    }
};

class PizzaCuCiuperci: public Pizza {
private:
    Pizza* piz;
public:
    PizzaCuCiuperci(Pizza* piz) : Pizza{piz->getPret()}, piz{piz} {}
    string descriere() override {
        return piz->descriere() + "cu ciuperci";
    }
    int getPret() override {
        return piz->getPret()+3;
    }
    ~PizzaCuCiuperci() override {
        delete piz;
    }
};

class BasicPizza: public Pizza {
private:
    string denumire;
public:
    BasicPizza(int pret, string denumire): Pizza(pret), denumire(denumire) {
    }

    string descriere() override {
        return denumire;
    }
    ~BasicPizza() = default;
};

vector<Pizza*> f() {
    vector<Pizza*> v;
    v.push_back(new PizzaCuCiuperci(new BasicPizza(15,"Salami")));
    v.push_back(new BasicPizza(15, "Salami"));
    v.push_back(new PizzaCuCiuperci(new PizzaCuPeperoni(new BasicPizza(20, "Diavola"))));
    return v;
}

void fr() {
    vector<Pizza*> v = f();
    sort(v.begin(), v.end(), [&](Pizza* p1, Pizza* p2) {
        return p1->getPret() > p2->getPret();
    });
    for(auto &p : v) {
        cout<<p->descriere()<<" "<<p->getPret()<<"\n";
    }
}
template <typename TElem>


class Catalog {
private:
    vector<TElem> v;
    string materie;
public:
    Catalog(string materie) : materie(materie) {}
    Catalog & operator + (TElem nota) {
        v.push_back(nota);
        return *this;
    }
    typename vector<TElem>::iterator begin() {
        return v.begin();
    }
    typename vector<TElem>::iterator end() {
        return v.end();
    }
};

int main() {
    Catalog<int> cat{ "OOP" };//creaza catalog cu note intregi
    cat + 10; //adauga o nota in catalog
    cat = cat + 8 + 6;
    int sum = 0;
    for (auto n : cat) { sum += n; } //itereaza notele din catalog
    std::cout << "Suma note:" << sum << "\n";
}



















