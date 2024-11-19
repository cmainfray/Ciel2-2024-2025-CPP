#ifndef ELEMENT_H
#define ELEMENT_H
#include <iostream>
#include <iomanip>
#include <istream>
#include "vecteur.h"
using namespace std;

class Element
{
public:
    Element();
    virtual ~Element();
    virtual void  Afficher() = 0;
    virtual int ObtenirLongueur() = 0;
    virtual int ObtenirDuree() = 0;
    virtual Vecteur ObtenirVecteurArrivee() = 0;

    int getNumero() const;
    void setNumero(int newNumero);

protected:
    int numero;
    int vitesse;
};

#endif // ELEMENT_H
