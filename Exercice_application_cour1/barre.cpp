#include "barre.h"

Barre::Barre(const string _reference, const string _nomAlliage, const int _longueur, const double _densite):
    reference(_reference),
    nomAlliage(_nomAlliage),
    longueur(_longueur),
    densite(_densite)
{}

void Barre::AfficherCaracteristique() const
{
    cout << "Reférence de la barre : " << reference << endl;
    cout << "Nom de l'alliage de la barre : " << nomAlliage << endl;
    cout << "Longueur de la barre : " << longueur << "cm" << endl;
    cout << "Densité de la  barre : " << densite << "g/cm3"<< endl;
}
