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
                if (e){
                    g.setCellule(x, y, std::make_shared<celluleVivante>() );
                }
                else{
                    g.setCellule(x, y, std::make_shared<celluleMorte>() );
                }
            }
// REGLER LE PROBLEME DE CREATION DE LA GRILLE ETAT SUIVANT 
        compteurIteration++;
    }
};
