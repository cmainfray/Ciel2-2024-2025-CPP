#include "detecteur.h"
#include "ui_detecteur.h"
#include <QMessageBox>
#include <QTimer>

Detecteur::Detecteur(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Detecteur)
{
    ui->setupUi(this);
    setWindowTitle("Le Détecteur");
}

Detecteur::~Detecteur()
{
    delete ui;
}

void Detecteur::on_pushButtonIntrus_clicked()
{
    QMessageBox messageIntru;
    messageIntru.setText("Un intrus a été détecté");

    messageIntru.exec();
}


