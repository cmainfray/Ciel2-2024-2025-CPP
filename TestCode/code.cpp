#include "code.h"
#include <iostream>

Code::Code(const int _tailleCode):
    tailleCode(_tailleCode)
{
    codeUsine = new quint8[tailleCode];
    codeUtilisateur = new quint8[tailleCode];
    for(int indice = 0 ; indice < tailleCode ; indice++){
        codeUsine[indice] = indice + 1;
        codeUtilisateur[indice] = 0;
    }
}

Code::~Code()
{
    delete codeUsine;
    delete codeUtilisateur;
}


// bool Code::VerifierCode(const quint8 _unCode[])
// {
//     bool verifUsine;
//     bool  verifUtilisateur;
//     verifUtilisateur = true;
//     verifUsine = true;
//     for(int indice = 0; indice < tailleCode; indice++){
//         if(_unCode != codeUsine[indice])
//             verifUsine = false;

//         else if (_unCode != codeUtilisateur[indice])
//             verifUtilisateur = false;

//     }
//     return verifUsine || verifUtilisateur;
// }

void Code::Memoriser(const quint8 _unCode[])
{
    for(int indice = 0; indice < tailleCode; indice++){
        codeUtilisateur[indice] = _unCode[indice];
    }
    for(int indice = 0; indice < tailleCode; indice++){
        qDebug() << codeUtilisateur[indice];
    }
}
