#include <iostream>
#include "barrecarre.h"
#include "barreronde.h"
#include "menu.h"
#include "catalogue.h"

using namespace std;

enum CHOIX_MENU
{
    OPTION_1 = 1,
    OPTION_2,
    OPTION_3,
    OPTION_4,
    QUITTER
};

int main()
{
    string reference;
    string alliage;
    float longueur;
    float densite;
    int choix;
    Menu menuCB("../lesBarres/barre.txt");
    Catalogue unCatalogue(10);
    BarreCarre *uneBarreCarre;
    BarreRonde *uneBarreRonde;
    do{choix = menuCB.Afficher();
        switch(choix){
        case OPTION_1:
            float cote;
            cout << "Entrer le type de la barre : " << endl;
            cin >> reference;
            cout << "Entrer le type d'alliage" << endl;
            cin >> alliage;
            cout << "Entrer la longueur de la barre : " << endl;
            cin >> longueur;
            cout << "Entrer la densité de la barre : " << endl;
            cin >> densite;
            cout << "Entrer un coté de la barre : " << endl;
            cin >> cote;
            uneBarreCarre = new BarreCarre(reference,alliage,longueur,densite,cote);
            unCatalogue.AjouterBarre(uneBarreCarre);
            break;
        case OPTION_2:
            float diametre;
            cout << "Entrer le type de la barre : " << endl;
            cin >> reference;
            cout << "Entrer le type d'alliage" << endl;
            cin >> alliage;
            cout << "Entrer la longueur de la barre : " << endl;
            cin >> longueur;
            cout << "Entrer la densité de la barre : " << endl;
            cin >> densite;
            cout << "Entrer le diametre de la barre : " << endl;
            cin >> diametre;
            uneBarreRonde = new BarreRonde(reference,alliage,longueur,densite,diametre);
            unCatalogue.AjouterBarre(uneBarreRonde);
            break;
        case OPTION_3:
            cout << endl;
               unCatalogue.AfficherCatalogue();
            cout << endl;
            break;
        case OPTION_4:
            cout << "Vous avez quitter" << endl;
            break;
        }

    }while(choix != OPTION_4);

    return 0;
}
