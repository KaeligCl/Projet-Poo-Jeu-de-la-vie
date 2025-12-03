#include "fichier.hpp"
#include <sstream>
#include<string>
#include <fstream>
#include <iostream>

grille Fichier::lireFichier(const std::string& chemin){
    std::ifstream fichier(chemin);
    if (!fichier)
        throw std::runtime_error("Impossible d'ouvrir le fichier");

    int hauteur, largeur;
    fichier >> hauteur >> largeur;

    grille g(hauteur, largeur);

    for (int i = 0; i < hauteur; i++) {
        for (int j = 0; j < largeur; j++) {
            int valeur;
            fichier >> valeur;
            if (valeur == 1)
                g.setCellule(i, j, std::make_shared<celluleVivante>());
            else
                g.setCellule(i, j, std::make_shared<celluleMorte>());
        }
    }
    return g;
}

void Fichier::creerFichier(const grille& g, const std::string& chemin)
{
    std::ofstream f(chemin);
    int h = g.getHauteur();
    int L = g.getLargeur();

    f << h << " " << L << "\n";

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < L; j++)
        {
            f << (g.getCellule(i, j)->getEstVivant()? 1 : 0) << " ";
        }
        f << "\n";
    }
}
