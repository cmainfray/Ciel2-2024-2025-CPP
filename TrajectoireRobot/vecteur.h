#ifndef VECTEUR_H
#define VECTEUR_H
#include <iostream>
#include <iomanip>
#include <istream>
using namespace std;

class Vecteur
{
public:
    Vecteur(double _x, double _y);
    Vecteur operator +(Vecteur _autre);
    Vecteur operator -(Vecteur _autre);
    void Afficher();


    double getX() const;
    void setX(double newX);

    double getY() const;
    void setY(double newY);

private:
    double x;
    double y;
};

#endif // VECTEUR_H
