#ifndef INTERFACEPRINCIPALE_H
#define INTERFACEPRINCIPALE_H

#include <QMainWindow>
#include <QIODevice>
#include <QSerialPort>
#include <QFile>
#include <QLabel>
#include <QSettings>
#include <QDir>
#include <QTimeZone>


#include "dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class InterfacePrincipale;
}
QT_END_NAMESPACE

class InterfacePrincipale : public QMainWindow
{
    Q_OBJECT

public:
    InterfacePrincipale(QWidget *parent = nullptr);
    ~InterfacePrincipale();
    void DecodageNMEA(const QString _trameNMEA);

private slots:
    void on_actionEnregistrer_triggered();

    void on_actionOuvrir_triggered();

    void on_actionConfigurer_triggered();

    void on_actionA_propos_de_triggered();

    void onQSerialPort_readyRead();

private:
    Ui::InterfacePrincipale *ui;

    Dialog *configGPS;
    QSerialPort lePort;

    QLabel labelEtatPort;
    QByteArray trameCourante;
};
#endif // INTERFACEPRINCIPALE_H
