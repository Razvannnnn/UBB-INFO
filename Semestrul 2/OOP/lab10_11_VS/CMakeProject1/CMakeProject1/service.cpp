#include "service.h"

#include <utility>
#include <algorithm>
#include <cassert>
#include <vector>
#include <fstream>

void serviceProdus::adaugare(std::string nume, std::string tip, double pret, std::string producator) {
    Valid::validProdus(nume, tip, pret, producator);
    Produs p{ std::move(nume), std::move(tip), pret, std::move(producator) };
    repo.store(p);
    undoAct.push_back(std::make_unique<UndoAdauga>(repo, p));
}

void serviceProdus::modificare(std::string nume, std::string tip, double pret, std::string producator,
    std::string newnume, std::string newtip, double newpret, std::string newproducator) {
    Valid::validProdus(nume, tip, pret, producator);
    Valid::validProdus(newnume, newtip, newpret, newproducator);
    Produs p{ std::move(nume), std::move(tip), pret, std::move(producator) };
    Produs p2{ std::move(newnume), std::move(newtip), newpret, std::move(newproducator) };
    repo.modify(p, p2);
    undoAct.push_back(std::make_unique<UndoModifica>(repo, p2, p));
}

void serviceProdus::stergere(std::string nume, std::string tip, double pret, std::string producator) {
    Valid::validProdus(nume, tip, pret, producator);
    Produs p{ std::move(nume), std::move(tip), pret, std::move(producator) };
    repo.del(p);
    undoAct.push_back(std::make_unique<UndoSterge>(repo, p));
}

Produs& serviceProdus::cauta(const std::string& nume, const std::string& tip, const std::string& producator) {
    return repo.cauta(nume, tip, producator);
}

vector<Produs> serviceProdus::filtrareNume(const string& nume) {
    const vector<Produs>& produse = getAll();
    vector<Produs> filtrate;
    std::copy_if(produse.begin(), produse.end(), std::back_inserter(filtrate), [&](const Produs& p) {
        return p.getNume() == nume;
        });
    return (filtrate);
}

vector<Produs> serviceProdus::filtrareTip(const string& tip) {
    const vector<Produs>& produse = getAll();
    vector<Produs> filtrate;
    std::copy_if(produse.begin(), produse.end(), std::back_inserter(filtrate), [&](const Produs& p) {
        return p.getTip() == tip;
        });
    return (filtrate);
}

vector<Produs> serviceProdus::filtrarePret(double pret) {
    const vector<Produs>& produse = getAll();
    vector<Produs> filtrate;
    std::copy_if(produse.begin(), produse.end(), std::back_inserter(filtrate), [&](const Produs& p) {
        return p.getPret() == pret;
        });
    return (filtrate);
}

vector<Produs> serviceProdus::filtrareProducator(const string& producator) {
    const vector<Produs>& produse = getAll();
    vector<Produs> filtrate;
    std::copy_if(produse.begin(), produse.end(), std::back_inserter(filtrate), [&](const Produs& p) {
        return p.getProducator() == producator;
        });
    return (filtrate);
}

vector<Produs> serviceProdus::sortNume() {
    vector<Produs> sortat{ repo.getAll() };
    sort(sortat.begin(), sortat.end(), cmpNume);
    return sortat;
}

vector<Produs> serviceProdus::sortPret() {
    vector<Produs> sortat{ repo.getAll() };
    sort(sortat.begin(), sortat.end(), cmpPret);
    return sortat;
}

vector<Produs> serviceProdus::sortNumeTip() {
    vector<Produs> sortat{ repo.getAll() };
    sort(sortat.begin(), sortat.end(), cmpNumeTip);
    return sortat;
}


void serviceProdus::cosAdauga(const string& nume, const string& tip, const string& producator) {
    const auto& produs = repo.cauta(nume, tip, producator);
    cosCurent.adaugaProdusCos(produs);
}

int serviceProdus::cosAdaugaRandom(int nr) {
    cosCurent.adaugaRandomProdusCos(this->getAll(), nr);
    return cosCurent.getAllCos().size();
}

void serviceProdus::cosSterge() {
    cosCurent.stergeCos();
}

const vector<Produs>& serviceProdus::getAllCos() {
    return cosCurent.getAllCos();
}

