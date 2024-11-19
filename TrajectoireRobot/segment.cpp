#include "segment.h"
#include <math.h>

Segment::Segment(const double _longueur, const double _angle, const int _vitesse):
    longueur(_longueur) ,
    angle(_angle),
    vitesse(_vitesse),
    duree(longueur/vitesse),
    vecteur(longueur*cos(angle),longueur*sin(angle))
{}

void Segment::Afficher()
{
    cout << left <<"(" << numero <<")" << " " << "SEGMENT L = "  << setw(10) <<longueur << "A = " << setw(10) << angle  << "V = " << setw(10) << vitesse << endl;
    cout << "Vecteur en (" << vecteur << ")" << endl;
    cout << "Durée totale du parcours = " << endl;
    cout << "Longueur totale du parcours = " << endl << endl;
}

int Segment::ObtenirLongueur()
{
    return longueur;
}

int Segment::ObtenirDuree()
{
    return duree;
}

Vecteur Segment::ObtenirVecteurArrivee()
{
    return vecteur;
}

