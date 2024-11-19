#include "compteepargne.h"

CompteEpargne::CompteEpargne(const float _tauxInterets, const float _solde):
    CompteBancaire(_solde),
    tauxInterets(_tauxInterets)
{}

void CompteEpargne::CalculerInterets()
{
    float interets =  solde * tauxInterets;
    solde += interets;
}

void CompteEpargne::ModifierTaux(const float _nouveauTaux)
{
    tauxInterets = _nouveauTaux;
}

