#pragma once
#include "cellule.hpp"
#include <memory>
#include <vector>
using namespace std;

class grille
{
private:
    vector<vector<shared_ptr<Cellule>>> tableauCellules;
public:
    grille(int l, int L);
    int getCellule(int x,int y);
    void setCellule(int x, int y);
};







