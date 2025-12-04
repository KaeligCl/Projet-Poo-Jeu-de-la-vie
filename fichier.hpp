#pragma once
#include "grille.hpp"
#include <string>
#include "celluleVivante.hpp"
#include "celluleMorte.hpp"
#include "obstacleMort.hpp"
#include "obstacleVivant.hpp"


class Fichier{
private :
    grille data;

public :
    Fichier(){}
    grille lireFichier(const std::string& chemin);
    void creerFichier(const grille& g, const std::string& chemin);
};
