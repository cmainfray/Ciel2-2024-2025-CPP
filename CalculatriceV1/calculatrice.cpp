#include "calculatrice.h"
#include "ui_calculatrice.h"
#include <QJSEngine>

Calculatrice::Calculatrice(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Calculatrice)
{
    ui->setupUi(this);
}

Calculatrice::~Calculatrice()
{
    delete ui;
}

void Calculatrice::on_pushButton0_clicked()
{
    QString expression = ui->lineEditAfficheur->text() + "0";
    ui->lineEditAfficheur->setText(expression);
}


void Calculatrice::on_pushButton1_clicked()
{
    QString expression = ui->lineEditAfficheur->text() + "1";
    ui->lineEditAfficheur->setText(expression);
}


void Calculatrice::on_pushButton2_clicked()
{
    QString expression = ui->lineEditAfficheur->text() + "2";
    ui->lineEditAfficheur->setText(expression);
}


void Calculatrice::on_pushButton3_clicked()
{
    QString expression = ui->lineEditAfficheur->text() + "3";
    ui->lineEditAfficheur->setText(expression);
}


void Calculatrice::on_pushButton4_clicked()
{
    QString expression = ui->lineEditAfficheur->text() + "4";
    ui->lineEditAfficheur->setText(expression);
}


void Calculatrice::on_pushButton5_clicked()
{
    QString expression = ui->lineEditAfficheur->text() + "5";
    ui->lineEditAfficheur->setText(expression);
}


void Calculatrice::on_pushButton6_clicked()
{
    QString expression = ui->lineEditAfficheur->text() + "6";
    ui->lineEditAfficheur->setText(expression);
}


void Calculatrice::on_pushButton7_clicked()
{
    QString expression = ui->lineEditAfficheur->text() + "7";
    ui->lineEditAfficheur->setText(expression);
}


void Calculatrice::on_pushButton8_clicked()
{
    QString expression = ui->lineEditAfficheur->text() + "8";
    ui->lineEditAfficheur->setText(expression);
}


void Calculatrice::on_pushButton9_clicked()
{
    QString expression = ui->lineEditAfficheur->text() + "9";
    ui->lineEditAfficheur->setText(expression);
}


void Calculatrice::on_pushButtonAdditionner_clicked()
{
    QString expression = ui->lineEditAfficheur->text() + "+";
    ui->lineEditAfficheur->setText(expression);
}


void Calculatrice::on_pushButtonSoustraire_clicked()
{
    QString expression = ui->lineEditAfficheur->text() + "-";
    ui->lineEditAfficheur->setText(expression);
}


void Calculatrice::on_pushButtonMultiplier_clicked()
{
    QString expression = ui->lineEditAfficheur->text() + "*";
    ui->lineEditAfficheur->setText(expression);
}


void Calculatrice::on_pushButtonDiviser_clicked()
{
    QString expression = ui->lineEditAfficheur->text() + "/";
    ui->lineEditAfficheur->setText(expression);
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

