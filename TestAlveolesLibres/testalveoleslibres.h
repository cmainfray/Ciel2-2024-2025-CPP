#ifndef TESTALVEOLESLIBRES_H
#define TESTALVEOLESLIBRES_H

#include <QWidget>
#include "alveoleslibres.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class TestAlveolesLibres;
}
QT_END_NAMESPACE

class TestAlveolesLibres : public QWidget
{
    Q_OBJECT

public:
    TestAlveolesLibres(QWidget *parent = nullptr);
    ~TestAlveolesLibres();

private slots:
    void on_pushButtonQuitter_clicked();

    void on_pushButtonReserver_clicked();

    void on_pushButtonLiberer_clicked();

private:
    Ui::TestAlveolesLibres *ui;
    AlveolesLibres lesAlveoles;
};
#endif // TESTALVEOLESLIBRES_H
