#include "panneau.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Panneau w;
    w.show();
    return a.exec();
}
