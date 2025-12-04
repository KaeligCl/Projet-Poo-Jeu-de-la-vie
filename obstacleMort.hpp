#pragma once
#include "cellule.hpp"

class obstacleMort : public Cellule
{
public:
    obstacleMort() : Cellule(false, true) {}
    
    bool getEstVivant() const override
    {
        return this->estVivant;
    }

    bool getObstacle() const override {
        return this->obstacle;
    }

    bool calculerEtatSuivant(int c) override {
        return false;
    }
};
