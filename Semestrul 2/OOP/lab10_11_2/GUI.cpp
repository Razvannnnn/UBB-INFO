#include "GUI.h"


void GUI::initializeGUIComponents() {
    //main layout
    lyMain = new QHBoxLayout;
    this->setLayout(lyMain);

    //left part of the window, pentru care setam layout vertical
    QWidget* left = new QWidget;
    lyLeft = new QVBoxLayout;
    left->setLayout(lyLeft);

    QWidget* form = new QWidget;
    lyForm = new QFormLayout;
    form->setLayout(lyForm);
    editNume = new QLineEdit;
    editProducator = new QLineEdit;
    editTip = new QLineEdit;
    editPret = new QLineEdit;

    // Nume
    lyForm->addRow(lblNume, editNume);

    // Tip
    lyForm->addRow(lblTip, editTip);

    // Pret
    lyForm->addRow(lblPret, editPret);

    // Producator
    lyForm->addRow(lblProducator, editProducator);

    btnAddProdus = new QPushButton("Adauga produs");
    lyForm->addWidget(btnAddProdus);
    btnModifyProdus = new QPushButton("Modifica produs");
    lyForm->addWidget(btnModifyProdus);

    btnDeleteProdus = new QPushButton("Delete produs");
    lyForm->addWidget(btnDeleteProdus);

    //adaugam toate componentele legate de adaugare produse in layout-ul care corespunde partii din stanga a ferestrei
    lyLeft->addWidget(form);

    //cream un GroupBox pentru radiobuttons care corespund criteriilor de sortare pe care le avem (dupa nume, pret, nume+tip) + butonul de sortare
    QVBoxLayout* lyRadioBox = new QVBoxLayout;
    this->groupBox->setLayout(lyRadioBox);
    lyRadioBox->addWidget(radioSrtNume);
    lyRadioBox->addWidget(radioSrtPret);
    lyRadioBox->addWidget(radioSrtNumeTip);

    btnSortProduse = new QPushButton("Sorteaza produsele");
    lyRadioBox->addWidget(btnSortProduse);

    //adaugam acest grup in partea stanga, dupa componentele pentru adaugare in layout-ul vertical
    lyLeft->addWidget(groupBox);

    //cream un form pentru filtrari
    QWidget* formFilter = new QWidget;
    QFormLayout* lyFormFilter = new QFormLayout;
    formFilter->setLayout(lyFormFilter);

    editFilterNume = new QLineEdit();
    lyFormFilter->addRow(lblFilterCriteria, editFilterNume);
    btnFilterProdus1 = new QPushButton("Filtreaza oferte dupa nume");
    lyFormFilter->addWidget(btnFilterProdus1);

    editFilterTip = new QLineEdit();
    lyFormFilter->addRow(lblFilterCriteria2, editFilterTip);
    btnFilterProdus2 = new QPushButton("Filtreaza oferte dupa tip");
    lyFormFilter->addWidget(btnFilterProdus2);

    editFilterPret = new QLineEdit();
    lyFormFilter->addRow(lblFilterCriteria3, editFilterPret);
    btnFilterProdus3 = new QPushButton("Filtreaza oferte dupa pret");
    lyFormFilter->addWidget(btnFilterProdus3);

    editFilterProducator = new QLineEdit();
    lyFormFilter->addRow(lblFilterCriteria4, editFilterProducator);
    btnFilterProdus4 = new QPushButton("Filtreaza oferte dupa producator");
    lyFormFilter->addWidget(btnFilterProdus4);

    lyLeft->addWidget(formFilter);

    //Buton folosit pentru a reincarca datele; afisam toate produsele in tabel, in ordinea initiala din fisier
    btnReloadData = new QPushButton("Reincarcare");
    lyLeft->addWidget(btnReloadData);

    btnUndo = new QPushButton("Undo");
    lyLeft->addWidget(btnUndo);

    btnCos = new QPushButton("Wishlist");
    adaugaCos = new QPushButton("Adauga produse in wishlist");
    numeProdusCos = new QLineEdit;
    tipProdusCos = new QLineEdit;
    producatorProdusCos = new QLineEdit;
    adaugaRandomCos = new QPushButton("Adauga produse random in wishlist");
    numarRandom = new QLineEdit;
    golesteCos = new QPushButton("Goleste wishlist");
    editExport = new QLineEdit;
    this->listaCos = new QListWidget();
    exportCos = new QPushButton("Exporta wishlist");

    btnCosCRUDGUI = new QPushButton("CosCRUDGUI");
    lyLeft->addWidget(btnCosCRUDGUI);

    btnCosReadOnlyGUI = new QPushButton("CosReadOnlyGUI");
    lyLeft->addWidget(btnCosReadOnlyGUI);

    //componenta right - contine doar tabelul cu produse
    QWidget* right = new QWidget;
    lyRight = new QVBoxLayout;
    right->setLayout(lyRight);

    int noLines = 10;
    int noColumns = 4;
    this->tableProduse = new QTableWidget{ noLines, noColumns };

    //setam header-ul tabelului
    QStringList tblHeaderList;
    tblHeaderList << "Nume" << "Tip" << "Pret" << "Producator";
    this->tableProduse->setHorizontalHeaderLabels(tblHeaderList);

    //optiune pentru a se redimensiona celulele din tabel in functie de continut
    this->tableProduse->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    lyRight->addWidget(tableProduse);
    lyRight->addWidget(btnCos);

    this->listaProduse = new QListWidget;
    lyRight->addWidget(listaProduse);

    QWidget* rright = new QWidget;
    lyRRight = new QVBoxLayout;
    rright->setLayout(lyRRight);

    lyMain->addWidget(left);
    lyMain->addWidget(right);
    lyMain->addWidget(rright);
}

