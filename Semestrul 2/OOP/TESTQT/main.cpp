#include <iostream>

#include <QApplication>
#include <QtWidgets>
#include <QLabel>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QLabel label{"HELLO"};
    label.show();
    return app.exec();
}
