#ifndef SERVEUR_H
#define SERVEUR_H

#include <QWidget>
#include <QUdpSocket>
#include <QMessageBox>
#include <QNetworkDatagram>
#include <QTimer>
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui {
class Serveur;
}
QT_END_NAMESPACE

class Serveur : public QWidget
{
    Q_OBJECT

public:
    Serveur(QWidget *parent = nullptr);
    ~Serveur();

private slots:
    void on_pushButtonDiffuser_clicked();

    void on_pushButtonAjouterMessage_clicked();

    void on_pushButtonCreerAlerte_clicked();

    void on_pushButtonSupprimer_clicked();

    void onTimerHeure_timeout();

    void onTimerInformation_timeout();

    void EnvoyerDatagram(const QByteArray data);

    void on_pushButtonModifierMeteo_clicked();

private:
    Ui::Serveur *ui;
    QUdpSocket *socketServeur;
    QNetworkDatagram datagram;

    int indexMessage;
    bool alerte;
    bool alternanceAlerte;
    QTimer timerInformation;
    QTimer timerHeure;
};
#endif // SERVEUR_H
