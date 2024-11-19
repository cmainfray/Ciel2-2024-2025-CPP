#include "testgestionstock.h"
#include "ui_testgestionstock.h"

TestGestionStock::TestGestionStock(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TestGestionStock)
{
    ui->setupUi(this);
}

TestGestionStock::~TestGestionStock()
{
    delete ui;
}

void TestGestionStock::on_pushButtonNouveau_clicked()
{
    QString reference = ui->lineEditReference->text();
    int diametre = ui->lineEditDiametre->text().toInt();

    if(!reference.isEmpty() && diametre > 0)
    {
        Rouleau nouveauRouleau(reference, diametre);
        leStock.AjouterRouleau(nouveauRouleau);

        ui->listWidgetStock->clear();
        QStringList descriptionStock = leStock.ObetenirContenuDuStock();
        ui->listWidgetStock->addItems(descriptionStock);
    }
}


void TestGestionStock::on_pushButtonRetrait_clicked()
{
    nbRouleaux = leStock.RechercherSerie(debut);
    ui->listWidgetRouleauxRetenus->clear();
    auto posDebut = debut;

    for(int indice = 0 ; indice < nbRouleaux; ++indice)
    {
        QString descriptionRetenus = QString("Référence : %1, Diamètre : %2")
                                            .arg(posDebut.value().getReference())
                                            .arg(posDebut.value().getDiametre());
        posDebut++;
        ui->listWidgetRouleauxRetenus->addItem(descriptionRetenus);
    }
}


void TestGestionStock::on_pushButtonSuppression_clicked()
{
    auto posDebut = debut;

    for(int indice = 0; indice < nbRouleaux; ++indice)
    {
        posDebut++;
        leStock.RetirerRouleauDuStock(debut);
        debut = posDebut;
    }
    ui->listWidgetStock->clear();
    QStringList descriptionStock = leStock.ObetenirContenuDuStock();
    ui->listWidgetStock->addItems(descriptionStock);
    ui->listWidgetRouleauxRetenus->clear();
}


void TestGestionStock::on_pushButtonQuitter_clicked()
{
    close();
}


void TestGestionStock::on_pushButtonSauvegarder_clicked()
{
    // QString fileName = QFileDialog::getSaveFileName(this,
    //                                                 tr("Enregistrer un fichier"),
    //                                                 "/home/USERS/ELEVES/CIEL2023/cmainfray/Ciel2-2024-2025-CPP/TestGestionStock/untitled.txt",
    //                                                 tr("Fichiers texte (*.txt);;Tous les fichiers (*)"));
    // if (!fileName.isEmpty()) {
    //     QFile file(fileName);
    //     if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
    //         QTextStream out(&file);
    //         out << "Contenu à sauvegarder";
    //     }
    // }
}


void TestGestionStock::on_pushButtonCharger_clicked()
{

}

