#include "ui.h"
#include <iostream>

using std::cin;
using std::cout;


void UI::startUI() {
    while (true) {
        cout<<"1. Adaugare\n2. Stergere\n3. Modificare\n4. Print\n5. Filtrare dupa un criteriu\n6. Cautare\n7. Sortare\n8. Raport TIP\n9. Meniu COS\n10. Undo\n0. Exit\nComanda:";
        int comanda = 0;
        cin>>comanda;
        if(comanda == 0) {
            break;
        }
        if(comanda == 1) {
            string nume;
            string tip;
            double pret;
            string producator;
            cout<<"Nume:";
            cin>>nume;
            cout<<"Tip:";
            cin>>tip;
            cout<<"Pret:";
            cin>>pret;
            cout<<"Producator:";
            cin>>producator;
            try {
                service.adaugare(nume, tip, pret, producator);
                cout<<"Produs adaugat!\n";
            } catch(RepoException &e){
                cout<< e.getMsg();
            }
        }
        if(comanda == 2) {
            string nume;
            string tip;
            string producator;
            double pret;
            cout << "Nume:";
            cin >> nume;
            cout << "Tip:";
            cin >> tip;
            cout<<"Pret:";
            cin>>pret;
            cout << "Producator:";
            cin >> producator;
            try {
                service.stergere(nume, tip, pret, producator);
                cout << "Produs sters!\n";
            } catch (RepoException &e) {
                cout << e.getMsg();
            }
        }
        if(comanda == 3) {
            string nume;
            string tip;
            double pret;
            string producator;
            cout<<"Nume:";
            cin>>nume;
            cout<<"Tip:";
            cin>>tip;
            cout<<"Pret:";
            cin>>pret;
            cout<<"Producator:";
            cin>>producator;
            string numeNou;
            string tipNou;
            double pretNou;
            string producatorNou;
            cout<<"Nume NOU:";
            cin>>numeNou;
            cout<<"Tip NOU:";
            cin>>tipNou;
            cout<<"Pret NOU:";
            cin>>pretNou;
            cout<<"Producator NOU:";
            cin>>producatorNou;
            try {
                service.modificare(nume, tip, pret, producator, numeNou, tipNou, pretNou, producatorNou);
                cout<<"Produs Modificat!\n";
            } catch(RepoException &e){
                cout<< e.getMsg();
            }
        }
        if(comanda == 4) {
            try {
                for(const Produs& p : service.getAll()) {
                    cout<<"Nume:"<<p.getNume()<<"\nTip:"<<p.getTip()<<"\nPret:"<<p.getPret()<<"\nProducator:"<<p.getProducator()<<"\n";
                }
            } catch(RepoException &e){
                cout<< e.getMsg();
            }
        }
        if(comanda == 5) {
            string nume;
            string tip;
            double pret;
            string producator;
            vector<Produs> produseFiltrate;
            int comandaFiltrare=-1;
            cout<<"Filtrare dupa: 1.Nume, 2.Tip, 3.Pret, 4.Producator\nOptiune:";
            cin>>comandaFiltrare;
            while(comandaFiltrare<1 || comandaFiltrare>4) {
                cout<<"Optiune invalida!\nOptiune:";
                cin>>comandaFiltrare;
            }
            if(comandaFiltrare == 1) {
                cout<<"Nume:";
                cin>>nume;
                produseFiltrate = service.filtrareNume(nume);
                for(const Produs& p : produseFiltrate) {
                    cout<<"Nume:"<<p.getNume()<<"\nTip:"<<p.getTip()<<"\nPret:"<<p.getPret()<<"\nProducator:"<<p.getProducator()<<"\n";
                }
            }
            if(comandaFiltrare == 2) {
                cout<<"Tip:";
                cin>>tip;
                produseFiltrate = service.filtrareTip(tip);
                for(const Produs& p : produseFiltrate) {
                    cout<<"Nume:"<<p.getNume()<<"\nTip:"<<p.getTip()<<"\nPret:"<<p.getPret()<<"\nProducator:"<<p.getProducator()<<"\n";
                }
            }
            if(comandaFiltrare == 3) {
                cout<<"Pret:";
                cin>>pret;
                produseFiltrate = service.filtrarePret(pret);
                for(const Produs& p : produseFiltrate) {
                    cout<<"Nume:"<<p.getNume()<<"\nTip:"<<p.getTip()<<"\nPret:"<<p.getPret()<<"\nProducator:"<<p.getProducator()<<"\n";
                }
            }
            if(comandaFiltrare == 4) {
                cout<<"Producator:";
                cin>>producator;
                produseFiltrate = service.filtrareProducator(producator);
                for(const Produs& p : produseFiltrate) {
                    cout<<"Nume:"<<p.getNume()<<"\nTip:"<<p.getTip()<<"\nPret:"<<p.getPret()<<"\nProducator:"<<p.getProducator()<<"\n";
                }
            }
        }
        if(comanda == 6) {
            string nume;
            string tip;
            string producator;
            cout << "Nume:";
            cin >> nume;
            cout << "Tip:";
            cin >> tip;
            cout << "Producator:";
            cin >> producator;
            try {
                Produs p = service.cauta(nume, tip, producator);
                cout<<"Nume:"<<p.getNume()<<"\nTip:"<<p.getTip()<<"\nPret:"<<p.getPret()<<"\nProducator:"<<p.getProducator()<<"\n";
            } catch (RepoException &e) {
                cout << e.getMsg();
            }
        }
        if(comanda == 7) {
            cout<<"Sortare dupa: 1.Nume 2.Pret 3.Nume+Tip\nOptiune:\n";
            int comanda_sort;
            cin>>comanda_sort;
            while(comanda_sort<1 || comanda_sort>3) {
                cout<<"Optiune invalida!\nOptiune:";
                cin>>comanda_sort;
            }
            if(comanda_sort == 1) {
                cout<<"1.Crescator sau 2.Descrescator\n";
                int comanda_sort2;
                cin>>comanda_sort2;
                while(comanda_sort2<1 || comanda_sort2>2) {
                    cout<<"Optiune invalida!\nOptiune:";
                    cin>>comanda_sort2;
                }
                vector<Produs> produseSortate = service.sortNume();
                if(comanda_sort2 == 1) {
                    for(const Produs& p : produseSortate) {
                        cout<<"Nume:"<<p.getNume()<<"\nTip:"<<p.getTip()<<"\nPret:"<<p.getPret()<<"\nProducator:"<<p.getProducator()<<"\n";
                    }
                } else {
                    for(auto i = produseSortate.rbegin(); i != produseSortate.rend(); ++i) {
                        const Produs& p = *i;
                        cout<<"Nume:"<<p.getNume()<<"\nTip:"<<p.getTip()<<"\nPret:"<<p.getPret()<<"\nProducator:"<<p.getProducator()<<"\n";
                    }
                }
            }
            if(comanda_sort == 2) {
                cout<<"1.Crescator sau 2.Descrescator\n";
                int comanda_sort2;
                cin>>comanda_sort2;
                while(comanda_sort2<1 || comanda_sort2>2) {
                    cout<<"Optiune invalida!\nOptiune:";
                    cin>>comanda_sort2;
                }
                vector<Produs> produseSortate = service.sortPret();
                if(comanda_sort2 == 1) {
                    for(const Produs& p : produseSortate) {
                        cout<<"Nume:"<<p.getNume()<<"\nTip:"<<p.getTip()<<"\nPret:"<<p.getPret()<<"\nProducator:"<<p.getProducator()<<"\n";
                    }
                } else {
                    for(auto i = produseSortate.rbegin(); i != produseSortate.rend(); ++i) {
                        const Produs& p = *i;
                        cout<<"Nume:"<<p.getNume()<<"\nTip:"<<p.getTip()<<"\nPret:"<<p.getPret()<<"\nProducator:"<<p.getProducator()<<"\n";
                    }
                }
            }
            if(comanda_sort == 3) {
                cout<<"1.Crescator sau 2.Descrescator\n";
                int comanda_sort2;
                cin>>comanda_sort2;
                while(comanda_sort2<1 || comanda_sort2>2) {
                    cout<<"Optiune invalida!\nOptiune:";
                    cin>>comanda_sort2;
                }
                vector<Produs> produseSortate = service.sortNumeTip();
                if(comanda_sort2 == 1) {
                    for(const Produs& p : produseSortate) {
                        cout<<"Nume:"<<p.getNume()<<"\nTip:"<<p.getTip()<<"\nPret:"<<p.getPret()<<"\nProducator:"<<p.getProducator()<<"\n";
                    }
                } else {
                    for(auto i = produseSortate.rbegin(); i != produseSortate.rend(); ++i) {
                        const Produs& p = *i;
                        cout<<"Nume:"<<p.getNume()<<"\nTip:"<<p.getTip()<<"\nPret:"<<p.getPret()<<"\nProducator:"<<p.getProducator()<<"\n";
                    }
                }
            }
        }
        if(comanda == 8) {
            cout<<"Raport privind tipul\n";
            auto map = service.raportTip();
            for(const auto &pereche : map) {
                if(pereche.second == 1) {
                    cout<<pereche.first<<":"<<pereche.second<<" produs\n";
                } else {
                    cout<<pereche.first<<":"<<pereche.second<<" produse\n";
                }
            }
        }
        if(comanda == 9) {
            meniuCos();
        }
        if(comanda == 10) {
            try {
                service.undo();
                cout<<"S-a efectuat operatia de undo!\n";
            } catch (Exceptie ex) {
                cout<<ex.getMsg()<<"\n";
            } catch(RepoException &e){
                cout<< e.getMsg();
            }
        }
    }
}

