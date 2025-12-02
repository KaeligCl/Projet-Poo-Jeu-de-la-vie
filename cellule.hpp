#pragma once

class Cellule
{
protected:
    const bool estVivant;
public :
    Cellule(bool vivant) : estVivant(vivant) {} 
    virtual bool getEstVivant() const = 0;
    virtual ~Cellule() {}
};


