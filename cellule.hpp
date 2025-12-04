#pragma once

class Cellule
{
protected:
    const bool estVivant;
    const bool obstacle;
public :
    Cellule(bool vivant, bool obs) : estVivant(vivant), obstacle(obs) {} 
    virtual bool getEstVivant() const = 0;
    virtual bool getObstacle() const = 0;
    virtual bool calculerEtatSuivant(int c) = 0;
    virtual ~Cellule() {}
};



