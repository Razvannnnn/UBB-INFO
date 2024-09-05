#include <iostream>
#include "domain.h"
#include "service.h"
#include "repo.h"
#include <QApplication>
#include "GUI.h"

using namespace std;

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    Repo repo{ "C:\\Users\\razva\\Desktop\\OOP\\PracticMELODII2\\melodii.txt" };
    Service srv{repo};
    GUI gui{srv};
    gui.show();
    return app.exec();
}
