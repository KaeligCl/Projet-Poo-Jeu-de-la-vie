#include "cellule.hpp"

class obstacleMort : public Cellule
{
public:
    obstacleMort() : Cellule(true, true) {}
    
    bool getEstVivant() const override
    {
        return this->estVivant;
    }

    bool getObstacle() const override {
        return this->obstacle;
    }
};