#pragma once

class Cellule
{
protected:
    const bool estVivant;
public :
    Cellule(const bool estVivant) : estVivant(estVivant) {}
    bool getEstVivant() const { return estVivant; }
};

