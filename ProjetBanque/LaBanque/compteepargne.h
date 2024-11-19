#ifndef COMPTEEPARGNE_H
#define COMPTEEPARGNE_H

#include "comptebancaire.h"
#include <iostream>

using namespace std;

class CompteEpargne : public CompteBancaire
{
public:
    CompteEpargne(const float _tauxInterets = 0.03, const float _solde = 0);
    void CalculerInterets();
    void ModifierTaux(const float _nouveauTaux);
private:
    float tauxInterets;
};

#endif // COMPTEEPARGNE_H
