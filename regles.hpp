#pragma once
#include "grille.hpp"

class Regle
{
private:
    long compteurIteration = 0;

public:
    void etatSuivant(grille &g)
    {
        int lMax = g.getHauteur();
        int LMax = g.getLargeur();

        // Calcul et création nouvelle cellule dans la grille suivante
        for (int x = 0; x < lMax; ++x)
            for (int y = 0; y < LMax; ++y)
            {
                int voisins = g.compterVoisinsVivants(x, y);
                bool e = g.getCellule(x, y)->calculerEtatSuivant(voisins);
                g.setCellule(x, y);

            }

        // Phase d’application
        for (int x = 0; x < lMax; ++x)
            for (int y = 0; y < LMax; ++y)
                g.getCellule(x, y)->appliquerNouvelEtat();

        compteurIteration++;
    }
};
