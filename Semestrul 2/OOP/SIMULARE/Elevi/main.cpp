#include <iostream>
#include <QApplication>
#include "repo.h"
#include "service.h"
#include "gui.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    Repo repo;
    Service srv{repo};
    GUI gui{srv};
    gui.show();
    return a.exec();
}
