#include "rouleau.h"

Rouleau::Rouleau(){}

Rouleau::Rouleau(const Rouleau &_autre)
{
    diametre = _autre.diametre;
    reference = _autre.reference;
    colonne = _autre.colonne;
    rangee = _autre.rangee;
}

Rouleau::Rouleau(const QString _reference, const int _diametre):
    reference(_reference),
    diametre(_diametre)
{
}

Rouleau &Rouleau::operator=(const Rouleau& _autre)
{
    if(this != &_autre)
    {
        diametre = _autre.diametre;
        reference = _autre.reference;
        colonne = _autre.colonne;
        rangee = _autre.rangee;
    }
}

Rouleau::~Rouleau()
{
}

QString Rouleau::getReference() const
{
    return reference;
}

int Rouleau::getDiametre() const
{
    return diametre;
}

void Rouleau::AffecterLocalisation(const int _rangee, const int _colonne)
{
    rangee = _rangee;
    colonne = _colonne;
}

void Rouleau::ObtenirLocalisation(int &_rangee, int &_colonne) const
{
    _rangee = rangee;
    _colonne = colonne;
}


