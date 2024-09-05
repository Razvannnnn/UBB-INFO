#include <iostream>
#include <QApplication>
#include "service.h"
#include "repo.h"
#include "gui.h"

using namespace std;

int main(int argc, char* argv[]) {
    QApplication app{argc, argv};
    Repo repo{"C:\\Users\\razva\\Desktop\\OOP\\PracticProduse\\produse.txt"};
    Service srv{repo};
    GUI gui{srv};
    gui.run();
    return app.exec();
}
