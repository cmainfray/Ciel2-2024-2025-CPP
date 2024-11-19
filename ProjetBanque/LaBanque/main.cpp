/**
    @file main.cpp
    @version 1.0
    @author Camille Mainfray
    @date 5/09/2024
    */

#include <iostream>
#include "menu.h"
#include "comptebancaire.h"
#include "compteepargne.h"


using namespace std;

enum CHOIX_MENU
{
    OPTION_1 = 1,
    OPTION_2,
    OPTION_3,
    OPTION_4,
    OPTION_5,
    QUITTER
};


// int main()
// {

//     int choix;
//     Menu menuCB("../LaBanque/CompteBancaire.txt");
//     CompteBancaire compte(100.0);
//     do{
//         choix = menuCB.Afficher();
//         switch(choix){
//             case OPTION_1:
//                 cout << "Votre solde est de :" << endl;
//                 cout << compte.ConsulterSolde()<< endl;
//                 break;
//             case OPTION_2:
//                 float depot;
//                 cout << "Entrer le montant" << endl;
//                 cin >> depot;
//                 compte.Deposer(depot);
//                 cout << endl << "Depot reussi" << endl;
//                 break;
//             case OPTION_3:
//                 float retirer;
//                 cout << "Entrer le montant" << endl;
//                 cin >> retirer;
//                  compte.Retirer(retirer);
//                  cout << endl << "Retrait reussi" << endl;
//                  break;
//             case OPTION_4:
//                 cout << "Vous avez quitter" << endl;
//                 break;
//         }

//     }
//     while(choix != OPTION_4);

//     return 0;
// }
int main(){
    int choix;
    Menu menuCB("../LaBanque/compteEpargne.txt");
    CompteEpargne compte(0.03, 100);
    do{choix = menuCB.Afficher();
        switch(choix){
        case OPTION_1:
            cout << "Votre solde est de :" << endl;
            cout << compte.ConsulterSolde()<< endl;
            break;
        case OPTION_2:
            float depot;
            cout << "Entrer le montant" << endl;
            cin >> depot;
            compte.Deposer(depot);
            cout << endl << "Depot reussi" << endl;
            break;
        case OPTION_3:
            float retirer;
            cout << "Entrer le montant" << endl;
            cin >> retirer;
            compte.Retirer(retirer);
            cout << endl << "Retrait reussi" << endl;
            break;
        case OPTION_4:
            compte.CalculerInterets();
            cout << "Vos interets : " << compte.ConsulterSolde() << endl;
            break;
        case OPTION_5:
            cout << "Vous avez quitter" << endl;
        }

    }while(choix != OPTION_5);

    return 0;
}