void serviceProdus::cosExport(const string& filename) {
    if (filename.find(".csv") == std::string::npos && filename.find(".html") == std::string::npos) {
        throw Exceptie("Fisierul nu este valid!\n");
    }
    else {
        std::ofstream fout(filename);
        if (filename.find(".html") != std::string::npos) {
            fout << "<html>";
            fout << "<style> table, th, td {border:1px solid black} body{background-color: #aad188;} </style>";
            fout << "<body>";
            fout << "<h1> COS CUMPARATURI </h1>";
            fout << "<table><tr><th>Nume</th> <th>Tip</th> <th>Pret</th> <th>Producator</th></tr>";
            for (auto& o : getAllCos()) {
                fout << "<tr><td>" << o.getNume() << "<td>" << o.getTip() << "</td><td>" << o.getPret() << "</td><td>" << o.getProducator() << "</td></tr>";
            }
            fout << "</table></body>";
            fout << "<html>";
        }
        else {
            for (auto& o : getAllCos()) {
                fout << o.getNume() << ";" << o.getTip() << ";" << o.getPret() << ";" << o.getProducator() << "\n";
            }
        }
        fout.close();
    }
}

unordered_map<string, int> serviceProdus::raportTip() {
    unordered_map<string, int> map;
    vector<Produs> produse = repo.getAll();
    for (auto& p : produse) {
        if (map.find(p.getTip()) != map.end()) {
            map[p.getTip()]++;
        }
        else {
            map[p.getTip()] = 1;
        }
    }
    return map;
}

void serviceProdus::undo() {
    if (undoAct.empty()) {
        throw Exceptie("Nu se mai poate efectua operatia de undo");
    }
    undoAct.back()->doUndo();
    undoAct.pop_back();
}

void testServiceRaport() {
    RepoProdus repo;
    CosProduse cos;
    serviceProdus service{ repo, cos };
    service.adaugare("Apa", "Minerala", 2.99, "Bucovina");
    service.adaugare("Apa", "Plata", 3.99, "Bucovina");
    service.adaugare("Apa", "Plata", 3.29, "Aqua Carpatica");
    auto map = service.raportTip();
    assert(map.size() == 2);
}

void testServiceAdaugare() {
    RepoProdus repo;
    CosProduse cos;
    serviceProdus service{ repo, cos };
    service.adaugare("Apa", "Minerala", 2.99, "Bucovina");
    assert(service.getAll().size() == 1);
}

void testServiceStergere() {
    RepoProdus repo;
    CosProduse cos;
    serviceProdus service{ repo, cos };
    service.adaugare("Apa", "Minerala", 2.99, "Bucovina");
    assert(service.getAll().size() == 1);
    service.stergere("Apa", "Minerala", 2.99, "Bucovina");
    assert(service.getAll().empty());
}

void testServiceModificare() {
    RepoProdus repo;
    CosProduse cos;
    serviceProdus service{ repo, cos };
    service.adaugare("Apa", "Minerala", 2.99, "Bucovina");
    assert(service.getAll().size() == 1);
    service.modificare("Apa", "Minerala", 2.99, "Bucovina", "Apa", "Plata", 4.99, "NotBucovina");
    assert(service.getAll().size() == 1);
    vector<Produs> updatedproduse = service.getAll();
    assert(updatedproduse[0].getNume() == "Apa");
    assert(updatedproduse[0].getTip() == "Plata");
    assert(updatedproduse[0].getPret() == 4.99);
    assert(updatedproduse[0].getProducator() == "NotBucovina");
}

void testServiceFiltrare() {
    RepoProdus repo;
    CosProduse cos;
    vector<Produs> listaFiltrata;
    serviceProdus service{ repo, cos };
    service.adaugare("Apa", "Minerala", 2.99, "Bucovina");
    service.adaugare("Apa", "Plata", 3.99, "Bucovina");
    service.adaugare("Apa", "Plata", 3.29, "Aqua Carpatica");
    assert(service.getAll().size() == 3);

    listaFiltrata = service.filtrareNume("Apa");
    assert(listaFiltrata.size() == 3);
    listaFiltrata = service.filtrareTip("Plata");
    assert(listaFiltrata.size() == 2);
    listaFiltrata = service.filtrarePret(2.99);
    assert(listaFiltrata.size() == 1);
    listaFiltrata = service.filtrareProducator("Bucovina");
    assert(listaFiltrata.size() == 2);
}

void testServiceCauta() {
    RepoProdus repo;
    CosProduse cos;
    serviceProdus service{ repo, cos };
    service.adaugare("Apa", "Minerala", 2.99, "Bucovina");
    assert(service.getAll().size() == 1);
    auto p = service.cauta("Apa", "Minerala", "Bucovina");
    assert(p.getNume() == "Apa");
    assert(p.getTip() == "Minerala");
    assert(p.getProducator() == "Bucovina");
}

