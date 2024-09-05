#include <iostream>
#include <domain.h>
#include "service.h"
#include "repo.h"
#include "gui.h"
#include <QApplication>

using namespace std;

int main(int argc, char* argv[]) {
    QApplication app{argc, argv};
    Repo repo{"C:\\Users\\razva\\Desktop\\OOP\\PracticTractoare\\tractoare.txt"};
    Service srv{repo};
    GUI gui{srv};
    gui.show();
    return app.exec();
}
