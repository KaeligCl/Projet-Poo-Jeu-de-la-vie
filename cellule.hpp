#pragma once

class cellule
{
protected:
    bool estVivant;
    bool next; //état suivant
public :
    cellule(bool estVivant, bool next) : estVivant(estVivant), next(next) {}
    bool getEstVivant() const { return estVivant; }
    bool getNext() const {  return next; }
    void setEstVivant(bool estVivant) { this -> estVivant = estVivant; }
    void setNext(bool next) { this -> next = next; }
    virtual bool update() = 0;
};
