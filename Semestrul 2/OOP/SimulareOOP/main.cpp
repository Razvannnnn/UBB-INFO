#include <iostream>
#include <QApplication>
#include "domain.h"
#include "repo.h"
#include "service.h"
#include "gui.h"
#include "string"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    string filename = "C:\\Users\\razva\\Desktop\\SimulareOOP\\produs.txt";
    Repo repo(filename);
    Service srv{repo};
    GUI gui{srv};
    gui.show();
    return a.exec();
}
