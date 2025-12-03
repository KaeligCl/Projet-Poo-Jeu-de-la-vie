#pragma once
#include "cellule.hpp"

class celluleVivante : public Cellule
{
public:
    celluleVivante() : Cellule(true) {}

    bool getEstVivant() const override {
        return this->estVivant;
    }
};

