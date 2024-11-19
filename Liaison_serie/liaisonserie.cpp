#include "liaisonserie.h"
#include "ui_liaisonserie.h"


LiaisonSerie::LiaisonSerie(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LiaisonSerie)
{
    ui->setupUi(this);
    for(const auto &info : QSerialPortInfo::availablePorts() ) // foreach
    {
        qDebug() << info.portName();
        ui->comboBox->addItem(info.portName());
        ui->pushButtonEnvoyer->setDisabled(true);
    }

}

LiaisonSerie::~LiaisonSerie()
{
    delete ui;
}


void LiaisonSerie::on_comboBox_currentTextChanged(const QString &arg1)
{
    lePortSerie.setPortName(arg1);
}


void LiaisonSerie::on_pushButtonPortSerie_clicked()
{

    if(ui->pushButtonPortSerie->text() == "Ouvrir le port série"){

        lePortSerie.setBaudRate(QSerialPort::Baud115200);
        lePortSerie.setDataBits(QSerialPort::Data8);
        lePortSerie.setParity(QSerialPort::NoParity);
        lePortSerie.setStopBits(QSerialPort::OneStop);
        lePortSerie.setFlowControl(QSerialPort::NoFlowControl);

        lePortSerie.open(QIODevice::ReadWrite);
        connect(&lePortSerie,
                &QSerialPort::readyRead,
                this,
                &LiaisonSerie::onQSerialPort_readyRead);

        ui->pushButtonPortSerie->setText("Fermer le port");
        ui->pushButtonEnvoyer->setDisabled(false);
        qDebug() << "Port ouvert";
    }
    else{
        lePortSerie.close();

        ui->pushButtonPortSerie->setText("Ouvrir le port série");

        ui->pushButtonEnvoyer->setDisabled(true);
        qDebug() << "Port fermer";
    }
}


void LiaisonSerie::on_pushButtonEnvoyer_clicked()
{
   QByteArray message =  ui->lineEdit->text().toUtf8();
    lePortSerie.write(message);
    qDebug() << message;

}

void LiaisonSerie::onQSerialPort_readyRead()
{
    QByteArray data = lePortSerie.readAll();
    ui->textEdit->insertPlainText(data);
    qDebug() << data;

}

