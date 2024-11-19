#include "mainwiget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWiget w;
    w.show();
    return a.exec();
}
