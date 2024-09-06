#include <iostream>
#include "barre.h"
#include "barreronde.h"

using namespace std;

int main()
{
    Barre uneBarre("B145","Latton",200,8.5);
    uneBarre.AfficherCaracteristique();
    BarreRonde uneBarreRonde("B1568","Métal",1000, 2.8, 56.68);
    uneBarreRonde.AfficherCaracteristique();
    return 0;
}
