/**
    @file main.cpp
    @version 1.0
    @author Camille Mainfray
    @date 5/09/2024
    */


#include "comptebancaire.h"

CompteBancaire::CompteBancaire(float _solde):
    solde(_solde)
{
}

void CompteBancaire::Deposer(float _montant)
{
    if(_montant > 0)
        solde += _montant;
}

bool CompteBancaire::Retirer(float _montant){
    if( _montant > 0 && solde >= _montant ){
        solde -= _montant;
        return true;
    }
    else
        return false;

}

float CompteBancaire::ConsulterSolde()
{
    return solde;
}

