#include "stock.h"

Stock::Stock(){}

void Stock::AjouterRouleau(const Rouleau _nouveau)
{
    lesRouleaux.insert(_nouveau.getDiametre(), _nouveau);
}

int Stock::RechercherSerie(QMultiMap<int,Rouleau>::iterator &_positionDebut)
{
    auto positionPremier = lesRouleaux.begin();
    _positionDebut = lesRouleaux.begin();
    int retour = lesRouleaux.size();

    if(retour > 6)
    {
        retour = 6;
        auto positionDernier = lesRouleaux.begin();
        for(int indice = 0; indice < 6; indice++)
        {
            positionDernier++;
        }
        int valeurRetenue = (positionDernier.value().getDiametre() - positionPremier.value().getDiametre());
        while(positionDernier != lesRouleaux.end())
        {
            int ecart = (positionPremier.value().getDiametre() - positionPremier.value().getDiametre());
            if(ecart < valeurRetenue)
            {
                valeurRetenue = ecart;
                _positionDebut = positionPremier;
            }
            positionDernier++;
            positionPremier++;
        }
    }
    return retour;
}

bool Stock::RetirerRouleauDuStock(const QMultiMap<int,Rouleau>::iterator _positionRouleau)
{
    bool retour = false;
    if(_positionRouleau != lesRouleaux.end())
    {
        lesRouleaux.erase(_positionRouleau);
        retour = true;
    }
    return retour;
}

QStringList Stock::ObetenirContenuDuStock() const
{
    QStringList descriptionStock;
    for(auto it = lesRouleaux.begin(); it != lesRouleaux.end(); it++)
    {
        QString descriptionRouleau = QString("Référence : %1, Diamètre : %2")
                                       .arg(it.value().getReference())
                                       .arg(it.value().getDiametre());
        descriptionStock.append(descriptionRouleau);
    }
    return descriptionStock;
}
