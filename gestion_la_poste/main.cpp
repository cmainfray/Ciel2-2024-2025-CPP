#include <iostream>
#include "emballage.h"
#include <limits>

using namespace std;
#define NB_Colis 2

int main()
{
    // Emballage colis1("XS",1,270,190);
    // Emballage *pColis;
    // pColis = new Emballage("XL",7,383,250,195);
    // colis1.Visualiser();
    // pColis->Visualiser();
    // delete pColis;
    string format;
    int resistance;
    int longueur;
    int largeur;
    int hauteur;

    Emballage *tab_colis[NB_Colis];
    for(int i = 0 ; i < NB_Colis; i++){
        cout << "Entrer le format" << endl;
        cin >> format ;
        cout << "Entrer la resistance" << endl;
        cin >> resistance ;
        cout << "Entrer la longueur" << endl;
        cin >> longueur ;
        cout << "Entrer la largeur" << endl;
        cin >> largeur;
        cout << "Entrer le hauteur" << endl;
        cin >> hauteur ;

        tab_colis[i] = new Emballage(format,resistance,longueur,largeur,hauteur);
    }
    cout << endl;
    cout << setfill('-');
    cout << "+" << setw(18) << "+";
    cout << setw(13) << "+";
    cout << setw(18) << "+";

    cout << endl;
    cout << setfill(' ');
    cout << "|" << setw(17) << left << "Format" ;
    cout << "|" << setw(11) << left << "Resistance";
    cout << "|" << setw(17) << left << "Dimensions" ;
    cout << "|";

    cout << endl;

    cout << setfill(' ');

    cout << endl;
    cout << setfill('-');
    cout << "+" << setw(18) << "+";
    cout << setw(13) << "+";
    cout << setw(18) << "+";

    cout << endl;
    cout << setfill(' ');

    for(int i = 0 ; i < NB_Colis; i++){
        tab_colis[i]->Visualiser();
    }
    cout << setfill('-');
    cout << "+" << setw(18) << "+";
    cout << setw(13) << "+";
    cout << setw(18) << "+";
    cout << setfill(' ');
    cout << endl;

     if(*tab_colis[0] < *tab_colis[1])
        cout << "tab_colis[0] est plus petit que tab_colis[1]" << endl;


    if(*tab_colis[0] == *tab_colis[1])
        cout << "tab_colis[0] et tab_colis[1] sont identique" << endl;
    else
        cout<< "tab_colis[0] et tab_colis[1] sont différent" << endl;
    float volume = *tab_colis[0];
    cout << "Le volume de tab_colis[0] est de " << volume << "cm3" << endl;

    return 0;
}

