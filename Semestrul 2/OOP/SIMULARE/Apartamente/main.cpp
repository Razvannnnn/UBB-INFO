#include <iostream>
#include <QApplication>
#include <QtWidgets>

#include "service.h"
#include "gui.h"
#include "repo.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    Repo repo;
    Service srv{repo};
    GUI gui{srv};
    gui.show();
    return app.exec();
}
