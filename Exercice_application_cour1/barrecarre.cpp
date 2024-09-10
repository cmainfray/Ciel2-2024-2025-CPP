#include "barrecarre.h"

BarreCarre::BarreCarre(const string _reference, const string _nomAlliage, const int _longueur, const double _densite, const int _cote):
    Barre(_reference,_nomAlliage,_longueur,_densite),
    cote(_cote)
{}

void BarreCarre::AfficherCaracteristique()
{
    Barre::AfficherCaracteristique();
    cout << "Coté de la barre carée : " << cote << "cm" << endl;
}

double BarreCarre::CalculerSection()
{
    return (cote * cote);
}

double BarreCarre::CalculerMasse()
{
    return (CalculerSection() * longueur * densite)/1000.0;
}
