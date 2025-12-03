#pragma once
#include "cellule.hpp"

class celluleMorte : public Cellule
{
public:
    celluleMorte() : Cellule(false, false) {}
    
    bool getEstVivant() const override {
        return this->estVivant;
    }

    bool calculerEtatSuivant(int c) override;
};
