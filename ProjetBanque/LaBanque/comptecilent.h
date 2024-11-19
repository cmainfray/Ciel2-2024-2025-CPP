#ifndef COMPTECILENT_H
#define COMPTECILENT_H
#include <string>
#include "comptebancaire.h"
#include "compteepargne.h"

using namespace std;

class CompteCilent
{
public:
    CompteCilent(string _nom, int _numero);
    ~CompteCilent();
    void OuvrirCompteEpargne();
    void GererCompteBancaire();
    void GererCompteEpargne();
private:
    CompteBancaire *comptebancaire;
    CompteEpargne *compteepargne;
    string nom;
    int numero;
};

#endif // COMPTECILENT_H
