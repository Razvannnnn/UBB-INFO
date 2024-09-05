#include "repo.h"
#include <cassert>

void RepoProdus::store(const Produs &produs) {
    for(const Produs& p : produse) {
        if(p.getNume() == produs.getNume() && p.getProducator() == produs.getProducator() && p.getTip() == produs.getTip()) {
            throw RepoException("Produsul deja exista!\n");
        }
    }
    produse.push_back(produs);
}

void RepoProdus::modify(Produs &produs, Produs& produsNou) {
    int ok=0;
    for(Produs& p : produse) {
        if(p.getNume() == produs.getNume() && p.getTip() == produs.getTip() && p.getProducator() == produs.getProducator() && p.getPret() == produs.getPret()) {
            p.setNume(produsNou.getNume());
            p.setProducator(produsNou.getProducator());
            p.setTip(produsNou.getTip());
            p.setPret(produsNou.getPret());
            ok=1;
        }
    }
    if(ok == 0) throw RepoException("Produsul nu exista!\n");
}

void RepoProdus::del(const std::string& nume, const std::string& tip, const std::string& producator) {
    int ok=0;
    for(int i=0;i<produse.size();i++) {
        if(produse[i].getNume() == nume && produse[i].getTip() == tip && produse[i].getProducator() == producator) {
            produse.erase(i);
            ok=1;
            break;
        }
    }
    if(ok==0) throw RepoException("Produsul nu exista!\n");
}

Produs RepoProdus::cauta(const std::string& nume, const std::string& tip, const std::string& producator) {
    for(const Produs& p : produse) {
        if(p.getNume() == nume && p.getProducator() == producator && p.getTip() == tip) {
            return p;
        }
    }
    throw RepoException("Produsul nu exista!\n");
}

void RepoProdus::sortare(RepoProdus &produseSortate, int criteriu, int mod) {
    if(mod == 1) {
        if(criteriu == 1) {
            int ok = 0;
            while(ok == 0) {
                ok = 1;
                for(int i=0;i<produseSortate.produse.size()-1;i++) {
                    if(produseSortate.produse[i].getNume() > produseSortate.produse[i+1].getNume()) {
                        Produs aux = produseSortate.produse[i];
                        produseSortate.produse[i] = produseSortate.produse[i+1];
                        produseSortate.produse[i+1] = aux;
                        ok = 0;
                    }
                }
            }
        }
        if(criteriu == 2) {
            int ok = 0;
            while(ok == 0) {
                ok = 1;
                for(int i=0;i<produseSortate.produse.size()-1;i++) {
                    if(produseSortate.produse[i].getPret() > produseSortate.produse[i+1].getPret()) {
                        Produs aux = produseSortate.produse[i];
                        produseSortate.produse[i] = produseSortate.produse[i+1];
                        produseSortate.produse[i+1] = aux;
                        ok = 0;
                    }
                }
            }
        }
        if(criteriu == 3) {
            int ok = 0;
            while(ok == 0) {
                ok = 1;
                for(int i=0;i<produseSortate.produse.size()-1;i++) {
                    if((produseSortate.produse[i].getNume() > produseSortate.produse[i+1].getNume()) || (produseSortate.produse[i].getNume() == produseSortate.produse[i+1].getNume() &&
                                                                                                         produseSortate.produse[i].getTip() > produseSortate.produse[i+1].getTip())) {
                        Produs aux = produseSortate.produse[i];
                        produseSortate.produse[i] = produseSortate.produse[i+1];
                        produseSortate.produse[i+1] = aux;
                        ok = 0;
                    }
                }
            }
        }
    } else {
        if(criteriu == 1) {
            int ok = 0;
            while(ok == 0) {
                ok = 1;
                for(int i=0;i<produseSortate.produse.size()-1;i++) {
                    if(produseSortate.produse[i].getNume() < produseSortate.produse[i+1].getNume()) {
                        Produs aux = produseSortate.produse[i];
                        produseSortate.produse[i] = produseSortate.produse[i+1];
                        produseSortate.produse[i+1] = aux;
                        ok = 0;
                    }
                }
            }
        }
        if(criteriu == 2) {
            int ok = 0;
            while(ok == 0) {
                ok = 1;
                for(int i=0;i<produseSortate.produse.size()-1;i++) {
                    if(produseSortate.produse[i].getPret() < produseSortate.produse[i+1].getPret()) {
                        Produs aux = produseSortate.produse[i];
                        produseSortate.produse[i] = produseSortate.produse[i+1];
                        produseSortate.produse[i+1] = aux;
                        ok = 0;
                    }
                }
            }
        }
        if(criteriu == 3) {
            int ok = 0;
            while(ok == 0) {
                ok = 1;
                for(int i=0;i<produseSortate.produse.size()-1;i++) {
                    if((produseSortate.produse[i].getNume() < produseSortate.produse[i+1].getNume()) || (produseSortate.produse[i].getNume() == produseSortate.produse[i+1].getNume() &&
                                                                                                         produseSortate.produse[i].getTip() < produseSortate.produse[i+1].getTip())) {
                        Produs aux = produseSortate.produse[i];
                        produseSortate.produse[i] = produseSortate.produse[i+1];
                        produseSortate.produse[i+1] = aux;
                        ok = 0;
                    }
                }
            }
        }
    }
}

