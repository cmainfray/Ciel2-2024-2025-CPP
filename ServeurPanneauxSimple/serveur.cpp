#include "serveur.h"
#include "ui_serveur.h"

Serveur::Serveur(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Serveur)
    ,indexMessage(0)
    ,alerte(false)
    ,alternanceAlerte(false)
    ,datagram(QByteArray(), QHostAddress::Broadcast, 45479)

{
    ui->setupUi(this);
    socketServeur = new QUdpSocket(this);
    connect(&timerHeure,&QTimer::timeout,this,&Serveur::onTimerHeure_timeout);
    timerHeure.start(60000);


}

Serveur::~Serveur()
{
    delete socketServeur;
    delete ui;
}

void Serveur::on_pushButtonDiffuser_clicked()
{
    if(ui->pushButtonDiffuser->text() == "Lancer la diffusion"){
        QByteArray datagram = ui->textEditInformation->toPlainText().toUtf8();
        socketServeur->writeDatagram(datagram, QHostAddress("127,0,0,1"), 45479);
        //socketServeur->writeDatagram(datagram, QHostAddress("224.0.1.1"), 45490);
        ui->pushButtonDiffuser->setText("Arrêter la diffusion");


        connect(&timerInformation,&QTimer::timeout,this,&Serveur::onTimerInformation_timeout);

        timerInformation.start(10000);

    }
    else
    {
        ui->pushButtonDiffuser->setText("Lancer la diffusion");
        timerHeure.stop();
        timerInformation.stop();
    }
}


void Serveur::on_pushButtonAjouterMessage_clicked()
{
    QString information = ui->textEditInformation->toPlainText();
    ui->listWidgetMessage->addItem(information);
    ui->textEditInformation->clear();
}


void Serveur::on_pushButtonCreerAlerte_clicked()
{
    if(ui->pushButtonCreerAlerte->text() == "Créer une alerte")
    {
        alerte = true;
        ui->pushButtonCreerAlerte->setText("Supprimer l'alerte");
    }
    else
    {
        alerte = false;
        ui->pushButtonCreerAlerte->setText("Créer une alerte");
    }
}


void Serveur::on_pushButtonSupprimer_clicked()
{
    QListWidgetItem *item = ui->listWidgetMessage->currentItem();
    if(item){
        delete item;
    }
    else{
        QMessageBox::warning(this,"Erreur","Vous devez sélectionner le message à supprimer");
    }
}

void Serveur::onTimerHeure_timeout()
{
    QTime heure = QTime::currentTime(); // donne l’heure courante
    QString heureStr = heure.toString("HH:mm");
    QByteArray buffer;
    QDataStream out(&buffer, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_0);
    out << "H" << heureStr;
    EnvoyerDatagram(buffer);

}

void Serveur::onTimerInformation_timeout()
{
    QByteArray buffer;
    QDataStream out(&buffer, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_0);
    QListWidgetItem *item = ui->listWidgetMessage->item(indexMessage);
    out << "I" <<item->text();

    EnvoyerDatagram(buffer);
    indexMessage++;
    if(indexMessage == ui->listWidgetMessage->count()){
        indexMessage = 0;
    }

}


void Serveur::EnvoyerDatagram(const QByteArray data)
{
    datagram.setData(data); // Configure les données à envoyer
    if (socketServeur->writeDatagram(datagram) == -1) {
        qDebug() << "Erreur lors de l'envoi du datagram :" << socketServeur->errorString();
    } else {
        qDebug() << "Datagram envoyé avec succès : " << data;
    }
}




void Serveur::on_pushButtonModifierMeteo_clicked()
{
    QByteArray buffer;
    QDataStream out(&buffer, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_0);
    out << "M" << ui->lineEditMeteo->text();
    EnvoyerDatagram(buffer);
}

