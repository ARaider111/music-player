#include "startwindow.h"
#include "appcontroller.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AppController controller;

    return a.exec();
}
