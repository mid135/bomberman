#include "mainwindow.h"
#include <QApplication>
#include  "elements.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Player *p = new Player();
    p->purge();
    return a.exec();
}
