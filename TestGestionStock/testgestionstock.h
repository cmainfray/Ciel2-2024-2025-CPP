#ifndef TESTGESTIONSTOCK_H
#define TESTGESTIONSTOCK_H

#include <QWidget>
#include "stock.h"

#include <QFile>
#include <QDataStream>
#include <QDebug>
#include <QTextStream>
#include <QIODevice>

QT_BEGIN_NAMESPACE
namespace Ui {
class TestGestionStock;
}
QT_END_NAMESPACE

class TestGestionStock : public QWidget
{
    Q_OBJECT

public:
    TestGestionStock(QWidget *parent = nullptr);
    ~TestGestionStock();

private slots:
    void on_pushButtonNouveau_clicked();

    void on_pushButtonQuitter_clicked();

    void on_pushButtonRetrait_clicked();

    void on_pushButtonSuppression_clicked();

    void on_pushButtonSauvegarder_clicked();

    void on_pushButtonCharger_clicked();

private:
    Ui::TestGestionStock *ui;
    int nbRouleaux;
    QMultiMap<int,Rouleau>::iterator debut;
    Stock leStock;
};
#endif // TESTGESTIONSTOCK_H
