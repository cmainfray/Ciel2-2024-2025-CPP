#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSerialPort>
#include <QSerialPortInfo>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QSerialPort &_lePort, QWidget *parent = nullptr);
    ~Dialog();

private slots:

    void on_spinBoxBitData_valueChanged(int arg1);

    void on_checkBoxStop_toggled(bool checked);

    void on_radioButtonPaire_toggled(bool checked);

    void on_radioButtonImpair_toggled(bool checked);

    void on_radioButtonNone_toggled(bool checked);

    void on_comboBoxVitesse_currentIndexChanged(int index);

    void on_comboBoxPort_currentIndexChanged(int index);

private:
    Ui::Dialog *ui;
    QSerialPort &lePort;
};

#endif // DIALOG_H
