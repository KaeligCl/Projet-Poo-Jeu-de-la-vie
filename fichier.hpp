#pragma once
#include <utility>
#include <vector>
#include "grille.hpp"
#include "celluleVivante.hpp"
#include "celluleMorte.hpp"


class Fichier{
    private :
        grille data;

    public :
        Fichier(){}
        grille lireFichier(const std::string& chemin);

        void creerFichier();
};
