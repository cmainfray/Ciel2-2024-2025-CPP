#ifndef SEGMENT_H
#define SEGMENT_H
#include "element.h"
#include <iostream>

class Segment : public Element
{
public:
    Segment(const double _longueur, const double _angle, const int _vitesse);
    void Afficher();
    int ObtenirLongueur();
    int ObtenirDuree();
    Vecteur ObtenirVecteurArrivee();
private:
    double longueur;
    double angle;
    int vitesse;
    int duree;
    Vecteur vecteur;
};

#endif // SEGMENT_H
