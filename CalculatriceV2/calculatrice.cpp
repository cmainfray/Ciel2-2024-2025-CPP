#include "calculatrice.h"
#include "ui_calculatrice.h"
#include <QJSEngine>

Calculatrice::Calculatrice(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Calculatrice)
{
    ui->setupUi(this);
    QList<QPushButton*> allButtons = this->findChildren<QPushButton*>();
    foreach(QPushButton* button, allButtons) {
        if(button->text() != "=" && button->text() != "C") {
            connect(button, &QPushButton::clicked, this, &Calculatrice::onQPushButtonClicked);
        }else if(button->text() == "="){
            connect(button, &QPushButton::clicked, this, &Calculatrice::on_pushButtonEgal_clicked);
        }
        else if(button->text() == "C"){
            connect(button, &QPushButton::clicked, this, &Calculatrice::on_pushButtonEffacer_clicked);
        }
    }

}

Calculatrice::~Calculatrice()
{
    delete ui;
}

void Calculatrice::onQPushButtonClicked()
{
    QPushButton *touche;
    touche=qobject_cast<QPushButton*>(sender());
    QString val;
    val=touche->text();
    ui->lineEditAfficheur->setText(ui->lineEditAfficheur->text()+ val);

}


void Calculatrice::on_pushButtonEgal_clicked()
{
    QJSEngine expression;
    ui->lineEditAfficheur->setText(expression.evaluate(ui->lineEditAfficheur->text()).toString());
}


void Calculatrice::on_pushButtonEffacer_clicked()
{
    ui -> lineEditAfficheur -> clear();
}


