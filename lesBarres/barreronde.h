#ifndef BARRERONDE_H
#define BARRERONDE_H
#include <string>
#include <iostream>
#include "barre.h"

using namespace std;

class BarreRonde : public Barre
{
public:
    BarreRonde(const string _reference, const string _nomAlliage, const int _longueur, const double _densite, double _diametre);
    virtual void AfficherCaracteristique();
    double CalculerSection();
    virtual double CalculerMasse();
private:
    double diametre;
};

#endif // BARRERONDE_H
