#pragma once

class cellule
{
protected:
    bool next; //état suivant stocké temporaire
public :
    Cellule(bool next) : next(next) {}
    bool getNext() const {  return next; }
    void setNext(bool next) { this -> next = next; }
};