void testServiceSortare() {
    RepoProdus repo;
    CosProduse cos;
    vector<Produs> listaSortate;
    serviceProdus service{ repo, cos };
    service.adaugare("Apa", "Minerala", 2.99, "Bucovina");
    service.adaugare("Apa", "Plata", 3.99, "Bucovina");
    service.adaugare("Apa", "Plata", 3.29, "Aqua Carpatica");
    assert(service.getAll().size() == 3);
    listaSortate = service.sortPret();
    auto produse = listaSortate;
    assert(produse[0].getPret() == 2.99);
    listaSortate = service.sortNume();
    produse = listaSortate;
    assert(produse[0].getNume() == "Apa");
    listaSortate = service.sortNumeTip();
    produse = listaSortate;
    assert(produse[0].getTip() == "Minerala");
    service.adaugare("AA", "Minerala", 2.99, "Bucovina");
    listaSortate = service.sortNumeTip();
    produse = listaSortate;
    assert(produse[0].getNume() == "AA");
}

void testService_constr() {
    Produs produs;
    assert(produs.getPret() == 0);
    assert(produs.getNume().empty());
    assert(produs.getTip().empty());
    assert(produs.getProducator().empty());
}

void testCos() {
    RepoProdus repo;
    CosProduse cos;
    serviceProdus service{ repo, cos };
    service.adaugare("Apa", "Minerala", 2.99, "Bucovina");
    service.adaugare("Apa", "Plata", 3.99, "Bucovina");
    service.adaugare("Apa", "Plata", 3.29, "Aqua Carpatica");

    service.cosAdauga("Apa", "Minerala", "Bucovina");
    service.cosAdauga("Apa", "Plata", "Aqua Carpatica");
    assert(service.getAllCos().size() == 2);
    try {
        service.cosAdauga("abc", "abc", "abc");
    }
    catch (RepoException& e) {
        assert(true);
    }
    service.cosSterge();
    service.cosAdaugaRandom(3);
    assert(service.getAllCos().size() == 3);

    string fis_csv = R"(C:\Users\razva\Desktop\OOP\lab8_9\test.csv)";
    string fis_html = R"(C:\Users\razva\Desktop\OOP\lab8_9\test.html)";
    string fis_dif = R"(C:\Users\razva\Desktop\OOP\lab8_9\test.txt)";

    service.cosExport(fis_csv);
    service.cosExport(fis_html);
    try {
        service.cosExport(fis_dif);
    }
    catch (Exceptie& e) {
        assert(e.getMsg() == "Fisierul nu este valid!\n");
        assert(true);
    }
}

void test_undo() {
    RepoProdus repo;
    CosProduse cos;
    serviceProdus service{ repo, cos };
    try {
        service.undo();
    }
    catch (Exceptie ex) {
        assert(true);
    }
    service.adaugare("Apa", "Minerala", 2.99, "Bucovina");
    service.adaugare("Apa", "Plata", 3.99, "Bucovina");
    service.adaugare("Apa", "Plata", 3.29, "Aqua Carpatica");
    assert(service.getAll().size() == 3);
    service.stergere("Apa", "Plata", 3.29, "Aqua Carpatica");
    assert(service.getAll().size() == 2);
    service.undo();
    assert(service.getAll().size() == 3);
    service.undo();
    assert(service.getAll().size() == 2);
    service.modificare("Apa", "Minerala", 2.99, "Bucovina", "Apa", "Plata", 2.59, "Aquavia");
    assert(service.getAll().size() == 2);
    service.undo();
    assert(service.getAll().size() == 2);
    service.undo();
    try {
        repo.cauta("Apa", "Plata", "Bucovina");
    }
    catch (RepoException ex) {
        assert(true);
    }
    service.undo();
    assert(service.getAll().empty());
}

/*
void testFILE() {
    RepoProdusFile repo{"C:\\Users\\razva\\Desktop\\OOP\\lab8_9\\test.txt"};
    CosProduse cos;
    serviceProdus service{ repo, cos};
    assert(service.getAll().size() == 2);
    service.adaugare("z", "z", 10, "z");
    assert(service.getAll().size() == 3);
    service.stergere("z", "z", 10, "z");
}
 */

void testeService() {
    testServiceAdaugare();
    testServiceStergere();
    testServiceModificare();
    testServiceFiltrare();
    testServiceCauta();
    testServiceSortare();
    testService_constr();
    testCos();
    testServiceRaport();
    test_undo();
    //testFILE();
}