void GUI::connectSignalsSlots() {
    QObject::connect(btnAddProdus, &QPushButton::clicked, this, &GUI::guiAddProdus);
    QObject::connect(btnModifyProdus, &QPushButton::clicked, this, &GUI::guiModifyProdus);
    QObject::connect(btnDeleteProdus, &QPushButton::clicked, this, &GUI::guiDeleteProdus);

    QObject::connect(btnUndo, &QPushButton::clicked, [&]() {
        try {
            this->srv.undo();
            this->reloadProdusList(this->srv.getAll());
            QMessageBox::information(this, "Info", QString::fromStdString("Undo realizat cu succes."));
        }
        catch (Exception& ex) {
            QMessageBox::warning(this, "Warning", QString::fromStdString(ex.getMsg()));
        }
        catch (RepoException& re) {
            QMessageBox::warning(this, "Warning", "");
        }
    });

    QObject::connect(btnSortProduse, &QPushButton::clicked, [&]() {
        if (this->radioSrtNume->isChecked())
            this->reloadProdusList(srv.sortNume());
        else if(this->radioSrtPret->isChecked())
            this->reloadProdusList(srv.sortPret());
        else if(this->radioSrtNumeTip->isChecked())
            this->reloadProdusList(srv.sortNumeTip());
    });

    QObject::connect(btnFilterProdus2, &QPushButton::clicked, [&]() {
        string filterC = this->editFilterTip->text().toStdString();
        this->reloadProdusList(srv.filtrareTip(filterC));
        editFilterTip->clear();
    });

    QObject::connect(btnFilterProdus1, &QPushButton::clicked, [&]() {
        string filterC = this->editFilterNume->text().toStdString();
        this->reloadProdusList(srv.filtrareNume(filterC));
        editFilterNume->clear();
    });

    QObject::connect(btnFilterProdus3, &QPushButton::clicked, [&]() {
        string filterC = this->editFilterPret->text().toStdString();
        this->reloadProdusList(srv.filtrarePret(stoi(filterC)));
        editFilterPret->clear();
    });

    QObject::connect(btnFilterProdus4, &QPushButton::clicked, [&]() {
        string filterC = this->editFilterProducator->text().toStdString();
        this->reloadProdusList(srv.filtrareProducator(filterC));
        editFilterProducator->clear();
    });

    QObject::connect(btnReloadData, &QPushButton::clicked, [&]() {
        this->reloadProdusList(srv.getAll());
    });

    QObject::connect(btnCos, &QPushButton::clicked, [&]() {
        QWidget* fereastraCos = new QWidget;
        QFormLayout* lyCos = new QFormLayout;
        fereastraCos->setLayout(lyCos);
        numeProdusCos = new QLineEdit;
        lyCos->addRow("Nume produs: ", numeProdusCos);
        tipProdusCos = new QLineEdit;
        lyCos->addRow("Tip produs: ", tipProdusCos);
        producatorProdusCos = new QLineEdit;
        lyCos->addRow("Producator produs: ", producatorProdusCos);
        lyCos->addWidget(adaugaCos);
        lyCos->addRow(lblRandom, numarRandom);
        lyCos->addWidget(adaugaRandomCos);
        lyCos->addWidget(golesteCos);
        editExport = new QLineEdit;
        lyCos->addRow(lblExport, editExport);
        lyCos->addWidget(exportCos);
        lyCos->addWidget(listaCos);
        fereastraCos->show();
    });

    QObject::connect(adaugaCos, & QPushButton::clicked, [&]() {
        try {
            string nume = numeProdusCos->text().toStdString();
            string tip = tipProdusCos->text().toStdString();
            string prodcator = producatorProdusCos->text().toStdString();
            numeProdusCos->clear();
            tipProdusCos->clear();
            producatorProdusCos->clear();
            this->srv.cosAdauga(nume, tip, prodcator);
//           QMessageBox::information(this, "Info", "Produs adaugat cu succes!");
            this->reloadProdusCosList(this->srv.getAllCos());
        } catch (RepoException& repoException) {
            QMessageBox::warning(this, "Warning", "Produsul nu exista!");
        }
    });

    QObject::connect(adaugaRandomCos, & QPushButton::clicked, [&]() {
        try {
            int nr = numarRandom->text().toInt();
            numarRandom->clear();
            this->srv.cosAdaugaRandom(nr);
//            QMessageBox::information(this, "Info", "S-au adaugat ofertele random");
            this->reloadProdusCosList(this->srv.getAllCos());
        } catch (RepoException& repoException) {
            QMessageBox::warning(this, "Warning", "Nu exista oferte");
        }
    });

    QObject::connect(golesteCos, & QPushButton::clicked, [&]() {
        try {
            this->srv.cosSterge();
            this->reloadProdusCosList(this->srv.getAllCos());
        } catch (RepoException &repoException) {
            QMessageBox::warning(this, "Warning", "");
        }
    });

    QObject::connect(exportCos, &QPushButton::clicked, [&]() {
        try {
            string fisier = editExport->text().toStdString();
            editExport->clear();
            this->srv.cosExport(fisier);
            listaCos->clear();
            this->srv.cosSterge();
            this->reloadProdusCosList(this->srv.getAllCos());
        } catch (Exceptie &Exception) {
            QMessageBox::warning(this, "Warning", "FISIER INVALID");
        }
    });

    QObject::connect(btnCosCRUDGUI, &QPushButton::clicked, [&]() {
       auto fereastraCos = new CosCRUDGUI(srv.getCos());
       fereastraCos->show();
    });

    QObject::connect(btnCosReadOnlyGUI, &QPushButton::clicked, [&]() {
        auto fereastraRONLY = new CosReadOnlyGUI(srv.getCos());
        fereastraRONLY->show();
    });
}

