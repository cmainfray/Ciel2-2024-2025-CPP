#ifndef CALCULATRICE_H
#define CALCULATRICE_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui {
class Calculatrice;
}
QT_END_NAMESPACE

class Calculatrice : public QWidget
{
    Q_OBJECT

public:
    Calculatrice(QWidget *parent = nullptr);
    ~Calculatrice();

private slots:
    void onQPushButtonClicked();

private:
    Ui::Calculatrice *ui;
    int NB_TOUCHES;
    QGridLayout *grille;
    QPushButton **touches;
    QLineEdit *afficheur;
};
#endif // CALCULATRICE_H
