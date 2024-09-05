#include <QApplication>
#include <QPushButton>
#include <domain.h>
#include "service.h"
#include "repo.h"
#include "gui.h"
#include "teste.h"


int main(int argc, char *argv[]) {

    teste();

    QApplication a(argc, argv);
    Repo repo{"C:\\Users\\razva\\Desktop\\tractoare\\tractoare.txt"};
    Service srv{repo};
    GUI gui{srv};
    gui.show();
    return QApplication::exec();
}
