#ifndef ALVEOLESLIBRES_H
#define ALVEOLESLIBRES_H
#include <QStack>

class AlveolesLibres : public QStack<int>
{
public:
    AlveolesLibres(const int _nbRangees=10, const int _nbColonnes=20);
    bool Reserver(int &_rangee,int &_colonne);
    void Liberer(int const _rangee,int const _colonne);
private:
    int nbRangees;
    int nbColonnes;
};

#endif // ALVEOLESLIBRES_H
