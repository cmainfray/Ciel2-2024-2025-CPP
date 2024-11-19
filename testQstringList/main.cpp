#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QStringList names;
    names << "Alice" << "Bob" << "Charlie";
    qDebug() << "Liste originale :" << names;
    qDebug() << "Concatenation avec virgule :" << names.join(", ");
    qDebug() << "Filtrer les éléments contenant 'o' :" << names.filter("o");
}
