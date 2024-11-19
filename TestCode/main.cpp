#include <iostream>
#include <QtGlobal>
#include "code.h"

using namespace std;

#define TAILLE_CODE 4

int main(int argc, char *argv[])
{
    char choix;
    quint8 combinaison[TAILLE_CODE];
    Code leCode;

    cout << "Voulez-vous modifier le code O/N : ";
    cin >> choix;
    if(choix == 'O' || choix == 'o')
    {
        cout << "Entrez le nouveau code à 4 chiffres" << endl;
        for(int i = 0 ; i < TAILLE_CODE ; i++){
            cin >> combinaison[i];

        }

        leCode.Memoriser(combinaison);

        cout << "Le code Utilisateur est : " << combinaison << endl;

    //     for(int i = 0 ; i < 1 ; i++){
    //           cout << leCode.VerifierCode(combinaison[i]) << endl;
    //      }
    // }

    // else if(choix == 'N' || choix == 'n') {
    //     for(int i = 0 ; i < 1 ; i++){
    //          cout << leCode.VerifierCode(combinaison[i]) << endl;
    //     }
    }
    return 0;
}
