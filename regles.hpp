#pragma once
#include "grille.hpp"
#include <memory>
#include "celluleVivante.hpp"
#include "celluleMorte.hpp"

class Regle
{
private:
    long compteurIteration = 0;

public:
    void etatSuivant(grille &g);
};
