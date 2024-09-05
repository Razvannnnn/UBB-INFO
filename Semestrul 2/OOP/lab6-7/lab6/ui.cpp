#include "ui.h"
#include <iostream>

using std::cin;
using std::cout;


void UI::startUI() {
    while (true) {
        cout<<"1. Adaugare\n2. Stergere\n3. Modificare\n4. Print\n5. Filtrare dupa un criteriu\n6. Cautare\n7. Sortare\n0. Exit\nComanda:";
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
            } catch(Exception &e){
                cout<< e.getMsg();
            }
        }
        if(comanda == 2) {
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
                service.stergere(nume, tip, producator);
                cout << "Produs sters!\n";
            } catch (Exception &e) {
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
            } catch(Exception &e){
                cout<< e.getMsg();
            }
        }
        if(comanda == 4) {
            for(const Produs& p : service.getAll()) {
                cout<<"Nume:"<<p.getNume()<<"\nTip:"<<p.getTip()<<"\nPret:"<<p.getPret()<<"\nProducator:"<<p.getProducator()<<"\n";
            }
        }
        if(comanda == 5) {
            string nume;
            string tip;
            double pret;
            string producator;
            RepoProdus produseFiltrate;
            int comandaFiltrare=-1;
            cout<<"Filtrare dupa: 1.Nume, 2.Tip, 3.Pret, 4.Producator\nOptiune:";
            cin>>comandaFiltrare;
            while(comandaFiltrare<1 || comandaFiltrare>4) {
                cout<<"Optiune invalida!\nOptiune:";
                cin>>comandaFiltrare;
            }
            if(comandaFiltrare == 1) {
                cout<<"Nume: ";
                cin>>nume;
                produseFiltrate = service.fltrareUnCriteriu(1, nume, "", 0, "");
                for(const Produs& p : produseFiltrate.getAll()) {
                    cout<<"Nume:"<<p.getNume()<<"\nTip:"<<p.getTip()<<"\nPret:"<<p.getPret()<<"\nProducator:"<<p.getProducator()<<"\n";
                }
            }
            if(comandaFiltrare == 2) {
                cout<<"Tip: ";
                cin>>tip;
                produseFiltrate = service.fltrareUnCriteriu(2, "", tip, 0, "");
                for(const Produs& p : produseFiltrate.getAll()) {
                    cout<<"Nume:"<<p.getNume()<<"\nTip:"<<p.getTip()<<"\nPret:"<<p.getPret()<<"\nProducator:"<<p.getProducator()<<"\n";
                }
            }
            if(comandaFiltrare == 3) {
                cout<<"Pret: ";
                cin>>pret;
                produseFiltrate = service.fltrareUnCriteriu(3, "", "", pret, "");
                for(const Produs& p : produseFiltrate.getAll()) {
                    cout<<"Nume:"<<p.getNume()<<"\nTip:"<<p.getTip()<<"\nPret:"<<p.getPret()<<"\nProducator:"<<p.getProducator()<<"\n";
                }
            }
            if(comandaFiltrare == 4) {
                cout<<"Producator: ";
                cin>>producator;
                produseFiltrate = service.fltrareUnCriteriu(4, "", "", 0, producator);
                for(const Produs& p : produseFiltrate.getAll()) {
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
            cout<<"Filtrare dupa: 1.Nume 2.Pret 3.Nume+Tip\nOptiune:\n";
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
                RepoProdus produseSortate = service.sortare(1, comanda_sort2);
                for(const Produs& p : produseSortate.getAll()) {
                        cout<<"Nume:"<<p.getNume()<<"\nTip:"<<p.getTip()<<"\nPret:"<<p.getPret()<<"\nProducator:"<<p.getProducator()<<"\n";
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
                RepoProdus produseSortate = service.sortare(2, comanda_sort2);
                for(const Produs& p : produseSortate.getAll()) {
                    cout<<"Nume:"<<p.getNume()<<"\nTip:"<<p.getTip()<<"\nPret:"<<p.getPret()<<"\nProducator:"<<p.getProducator()<<"\n";
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
                RepoProdus produseSortate = service.sortare(3, comanda_sort2);
                for(const Produs& p : produseSortate.getAll()) {
                    cout<<"Nume:"<<p.getNume()<<"\nTip:"<<p.getTip()<<"\nPret:"<<p.getPret()<<"\nProducator:"<<p.getProducator()<<"\n";
                }
            }
        }
    }
}