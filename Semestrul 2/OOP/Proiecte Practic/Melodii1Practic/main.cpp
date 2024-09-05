#include <QApplication>
#include <QPushButton>
#include "repo.h"
#include "service.h"
#include "gui.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Repo repo{"C:\\Users\\razva\\Desktop\\Melodii1Practic\\melodii.txt"};
    Service srv{repo};
    GUI gui{srv};
    gui.show();
    return QApplication::exec();
}