void RepoProdus::filtrareNume(RepoProdus &produseFiltrate, const string& nume) {
    for(int i=0;i<produse.size();i++) {
        if(produse[i].getNume() == nume) {
            produseFiltrate.store(produse[i]);
        }
    }
}

void RepoProdus::filtrareTip(RepoProdus &produseFiltrate, const string& tip) {
    for(int i=0;i<produse.size();i++) {
        if(produse[i].getTip() == tip) {
            produseFiltrate.store(produse[i]);
        }
    }
}

void RepoProdus::filtrarePret(RepoProdus &produseFiltrate, const double& pret) {
    for(int i=0;i<produse.size();i++) {
        if(produse[i].getPret() == pret) {
            produseFiltrate.store(produse[i]);
        }
    }
}

void RepoProdus::filtrareProducator(RepoProdus &produseFiltrate, const string& producator) {
    for(int i=0;i<produse.size();i++) {
        if(produse[i].getProducator() == producator) {
            produseFiltrate.store(produse[i]);
        }
    }
}


void testRepoAdaugare() {
    RepoProdus repo;
    Produs p{"Apa", "Minerala", 2.99, "Bucovina"};
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
    Produs p{"Apa", "Minerala", 2.99, "Bucovina"};
    repo.store(p);
    assert(repo.getAll().size() == 1);
    repo.del("Apa", "Minerala", "Bucovina");
    assert(repo.getAll().size() == 0);
    try {
        repo.del("Apa", "Minerala", "Bucovina");
    }
    catch (RepoException&) {
        assert(true);
    }
}

void testRepoModificare() {
    RepoProdus repo;
    Produs p{"Apa", "Minerala", 2.99, "Bucovina"};
    repo.store(p);
    Produs p2{"Apa", "Plata", 3.99, "Bucovina"};
    assert(repo.getAll().size() == 1);
    repo.modify(p, p2);
    Vector<Produs> produse = repo.getAll();
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

void testFiltrare() {
    RepoProdus repo;
    RepoProdus listaFiltrata;
    Produs p1{"Apa", "Minerala", 2.99, "Bucovina"};
    Produs p2{"Apa", "Plata", 3.99, "Bucovina"};
    Produs p3{"Apa", "Plata", 3.29, "Aqua Carpatica"};
    repo.store(p1);
    repo.store(p2);
    repo.store(p3);
    assert(repo.getAll().size() == 3);
    repo.filtrareNume(listaFiltrata, "Apa");
    assert(listaFiltrata.getAll().size() == 3);

    listaFiltrata = {};
    repo.filtrareTip(listaFiltrata, "Plata");
    assert(listaFiltrata.getAll().size() == 2);

    listaFiltrata = {};
    repo.filtrarePret(listaFiltrata, 3.99);
    assert(listaFiltrata.getAll().size() == 1);

    listaFiltrata = {};
    repo.filtrareProducator(listaFiltrata, "Bucovina");;
    assert(listaFiltrata.getAll().size() == 2);
}

void test_cauta() {
    RepoProdus repo;
    Produs p{"Apa", "Minerala", 2.99, "Bucovina"};
    repo.store(p);
    assert(repo.getAll().size() == 1);
    auto prod = repo.cauta("Apa", "Minerala", "Bucovina");
    assert(prod.getNume() == "Apa");
    assert(prod.getTip() == "Minerala");
    assert(prod.getProducator() == "Bucovina");
    try {
        auto prod2 = repo.cauta("Apa", "Minerala", "Bucovin");}
    catch (RepoException&) {
        assert(true);
    }
}

void test_sort() {
    RepoProdus repoSortat;
    Produs p1{"Apa", "Minerala", 4.99, "Bucovina"};
    Produs p2{"Paine", "Plata", 3.99, "Bucovina"};
    Produs p3{"Apa", "Semi", 3.29, "Aqua Carpatica"};
    repoSortat.store(p1);
    repoSortat.store(p2);
    repoSortat.store(p3);
    assert(repoSortat.getAll().size() == 3);
    repoSortat.sortare(repoSortat, 1, 1);
    auto sortate = repoSortat.getAll();
    assert(sortate[0].getPret() == 4.99);

    repoSortat.sortare(repoSortat, 2, 1);
    auto sortate2 = repoSortat.getAll();
    assert(sortate2[0].getPret() == 3.29);

    repoSortat.sortare(repoSortat, 3, 1);
    auto sortate3 = repoSortat.getAll();
    assert(sortate3[0].getPret() == 4.99);

    repoSortat.sortare(repoSortat, 1, 2);
    auto sortate4 = repoSortat.getAll();
    assert(sortate4[0].getPret() == 3.99);

    repoSortat.sortare(repoSortat, 2, 2);
    auto sortate5 = repoSortat.getAll();
    assert(sortate5[0].getPret() == 4.99);

    repoSortat.sortare(repoSortat, 3, 2);
    auto sortate6 = repoSortat.getAll();
    assert(sortate6[0].getPret() == 3.99);
}

void testeREPO() {
    testRepoAdaugare();
    testRepoStergere();
    testRepoModificare();
    testMSG();
    testFiltrare();
    test_cauta();
    test_sort();
}