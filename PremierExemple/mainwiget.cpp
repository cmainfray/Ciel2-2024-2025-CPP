#include "mainwiget.h"
#include "ui_mainwiget.h"
#include <QMessageBox>

MainWiget::MainWiget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWiget)
{
    ui->setupUi(this);
}

MainWiget::~MainWiget()
{
    delete ui;
}

void MainWiget::on_pushButton_2_clicked()
{
    QMessageBox message;
    message.setText("bonjour");
    message.exec();
    ui->pushButton_2->setText("Bonjour");
    ui->groupBox->hide();
}

