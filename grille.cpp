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

std::shared_ptr<Cellule> grille::getCellule(int x, int y) const { 
    return tableauCellules[x][y]; 
}

void grille::setCellule(int x, int y, shared_ptr<Cellule> c) {
    this->tableauCellules[x][y] = c;
}

int grille::getHauteur() const { 
    return tableauCellules.size(); 
}

int grille::getLargeur() const { 
    return tableauCellules[0].size(); 
}

int grille::compterVoisinsVivants(int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue;
            int newX = x + i;
            int newY = y + j;
            if (newX >= 0 && newX < getHauteur() && newY >= 0 && newY < getLargeur()) {
                if (getCellule(newX, newY)->getEstVivant()) {
                    count++;
                }
            }
        }
    }
    return count;
}
