#include <iostream>
#include "barrecarre.h"
#include "barreronde.h"

using namespace std;

int main(int argc, char *argv[])
{
    BarreCarree uneBarre("Barre 2x2 en Cuivre", 200, 8.920, 2);
    uneBarre.AfficherCaracteristiques();
    cout << "Le poids de la barre est : " ;
    cout << uneBarre.CalculerMasse() / 1000.0;
    cout << " kg" << endl;
    cout << endl;
    return 0;
}
