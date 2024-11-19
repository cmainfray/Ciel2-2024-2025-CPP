#include "vecteur.h"

Vecteur::Vecteur(double _x, double _y):
    x(_x),
    y(_y)
{}

Vecteur Vecteur::operator +(Vecteur _autre)
{
    x += _autre.getX();
    y += _autre.getY();
        return *this;
}

Vecteur Vecteur::operator -(Vecteur _autre)
{
    x -= _autre.getX();
    y -= _autre.getY();
    return *this;
}

void Vecteur::Afficher()
{
    cout << x << endl;
    cout << y << endl;
}

double Vecteur::getX() const
{
    return x;
}

void Vecteur::setX(double newX)
{
    x = newX;
}

double Vecteur::getY() const
{
    return y;
}

void Vecteur::setY(double newY)
{
    y = newY;
}