void UI::meniuCos() {
    while (true) {
        cout << "COS CUMPARATURI" << endl;
        cout << "Exista " << service.getAllCos().size() << " produse in cosul de cumparaturi.\n";
        cout << "Meniu Cos Cumparaturi" << endl;
        cout<< "1. Adaugare produs\n2. Generare produse random \n3. Goleste cos\n4. Afisare cos\n5. Export\n6. Iesire\n";
        int optiune;
        cout << "Optiunea:";
        cin >> optiune;
        if(optiune == 1) {
            string nume;
            string tip;
            string producator;
            cout << "Nume:";
            cin >> nume;
            cout << "Tip:";
            cin >> tip;
            cout << "Producator:";
            cin >> producator;
            try {
                service.cosAdauga(nume, tip, producator);
                cout << "Produsul a fost adaugat in cos!\n";
            } catch (RepoException &e) {
                cout << e.getMsg() << "\n";
            }
        }
        if(optiune == 2) {
            int nr;
            cout << "Numarul de produse pe care vreti sa le adaugati:";
            cin >> nr;
            if (nr < 0) {
                cout << "Numarul nu este valid!\n";
            } else {
                try {
                    int nr_prod = service.cosAdaugaRandom(nr);
                    cout << "Au fost adaugate " << nr_prod << " produse in cosul de cumparaturi!\n";
                } catch (Exceptie &e) {
                    cout << e.getMsg() << "\n";
                }
            }
        }
        if(optiune == 3) {
            service.cosSterge();
            cout << "Au fost sterse produsele din cos!\n";
        }
        if(optiune == 4) {
            for (const Produs &p: service.getAllCos()) {
                cout << "Nume:" << p.getNume() << "\nTip:" << p.getTip() << "\nPret:" << p.getPret() << "\nProducator:"
                     << p.getProducator() << "\n";
            }
        }
        if(optiune == 5) {
            string filename;
            cout << "Numele fisierului in care vrei sa salvezi cosul (.csv sau .html):";
            cin >> filename;
            string referinta = "C:\\Users\\razva\\Desktop\\OOP\\lab8_9\\";
            service.cosExport(referinta.append(filename));

        }
        if(optiune == 6) {
            cout << "Iesire din Cosul de cumparaturi\n";
            return;
        }
    }
}