#pragma once
#include "cellule.hpp"
#include <vector>
using namespace std;

class grille
{
private:
    celluleVivante tableauCelllules[[]];
public:
    grille(int l, int L);
    int getCellule(int x,int y);
    void setCellule(int x, int y);
};

