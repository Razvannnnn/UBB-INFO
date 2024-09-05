#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Mancare {
private:
    int pret;
public:
    Mancare(int pret) : pret{ pret } {}
    virtual string descriere() = 0;
    virtual int getPret() {
        return pret;
    }
    ~Mancare() = default;
};

class CuCartof: public Mancare {
private:
    Mancare* mancare1;
public:
    CuCartof(Mancare* mancare) : Mancare{mancare->getPret()}, mancare1{ mancare } {}
    string descriere() override {
        return mancare1->descriere() + "cu cartof";
    }
    int getPret() override {
        return mancare1->getPret() + 3;
    }
};

class CuSos: public Mancare {
private:
    Mancare* mancare1;
private:
    CuSos(Mancare* mancare) : Mancare{mancare->getPret()}, mancare1{mancare} {}
    string descriere() override {
        return mancare1->descriere() + "cu sos";
    }
    int getPret() override {
        return mancare1->getPret() + 2;
    }
};

class Burger: public Mancare{
private:
    string nume;
public:
    Burger(int pret, string nume): Mancare{pret}, nume{nume} {}
    string descriere() override {
        return nume;
    }
};

vector<Mancare*> f() {
    vector<Mancare*> v;
    v.push_back(new Burger{10, "McPuisor"});
    v.push_back(new CuCartof{new Burger{10,"da"}});
}


template <typename TElem>

class Sesiune {
private:
    vector<string> participanti;
public:
    Sesiune(vector<string> participanti) : participanti{ participanti } {}
    Sesiune & operator + (string nume) {
        participanti.push_back(nume);
        return *this;
    }

};

class Conferinta {
private:
    map<string, Sesiune> sesiuni;
public:
    Sesiune & track(const string* nume) {
        return sesiuni[nume];
    }
};



int main() {
    Conferinta conf;
    //add 2 attendants to "Artifiial Inteligente" track
    conf.track("Artifiial Inteligente") + "Ion Ion" + "Vasile Aron";
    //add 2 attendants to "Software" track
    Sesiune s = conf.track("Software");
    s + "Anar Lior" + "Aurora Bran";
    //print all attendants from group "Artifiial Inteligente" track
    for (auto name : conf.track("Artifiial Inteligente")) {
        std::cout << name << ",";
    }
    //find and print all names from Software track that contains "ar"
    vector<string> v = conf.track("Software").select("ar");
    for (auto name : v) { std::cout << name << ","; }
}
