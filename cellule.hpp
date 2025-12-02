#pragma once

class cellule
{
protected:
    bool estVivant;
    bool next; //état suivant stocké temporaire
public :
    Cellule(bool estVivant, bool next) : estVivant(estVivant), next(next) {}
    bool getEstVivant() const { return estVivant; }
    bool getNext() const {  return next; }
    void setestVivant(bool estVivant) { this -> estVivant = estVivant; }
    void setNext(bool next) { this -> next = next; }
};
