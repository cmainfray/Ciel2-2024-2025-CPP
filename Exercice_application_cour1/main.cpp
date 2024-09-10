#include <iostream>
#include "barre.h"
#include "barreronde.h"
#include "barrecarre.h"

using namespace std;

int main()
{
    Barre uneBarre("B145","Latton",200,8.5);
    uneBarre.AfficherCaracteristique();
    cout << endl;

    BarreRonde uneBarreRonde("B1568","Métal",200, 8.5, 10);
    uneBarreRonde.AfficherCaracteristique();
    cout << "La section est : " << uneBarreRonde.CalculerSection() << "cm2" << endl;
    cout << "la masse est : " << uneBarreRonde.CalculerMasse() << "kg" << endl << endl;

    BarreCarre uneBarreCarre("B172", "Acier", 200, 8.5, 5);
    uneBarreCarre.AfficherCaracteristique();
    cout << "La section est : " << uneBarreCarre.CalculerSection() << "cm2" << endl;
    cout << "la masse est : " << uneBarreCarre.CalculerMasse() << "kg" << endl <<endl;
    return 0;
}
