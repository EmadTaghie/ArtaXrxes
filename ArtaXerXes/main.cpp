#include "mainwindow.h"
#include <QApplication>
#include "loby.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Loby l;
    thread t1(&Loby::data_sender, &l);
    t1.detach();

    return a.exec();
}
