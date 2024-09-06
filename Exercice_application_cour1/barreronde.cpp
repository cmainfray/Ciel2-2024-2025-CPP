#include "barreronde.h"
#include <math.h>
BarreRonde::BarreRonde(const string _reference, const string _nomAlliage, const int _longueur, const float _densite, double _diametre):
    Barre(_reference,_nomAlliage,_longueur,_densite),
    diametre(_diametre)
{}

void BarreRonde::AfficherCaracteristique()
{
    Barre::AfficherCaracteristique();
    cout << "diametre : " << diametre << endl;
}

double BarreRonde::CalculerSection()
{
    return(M_PI *(diametre * diametre)/4);
}

double BarreRonde::CalculerMasse()
{
    return CalculerSection() * longueur * densite;
}

