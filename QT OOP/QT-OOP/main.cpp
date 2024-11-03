#include "mainwindow.h"
#include "Models/Helper.h"
#include <QString>
#include <QApplication>
#include <QInputDialog>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
