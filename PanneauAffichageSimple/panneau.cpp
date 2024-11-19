#include "panneau.h"
#include "ui_panneau.h"

Panneau::Panneau(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Panneau)


{
    ui->setupUi(this);
    socketClient = new QUdpSocket(this);
    if(socketClient->bind(45479, QUdpSocket::ShareAddress))
    {
        connect(socketClient, &QUdpSocket::readyRead, this, &Panneau::RecevoirMessage);
        qDebug() << "Client prêt à recevoir des messages sur le port 45479";
    }
    else {
        qDebug() << "Erreur de liaison du client au port 45479";
    }
}

Panneau::~Panneau()
{
    delete ui;
}

void Panneau::RecevoirMessage()
{
    while (socketClient->hasPendingDatagrams()) {
        QByteArray buffer;
        buffer.resize(socketClient->pendingDatagramSize());

        QHostAddress sender;
        quint16 senderPort;

        socketClient->readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);
        ui->textEditMessage->append(QString::fromUtf8(buffer));
        qDebug() << "Reçu de" << sender.toString() << ":" << senderPort << "Données:" << buffer;

        // if (socketClient->bind(45479, QUdpSocket::ShareAddress)) {
        //     if (socketClient->joinMulticastGroup(QHostAddress("224.0.1.1"))) {
        //         connect(socketClient, &QUdpSocket::readyRead, this, &Panneau::RecevoirMessage);
        //         qDebug() << "Client rejoint le groupe multicast et est prêt à recevoir des messages";
        //     } else {
        //         qDebug() << "Erreur : impossible de rejoindre le groupe multicast";
        //     }
        // } else {
        //     qDebug() << "Erreur de liaison du client au port 45454";
        // }
    }
}
