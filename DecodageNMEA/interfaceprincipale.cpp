#include "interfaceprincipale.h"
#include "ui_interfaceprincipale.h"

InterfacePrincipale::InterfacePrincipale(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::InterfacePrincipale)

{
    ui->setupUi(this);
    QSettings settings("Touchard", "DecodageNMEA");
    labelEtatPort.setText("port fermé");
    ui->statusbar->addPermanentWidget(&labelEtatPort);
    ui->statusbar->show();
    if(settings.contains("liaison serie/Port"))
    {

       // QString port = settings.value("Port",lePort.portName());
       // int vitesse = settings.value("Vitesse", lePort.baudRate());
       // int parite =  settings.value("Parite", lePort.parity());
       // int bitStop = settings.value("BitStop",lePort.stopBits());
       // int dataBit = settings.value("BitData",lePort.dataBits());


        ui->statusbar->addPermanentWidget(&labelEtatPort);
        ui->statusbar->show();


        ui->tableWidgetNMEA->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }
}

InterfacePrincipale::~InterfacePrincipale()
{
    delete ui;
}

void InterfacePrincipale::DecodageNMEA(const QString _trameNMEA)
{
    QStringList champsNMEA = _trameNMEA.split(',');
    if (champsNMEA.size() >= 12 && champsNMEA.at(0) == "$GPRMC") {
        // Extraction de l'heure
        QString heureStr = champsNMEA.at(1);
        QTime heure(heureStr.mid(0, 2).toInt(),
                    heureStr.mid(2, 2).toInt(),
                    heureStr.mid(4, 2).toInt());
        // Extraction de la date (Exemple pour le champ date, en
        // supposant que le champ date est au format DDMMYY)
        QString dateStr = champsNMEA.at(9);
        QDate date(2000 + dateStr.mid(4, 2).toInt(),
                   dateStr.mid(2, 2).toInt(),
                   dateStr.mid(0, 2).toInt());
        // Création d'un horodatage
        QDateTime horodatage(date, heure, QTimeZone("Europe/Paris"));
        // Conversion locale si nécessaire
        horodatage = horodatage.toLocalTime();
        // Mise à jour de l'interface
        int ligneCourante = ui->tableWidgetNMEA->rowCount();
        ui->tableWidgetNMEA->insertRow(ligneCourante);
        ui->tableWidgetNMEA->setItem(ligneCourante, 0, new QTableWidgetItem(horodatage.toString(Qt::TextDate)));



    }
}

void InterfacePrincipale::on_actionEnregistrer_triggered()
{

}


void InterfacePrincipale::on_actionOuvrir_triggered()
{

}


void InterfacePrincipale::on_actionConfigurer_triggered()
{
    Dialog configGPS(lePort,this);
    if (configGPS.exec() == QDialog::Accepted)
    {
        QString message;
        QTextStream flux(&message);
        QString parite;

        switch(lePort.parity())
        {
        case QSerialPort::NoParity:
            parite = "n";
            break;
        case QSerialPort::EvenParity:
            parite = "p";
            break;
        case QSerialPort::OddParity:
            parite = "i";
            break;
        default:
            parite = "n";
        }

        QSettings settings("Touchard", "DecodageNMEA");
        settings.beginGroup("liaison serie");
        settings.setValue("Port",lePort.portName());
        settings.setValue("Vitesse", lePort.baudRate());
        settings.setValue("Parite", lePort.parity());
        settings.setValue("BitStop",lePort.stopBits());
        settings.setValue("BitData",lePort.dataBits());
        settings.endGroup();

        flux << "Port : " <<lePort.portName() << "," << lePort.baudRate() << "," << parite << "," << lePort.stopBits() << "," << lePort.dataBits();
        labelEtatPort.setText(message);
        lePort.open(QIODevice::ReadWrite);
        connect(&lePort,&QSerialPort::readyRead,this,&InterfacePrincipale::onQSerialPort_readyRead);
    }
}


void InterfacePrincipale::on_actionA_propos_de_triggered()
{

}

void InterfacePrincipale::onQSerialPort_readyRead()
{

    QByteArray data = lePort.readAll();
    trameCourante.append(data);

    while(trameCourante.contains("\n")){
        int retourChariot = trameCourante.indexOf("\n");
        QByteArray message = trameCourante.left(retourChariot);
        trameCourante.remove(0,retourChariot + 1 );
        ui->textEditTrameRecu->setText(message);
    }
    DecodageNMEA(trameCourante);
}

