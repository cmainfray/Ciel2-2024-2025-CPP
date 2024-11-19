#ifndef DETECTEURTEMPORISE_H
#define DETECTEURTEMPORISE_H

#include "detecteur.h"

class DetecteurTemporise : public Detecteur
{
public:
    DetecteurTemporise();

private slots:

    void on_pushButton_clicked();
    void onTimerIntru_timeout();

private:
     QTimer timerIntru;
};

#endif // DETECTEURTEMPORISE_H
