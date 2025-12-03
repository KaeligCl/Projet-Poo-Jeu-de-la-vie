#pragma once
#include "grille.h"
#include <string>
#include "celluleVivante.h"
#include "celluleMorte.h"


class Fichier{
private :
    grille data;

public :
    Fichier(){}
    grille lireFichier(const std::string& chemin);
    void creerFichier(const grille& g, const std::string& chemin);
};
