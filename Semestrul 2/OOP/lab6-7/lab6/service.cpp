#include "service.h"

#include <utility>
#include <cassert>

void serviceProdus::adaugare(std::string nume, std::string tip, double pret, std::string producator) {
    Valid::validProdus(nume, tip, pret, producator);
    Produs p{std::move(nume), std::move(tip), pret, std::move(producator)};
    repo.store(p);
}

void serviceProdus::modificare(std::string nume, std::string tip, double pret, std::string producator,
                               std::string newnume, std::string newtip, double newpret, std::string newproducator) {
    Valid::validProdus(nume, tip, pret, producator);
    Valid::validProdus(newnume, newtip, newpret, newproducator);
    Produs p{std::move(nume), std::move(tip), pret, std::move(producator)};
    Produs p2{std::move(newnume), std::move(newtip), newpret, std::move(newproducator)};
    repo.modify(p, p2);

}

void serviceProdus::stergere(const std::string& nume, const std::string& tip, const std::string& producator) {
    repo.del(nume, tip, producator);
}

Produs serviceProdus::cauta(const std::string &nume, const std::string &tip, const std::string &producator) {
    return repo.cauta(nume, tip, producator);
}

RepoProdus serviceProdus::sortare(int criteriu, int mod) {
    RepoProdus produseSortate;
    produseSortate = repo;
    repo.sortare(produseSortate, criteriu, mod);
    return produseSortate;}

RepoProdus serviceProdus::fltrareUnCriteriu(const int& criteriu, const string& nume, const string& tip, double pret, const string& producator) {
    RepoProdus produseFiltrate ;
    if(criteriu == 1) {
        repo.filtrareNume(produseFiltrate, nume);
    }
    else if(criteriu == 2) {
        repo.filtrareTip(produseFiltrate, tip);
    }
    else if(criteriu == 3) {
        repo.filtrarePret(produseFiltrate, pret);
    }
    else if(criteriu == 4) {
        repo.filtrareProducator(produseFiltrate, producator);
    }
    return produseFiltrate;}

void testServiceAdaugare() {
    RepoProdus repo;
    serviceProdus service{ repo };
    service.adaugare("Apa", "Minerala", 2.99, "Bucovina");
    assert(service.getAll().size() == 1);
}

void testServiceStergere() {
    RepoProdus repo;
    serviceProdus service{ repo };
    service.adaugare("Apa", "Minerala", 2.99, "Bucovina");
    assert(service.getAll().size() == 1);
    service.stergere("Apa", "Minerala", "Bucovina");
    assert(service.getAll().size() == 0);
}

void testServiceModificare() {
    RepoProdus repo;
    serviceProdus service{ repo };
    service.adaugare("Apa", "Minerala", 2.99, "Bucovina");
    assert(service.getAll().size() == 1);
    service.modificare("Apa", "Minerala", 2.99, "Bucovina", "Apa", "Plata", 4.99, "NotBucovina");
    assert(service.getAll().size() == 1);
    Vector<Produs> updatedproduse = service.getAll();
    assert(updatedproduse[0].getNume() == "Apa");
    assert(updatedproduse[0].getTip() == "Plata");
    assert(updatedproduse[0].getPret() == 4.99);
    assert(updatedproduse[0].getProducator() == "NotBucovina");
}

void testServiceFiltrare() {
    RepoProdus repo;
    RepoProdus listaFiltrata;
    serviceProdus service{ repo };
    service.adaugare("Apa", "Minerala", 2.99, "Bucovina");
    service.adaugare("Apa", "Plata", 3.99, "Bucovina");
    service.adaugare("Apa", "Plata", 3.29, "Aqua Carpatica");
    assert(service.getAll().size() == 3);

    listaFiltrata = service.fltrareUnCriteriu(1, "Apa", "", 0, "");
    assert(listaFiltrata.getAll().size() == 3);

    listaFiltrata = {};
    listaFiltrata = service.fltrareUnCriteriu(2, "", "Plata", 0, "");
    assert(listaFiltrata.getAll().size() == 2);

    listaFiltrata = {};
    listaFiltrata = service.fltrareUnCriteriu(3, "", "", 2.99, "");
    assert(listaFiltrata.getAll().size() == 1);

    listaFiltrata = {};
    listaFiltrata = service.fltrareUnCriteriu(4, "", "", 0, "Bucovina");
    assert(listaFiltrata.getAll().size() == 2);
}

void testServiceCauta() {
    RepoProdus repo;
    serviceProdus service{ repo };
    service.adaugare("Apa", "Minerala", 2.99, "Bucovina");
    assert(service.getAll().size() == 1);
    auto p = service.cauta("Apa", "Minerala", "Bucovina");
    assert(p.getNume() == "Apa");
    assert(p.getTip() == "Minerala");
    assert(p.getProducator() == "Bucovina");
}

void testServiceSortare() {
    RepoProdus repo;
    RepoProdus listaSortate;
    serviceProdus service{ repo };
    service.adaugare("Apa", "Minerala", 2.99, "Bucovina");
    service.adaugare("Apa", "Plata", 3.99, "Bucovina");
    service.adaugare("Apa", "Plata", 3.29, "Aqua Carpatica");
    assert(service.getAll().size() == 3);
    listaSortate = service.sortare(2, 1);
    auto produse = listaSortate.getAll();
    assert(produse[0].getPret() == 2.99);
}

void testeService() {
    testServiceAdaugare();
    testServiceStergere();
    testServiceModificare();
    testServiceFiltrare();
    testServiceCauta();
    testServiceSortare();
}