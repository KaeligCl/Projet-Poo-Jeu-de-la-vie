#pragma once
#include "celluleVivante.hpp"
#include "celluleMorte.hpp"
#include <memory>
#include <vector>
using namespace std;

class grille
{
private:
    vector<vector<shared_ptr<Cellule>>> tableauCellules;
public:
    grille() {}
    grille(int l, int L);
    shared_ptr<Cellule> getCellule(int x,int y) const ;
    void setCellule(int x, int y, shared_ptr<Cellule> c);
    int compterVoisinsVivants(int x, int y);
    int getHauteur() const ;
    int getLargeur()const ;

};







