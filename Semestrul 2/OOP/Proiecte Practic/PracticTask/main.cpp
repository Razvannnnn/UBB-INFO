#include <QApplication>
#include <QPushButton>
#include "gui.h"
#include "service.h"
#include "repo.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Repo repo{"C:\\Users\\razva\\Desktop\\PracticTask\\taskuri.txt"};
    Service srv{repo};
    GUI gui{srv};
    gui.show();
    return QApplication::exec();
}
