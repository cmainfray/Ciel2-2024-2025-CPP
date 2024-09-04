#include "emballage.h"

Emballage::Emballage(const string _format, const int _resistance , const int _longueur, const int _largeur, const int _hauteur):
    format(_format),
    resistance(_resistance),
    longueur(_longueur),
    hauteur(_hauteur),
    largeur(_largeur),
    stock(0)
{
    cout <<"Constructeur: Emballage /" << format << endl;
}
Emballage::~Emballage()
{
    cout << "Destructeur: Emballage /" << format << endl;
}

void Emballage::Visualiser()
{
    if(hauteur == 0){
        cout << "|" << format << setw(4) << "|" <<resistance << "kg" << setw(4) << "|" << longueur<<"x" << largeur << setw(6) <<"|" << endl;
    }

    else {
        cout << "|" << format << setw(4) << "|" <<resistance << "kg" << setw(4) << "|" << longueur<<"x" << largeur << "x" << hauteur << setw(2) <<"|" << endl;
    }
}

bool Emballage::operator <(Emballage &autre)
{
    return CalculerVolume() < autre.CalculerVolume();
}

bool Emballage::operator ==(Emballage &autre)
{
    return (longueur == autre.longueur && largeur == autre.largeur &&
            hauteur == autre.hauteur && resistance == autre.resistance);
}

Emballage::operator float()
{
    return CalculerVolume();
}

double Emballage::CalculerVolume()
{
    int volume = longueur * largeur;
    if(hauteur != 0)
        volume *= hauteur;
    double volumeCm3 = volume / 1000.0;
    return volumeCm3;

}




