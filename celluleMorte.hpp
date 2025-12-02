#pragma once
#include "cellule.hpp"

class celluleMorte : public cellule
{
private:
    const bool estVivant = false;
public:
    celluleMorte();
};
