#pragma once
#include "cellule.hpp"

class celluleVivante : public cellule
{
private:
    const bool estVivant = true;

public:
    celluleVivante();
};

