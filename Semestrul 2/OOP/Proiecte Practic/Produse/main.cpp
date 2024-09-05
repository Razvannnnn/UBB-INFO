#include "mainwindow.h"

#include <QApplication>
#include "teste.h"
#include "repo.h"
#include "service.h"
#include "gui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Teste t;
    t.testAll();
    Repo r("fisier.txt");
    Service s(r);
    GUI g(s);
    g.show();
    return a.exec();
}
