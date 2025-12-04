#pragma once
#include "grille.h"
#include <memory>
#include "celluleVivante.h"
#include "celluleMorte.h"

class Regle
{
private:
    long compteurIteration = 0;

public:
    void etatSuivant(grille &g)
    {

        int lMax = g.getHauteur();
        int LMax = g.getLargeur();

        grille g2(lMax, LMax);

        // Calcul et création nouvelle cellule dans la grille suivante
        for (int x = 0; x < lMax; ++x)
            for (int y = 0; y < LMax; ++y)
            {
                int voisins = g.compterVoisinsVivants(x, y);
                bool e = g.getCellule(x, y)->calculerEtatSuivant(voisins); //etat suivant
                if (e){
                    g2.setCellule(x, y, std::make_shared<celluleVivante>() );
                }
                else{
                    g2.setCellule(x, y, std::make_shared<celluleMorte>() );
                }
            }
        g = g2;
        compteurIteration++;
    }
};
