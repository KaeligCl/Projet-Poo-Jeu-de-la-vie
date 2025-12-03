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
    grille() : tableauCellules(0) {}
    grille(int l, int L);
    shared_ptr<Cellule> getCellule(int x,int y);
    void setCellule(int x, int y, bool e);
    int compterVoisinsVivants(int x, int y);
    int getHauteur();
    int getLargeur();

};







