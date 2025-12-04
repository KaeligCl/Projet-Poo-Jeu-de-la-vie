#pragma once
#include "cellule.hpp"

class celluleVivante : public Cellule
{
public:
    celluleVivante() : Cellule(true, false) {}

    bool getEstVivant() const override {
        return this->estVivant;
    }

    bool getObstacle() const override {
        return this->obstacle;
    }

    bool calculerEtatSuivant(int c) override;
};
