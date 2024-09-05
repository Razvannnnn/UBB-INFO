#include <iostream>
#include "domain.h"
#include "service.h"
#include "repo.h"
#include <QApplication>
#include "gui.h"

using namespace std;

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    Repo repo{ "C:\\Users\\razva\\Desktop\\OOP\\Practiccc\\produse.txt" };
    Service srv{repo};
    GUI gui{srv};
    gui.show();
    return app.exec();
}
