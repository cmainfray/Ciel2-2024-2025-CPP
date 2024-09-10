#ifndef BARRE_H
#define BARRE_H

#include <iostream>
#include <string>


using namespace std;

class Barre
{
public:
    Barre(const string _reference, const string _nomAlliage, const int _longueur, const double _densite);
    virtual ~Barre();
    virtual void AfficherCaracteristique();
    virtual double CalculerMasse() = 0;


protected:
    string reference;
    string nomAlliage;
    int longueur;
    double densite;
};

#endif // BARRE_H
