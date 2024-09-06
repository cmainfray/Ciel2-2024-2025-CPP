#ifndef BARRERONDE_H
#define BARRERONDE_H
#include <string>
#include <iostream>
#include "barre.h"

using namespace std;

class BarreRonde : public Barre
{
public:
    BarreRonde(const string _reference, const string _nomAlliage, const int _longueur, const float _densite,double _diametre);
    void AfficherCaracteristique();
    double CalculerSection();
    double CalculerMasse();
private:
    string reference;
    string nomAlliage;
    int longueur;
    float densite;
    double diametre;
};

#endif // BARRERONDE_H
