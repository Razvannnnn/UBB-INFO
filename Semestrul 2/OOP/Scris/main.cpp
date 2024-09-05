#include <iostream>

using namespace std;

class Pizza {
private:
    int pret;
public:
    Pizza(int pret) : pret{ pret } {}
    virtual string descriere() = 0;
    int getPret() {
        return pret;
    }
    ~Pizza() = default;
};

class PizzaCuPeperoni: public Pizza {
private:
    Pizza* pizza;
public:
    PizzaCuPeperoni(Pizza* pizza): Pizza{pizza->getPret()}, pizza{ pizza } {}
    string descriere() override {
        return pizza->descriere() + "cu peperoni";
    }
    int getPret() {
        return pizza->getPret() + 3;
    }
    ~PizzaCuPeperoni() = default;
};



#include <vector>

template <typename TElem>

class Catalog {
private:
    string materie;
    vector<TElem> note;
public:
    Catalog(string materie) : materie{materie} {}
    Catalog & operator + (TElem nota) {
        note.push_back(nota);
        return *this;
    }
    typename vector<TElem>::iterator begin() {
        return note.begin();
    }
    typename vector<TElem>::iterator end() {
        return note.end();
    }
    ~Catalog() = default;
};

void catalog() {
    Catalog<int> cat{ "OOP" };//creaza catalog cu note intregi
    cat + 10; //adauga o nota in catalog
    cat = cat + 8 + 6;
    int sum = 0;
    for (auto n : cat) { sum += n; } //itereaza notele din catalog
    std::cout << "Suma note:" << sum << "\n";
}

int main() {
    catalog();
}












