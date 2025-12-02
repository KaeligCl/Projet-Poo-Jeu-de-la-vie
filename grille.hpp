#pragma once
#include "celluleVivante.hpp"
#include <vector>
using namespace std;

class grille
{
private:
    celluleVivante tableauCelllules[[]];
public:
    grille(int l, int L);
    int gettableauCellules(int x,int y);
    void settableauCellules(int x, int y);
};


