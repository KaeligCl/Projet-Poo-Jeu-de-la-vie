#pragma once
#include "celluleVivante.hpp"
#include <vector>
using namespace std;

class grille
{
private:
    vector<vector<shared_ptr<cellule>>> mat;;
public:
    grille(int l, int L);
    int gettableauCellules(int x,int y);
    void settableauCellules(int x, int y);
};



