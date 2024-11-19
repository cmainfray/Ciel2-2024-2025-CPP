#include "testalveoleslibres.h"
#include "ui_testalveoleslibres.h"
#include <QMessageBox>

TestAlveolesLibres::TestAlveolesLibres(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TestAlveolesLibres)
    , lesAlveoles(2,3)

{
    ui->setupUi(this);
}

TestAlveolesLibres::~TestAlveolesLibres()
{
    delete ui;
}

void TestAlveolesLibres::on_pushButtonQuitter_clicked()
{
    close();
}


void TestAlveolesLibres::on_pushButtonReserver_clicked()
{
    int rangee;
    int colonne;
    if(lesAlveoles.Reserver(rangee,colonne))
    {
        QString phrase;
        phrase = "Alvéole occupée en : ";
        ui->listWidgetAlveolesLibres->addItem(phrase + QString::number(rangee) + " , " + QString::number(colonne));
        ui->lineEditNumAlveole->clear();
    }
    else
    {
        QMessageBox messageErreur;
        messageErreur.setText("Le magasin est plein");
        messageErreur.exec();
    }
}


void TestAlveolesLibres::on_pushButtonLiberer_clicked()
{
    QListWidgetItem *currentItem = ui->listWidgetAlveolesLibres->currentItem();

    if(currentItem){
        QString texte = currentItem->text();
        QStringList parts = texte.split(": ");
        if(parts.size() == 2){
            QStringList position = parts[1].split(",");
            if(position.size() == 2){
                int rangee = position[0].toInt();
                int colonne = position[1].toInt();
                lesAlveoles.Liberer(rangee,colonne);
            }
        }
        delete ui->listWidgetAlveolesLibres->takeItem(ui->listWidgetAlveolesLibres->row(currentItem));
        ui->lineEditNumAlveole->setText("libre en : "+ parts[1]);
    }
}

