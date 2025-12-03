#include "grille.hpp"

grille::grille(int l, int L)
{
    // Crée un vecteur de l lignes
    tableauCellules.resize(l);
    for (int i = 0; i < l; ++i)
    {
        // Chaque ligne a L colonnes initialisées à nullptr
        tableauCellules[i].resize(L, nullptr);
    }
}

shared_ptr<Cellule> grille::getCellule(int x, int y){
    return this->tableauCellules[x][y];
}

void grille::setCellule(int x, int y, shared_ptr<Cellule> c){
    this->tableauCellules[x][y] = c;
}

int grille::getHauteur() {
    return tableauCellules.size();
}

int grille::getLargeur() {
    return tableauCellules[0].size();
}
