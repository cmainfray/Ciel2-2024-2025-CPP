#include <iostream>
#include "trajectoire.h"
#include "segment.h"
#include "element.h"


using namespace std;

int main()
{
    Trajectoire uneTrajectoire(9);
    Segment unSegment(9,0);
    Segment unSegment2(5,0.927295);
    uneTrajectoire.Ajouter(&unSegment);
    uneTrajectoire.Ajouter(&unSegment2);
    uneTrajectoire.Afficher();
    return 0;
}
