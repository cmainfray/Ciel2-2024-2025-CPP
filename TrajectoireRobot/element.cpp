#include "element.h"

Element::Element():
    numero(0),
    vitesse(1)
{}

Element::~Element()
{

}

int Element::getNumero() const
{
    return numero;
}

void Element::setNumero(int newNumero)
{
    numero = newNumero;
}


