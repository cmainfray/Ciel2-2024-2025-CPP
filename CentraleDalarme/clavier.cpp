#include "clavier.h"
#include "ui_clavier.h"
#include <QMessageBox>
#include <QDebug>

Clavier::Clavier(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Clavier),
    leDetecteur(nullptr)
{
    ui->setupUi(this);
    QList<QPushButton*> allButtons = this->findChildren<QPushButton*>();
    foreach(QPushButton* button, allButtons) {
        if(button->text() != "Marche" && button->text() != "Arrêt" ) {
            connect(button, &QPushButton::clicked, this, &Clavier::TraiterChiffre);
        }


    }
     connect(&timerLed,&QTimer::timeout,this,&Clavier::onTimerLed_timeout);

}

Clavier::~Clavier()
{
    delete ui;
}

void Clavier::onTimerLed_timeout()
{
    if(ui->checkBoxLedRouge->checkState() == Qt::Checked)
        ui->checkBoxLedRouge->setCheckState(Qt::Unchecked);
    else
        ui->checkBoxLedRouge->setCheckState(Qt::Checked);
}
void Clavier::TraiterChiffre()
{
    // QPushButton *pbouton = static_cast<QPushButton *>(sender());
    // QString texteBouton = pbouton -> text();
    // QMessageBox messageChiffre;
    // messageChiffre.setText("j'ai appuyé sur la touche " + texteBouton);
    // messageChiffre.exec();
}




void Clavier::on_pushButtonMarche_pressed()
{
    // QString texteBouton = ui->pushButtonMarche->text();
    // QMessageBox messageMarche;
    // messageMarche.setText("j'ai appuyé sur la touche " + texteBouton);
    // messageMarche.exec();
    // ui->checkBoxLedRouge->setCheckState(Qt::Checked);
    // timerLed.start(500);
}


void Clavier::on_pushButtonMarche_released()
{

}


void Clavier::on_pushButtonArret_clicked()
{
    // QString texteBouton = ui->pushButtonArret->text();
    // QMessageBox messageArret;
    // messageArret.setText("j'ai appuyé sur la touche " + texteBouton);
    // messageArret.exec();
    ui->checkBoxLedRouge->setCheckState(Qt::Unchecked);
    timerLed.stop();
}


void Clavier::on_pushButtonMarche_clicked()
{
    timerLed.start(500);
}




void Clavier::on_pushButton2_clicked()
{
    leDetecteur = new Detecteur;
    leDetecteur->show();



}


void Clavier::on_pushButton3_clicked()
{
    if(leDetecteur != nullptr){
    leDetecteur->hide();
    delete leDetecteur;
    leDetecteur = nullptr;
    }
}

