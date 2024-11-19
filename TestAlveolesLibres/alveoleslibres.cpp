#include "alveoleslibres.h"
#include <QDebug>
AlveolesLibres::AlveolesLibres(int const _nbRangees,int const _nbColonnes):
    nbRangees(_nbRangees),
    nbColonnes(_nbColonnes)
{
    reserve(200);
    for(int i = 1 ; i <= nbRangees * nbColonnes; i++){
        push(i);
    }
    qDebug() <<"Dans le constructeur" << *this;
}

bool AlveolesLibres::Reserver(int &_rangee, int &_colonne)
{
    int numAlveole;
    bool retour = false;
    if(!isEmpty()){
        numAlveole = pop();
        _rangee = (numAlveole - 1) / nbColonnes + 1;
        _colonne = (numAlveole - 1) % nbColonnes + 1;
        retour = true;
    }
    qDebug() <<"Dans la méthode Reserver" << *this;
    return retour;
}



void AlveolesLibres::Liberer(const int _rangee, const int _colonne)
{
    int numAlveole = nbColonnes * (_rangee-1) + _colonne;
    if(contains(numAlveole) != true)
    {
        push(numAlveole);
    }
    qDebug() << "Dans la méthode Liberer" << *this;
}
