#ifndef LIAISONSERIE_H
#define LIAISONSERIE_H

#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QList>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class LiaisonSerie;
}
QT_END_NAMESPACE

class LiaisonSerie : public QWidget
{
    Q_OBJECT

public:
    LiaisonSerie(QWidget *parent = nullptr);
    ~LiaisonSerie();

private slots:
    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_pushButtonPortSerie_clicked();

    void on_pushButtonEnvoyer_clicked();

    void onQSerialPort_readyRead();
private:
    Ui::LiaisonSerie *ui;
    QSerialPort lePortSerie;

};
#endif // LIAISONSERIE_H
