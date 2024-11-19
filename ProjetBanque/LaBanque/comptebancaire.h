/**
    @file main.cpp
    @version 1.0
    @author Camille Mainfray
    @date 5/09/2024
    */


#ifndef COMPTEBANCAIRE_H
#define COMPTEBANCAIRE_H

class CompteBancaire
{
public:
    CompteBancaire(float _solde);
    void Deposer(float _montant);
    bool Retirer(float _montant);
    float ConsulterSolde();
protected:
    float solde;
};

#endif // COMPTEBANCAIRE_H
