#pragma once

class cellule
{
private:
    bool estVivant;
    bool next;
public :
    Cellule(bool estVivant, bool next) : estVivant(estVivant), next(next) {}
    bool getEstVivant() { return estVivant; }
    bool getNext() {  return next; }
    void setEstVivant(bool estVivant) { estVivant = estVivant; }
    void setNext(bool next) { next = next; }
    bool update();
};
