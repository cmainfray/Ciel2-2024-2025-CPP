#ifndef ELEMENT_H
#define ELEMENT_H
#include <iostream>
#include <iomanip>
#include <istream>
using namespace std;

class Element
{
public:
    Element();
    virtual ~Element();
    virtual void  Afficher() = 0;
};

#endif // ELEMENT_H