void GUI::reloadProdusList(vector<Produs> produse) {
    this->tableProduse->clearContents();
    this->tableProduse->setRowCount(produse.size());

    int lineNumber = 0;
    for (auto& produs : produse) {
        this->tableProduse->setItem(lineNumber, 0, new QTableWidgetItem(QString::fromStdString(produs.getNume())));
        this->tableProduse->setItem(lineNumber, 1, new QTableWidgetItem(QString::fromStdString(produs.getTip())));
        this->tableProduse->setItem(lineNumber, 2, new QTableWidgetItem(QString::number(produs.getPret())));
        this->tableProduse->setItem(lineNumber, 3, new QTableWidgetItem(QString::fromStdString(produs.getProducator())));
        lineNumber++;
    }

    this->listaProduse->clear();
    for(auto& produs : produse) {
        string o = produs.getNume() + " - " + produs.getTip() + " - " + to_string(produs.getPret()) + " - " + produs.getProducator();
        this->listaProduse->addItem(QString::fromStdString(o));
    }
    QLayoutItem *item;
    while ((item = lyRRight->takeAt(0)))
    {
        delete item->widget();
        delete item;
    }
    adaugaButoane();
}

void GUI::reloadProdusCosList(vector<Produs> produse) {
    this->listaCos->clear();
    for(const auto& elem : produse) {
        auto item = new QListWidgetItem(QString::fromStdString(
                elem.getNume() + " " + elem.getTip() + " " + std::to_string(elem.getPret()) + " " + elem.getProducator()
        ));
        this->listaCos->addItem(item);
    }
}

