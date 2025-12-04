#pragma once
#include "cellule.hpp"

class obstacleVivant : public Cellule
{
public:
    obstacleVivant() : Cellule(true, true) {}
    bool getEstVivant() const override
    {
        return this->estVivant;
    }

    bool getObstacle() const override {
        return this->obstacle;
    }
};