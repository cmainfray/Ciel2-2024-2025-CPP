#include "barre.h"

Barre::Barre(const string _reference, const string _nomAlliage, const int _longueur, const float _densite):
    reference(_reference),
    nomAlliage(_nomAlliage),
    longueur(_longueur),
    densite(_densite)
{}

void Barre::AfficherCaracteristique()
{
    cout << "Reférence de la barre : " << reference << endl;
    cout << "Nom de l'alliage de la barre : " << nomAlliage << endl;
    cout << "Longueur de la barre : " << longueur << endl;
    cout << "Densité de la  barre : " << densite << endl;
}
