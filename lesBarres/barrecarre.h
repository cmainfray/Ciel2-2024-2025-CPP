#ifndef BARRECARRE_H
#define BARRECARRE_H
#include <string>
#include <iostream>
#include "barre.h"


class BarreCarre : public Barre
{
public:
    BarreCarre(const string _reference, const string _nomAlliage, const int _longueur, const double _densite , const int _cote);
    virtual void AfficherCaracteristique();
    double CalculerSection();
    virtual double CalculerMasse();
private:
    int cote;
};

#endif // BARRECARRE_H