void GUI::adaugaButoane() {
    auto map = srv.raportTip();
    for(const auto &pereche : map) {
        if(pereche.second > 0) {
            auto buttonTip = new QPushButton(QString::fromStdString(pereche.first));
            lyRRight->addWidget(buttonTip);
            QObject::connect(buttonTip, &QPushButton::clicked, [pereche](){
                QMessageBox::information(nullptr, "Info", QString::number(pereche.second));
            });
        }
    }
}

void GUI::guiAddProdus() {
    try {
        string nume = editNume->text().toStdString();
        string tip = editTip->text().toStdString();
        string producator = editProducator->text().toStdString();
        double pret = editPret->text().toFloat();

        editNume->clear();
        editProducator->clear();
        editTip->clear();
        editPret->clear();

        this->srv.adaugare(nume, tip, pret, producator);
        this->reloadProdusList(this->srv.getAll());

        QMessageBox::information(this, "Info", QString::fromStdString("Produs adaugat cu succes."));

    }
    catch (RepoException& re) {
        QMessageBox::warning(this, "Warning", "");
    }
    catch (Exception& ve) {
        QMessageBox::warning(this, "Warning", QString::fromStdString(ve.getMsg()));
    }
}

void GUI::guiModifyProdus() {
    try {
        string nume = editNume->text().toStdString();
        string tip = editTip->text().toStdString();
        string producator = editProducator->text().toStdString();
        double pret = editPret->text().toFloat();

        editNume->clear();
        editProducator->clear();
        editTip->clear();
        editPret->clear();

        this->srv.modificare(nume, tip, pret, producator, nume, tip, pret, producator);
        this->reloadProdusList(this->srv.getAll());

        QMessageBox::information(this, "Info", QString::fromStdString("Produs modificat cu succes."));

    }
    catch (RepoException& re) {
        QMessageBox::warning(this, "Warning", "");
    }
    catch (Exception& ve) {
        QMessageBox::warning(this, "Warning", QString::fromStdString(ve.getMsg()));
    }
}

void GUI::guiDeleteProdus() {
    try {
        string nume = editNume->text().toStdString();
        string tip = editTip->text().toStdString();
        string producator = editProducator->text().toStdString();
        double pret = editPret->text().toFloat();

        editNume->clear();
        editProducator->clear();
        editTip->clear();
        editPret->clear();

        this->srv.stergere(nume, tip, pret, producator);
        this->reloadProdusList(this->srv.getAll());

        QMessageBox::information(this, "Info", QString::fromStdString("Oferta stearsa cu succes."));

    }
    catch (RepoException& re) {
        QMessageBox::warning(this, "Warning", "");
    }
    catch (Exception& ve) {
        QMessageBox::warning(this, "Warning", QString::fromStdString(ve.getMsg()));
    }
}