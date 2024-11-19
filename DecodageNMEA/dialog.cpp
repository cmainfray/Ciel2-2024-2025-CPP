#include "dialog.h"
#include "ui_dialog.h"
#include <QPushButton>

Dialog::Dialog(QSerialPort &_lePort,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
    , lePort(_lePort)

{
    ui->setupUi(this);
    for(const auto &info : QSerialPortInfo::availablePorts() ) // foreach
    {
        qDebug() << info.portName();
        ui->comboBoxPort->addItem(info.portName());
    }
    ui->comboBoxVitesse->addItem("Choisissez la vitesse",0);
    ui->comboBoxVitesse->addItem("1200",QSerialPort::Baud1200);
    ui->comboBoxVitesse->addItem("2400",QSerialPort::Baud2400);
    ui->comboBoxVitesse->addItem("4800",QSerialPort::Baud4800);
    ui->comboBoxVitesse->addItem("9600",QSerialPort::Baud9600);
    ui->comboBoxVitesse->addItem("19200",QSerialPort::Baud19200);
    ui->comboBoxVitesse->addItem("38400",QSerialPort::Baud38400);
    ui->comboBoxVitesse->addItem("57600",QSerialPort::Baud57600);
    ui->comboBoxVitesse->addItem("115200",QSerialPort::Baud115200);
    int index9600 = ui->comboBoxVitesse->findData(QSerialPort::Baud9600);
    if(index9600 != -1)
        ui->comboBoxVitesse->setCurrentIndex(index9600);
    lePort.setBaudRate(QSerialPort::Baud9600);

    ui->spinBoxBitData->setMaximum(8);
    ui->spinBoxBitData->setMinimum(5);
    ui->spinBoxBitData->setValue(8);

    ui->radioButtonNone->setChecked(true);

    lePort.setStopBits(QSerialPort::OneStop);

    ui->comboBoxFlux->addItem("Pas de contrôle de flux");
    ui->comboBoxFlux->addItem("Matériel(RTS/CTS)");
    ui->comboBoxFlux->addItem("Logiciel(XON/XOFF)");
    ui->comboBoxFlux->setCurrentIndex(0);

    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_spinBoxBitData_valueChanged(int arg1)
{
    switch (arg1) {
    case 5:
        lePort.setDataBits(QSerialPort::Data5);
        break;
    case 6:
        lePort.setDataBits(QSerialPort::Data6);
        break;
    case 7:
        lePort.setDataBits(QSerialPort::Data7);
        break;
    case 8:
        lePort.setDataBits(QSerialPort::Data8);
    default:
        break;
    }
}


void Dialog::on_checkBoxStop_toggled(bool checked)
{
    if(checked == true)
    {
        lePort.setStopBits(QSerialPort::TwoStop);
    }
}


void Dialog::on_radioButtonPaire_toggled(bool checked)
{
    if(checked == true)
    {
        lePort.setParity(QSerialPort::EvenParity);
    }
}


void Dialog::on_radioButtonImpair_toggled(bool checked)
{
    if(checked == true)
    {
        lePort.setParity(QSerialPort::OddParity);
    }
}


void Dialog::on_radioButtonNone_toggled(bool checked)
{
    if(checked == true)
    {
        lePort.setParity(QSerialPort::NoParity);
    }
}


void Dialog::on_comboBoxVitesse_currentIndexChanged(int index)
{
    if(index>0)
    {
        QVariant data = ui->comboBoxVitesse->currentData();
        QSerialPort::BaudRate vitesse = static_cast<QSerialPort::BaudRate>(data.toInt());

        if(lePort.setBaudRate(vitesse))
        {
            qDebug() << "Vitesse : " << vitesse;
        }
        else
        {
            qDebug() << "Vitesse : config impossible";
        }
    }
}

void Dialog::on_comboBoxPort_currentIndexChanged(int index)
{
    if(index > 0){
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
        qDebug() << ui->comboBoxPort->currentText();
        lePort.setPortName(ui->comboBoxPort->currentText());
    }
}
