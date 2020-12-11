#ifndef CHAINON_H
#define CHAINON_H

#include "trajet.h"
class Chainon
{
public:
    // Get Set
    void SetSuivant(Chainon* c);
    void SetTrajet(Trajet* t);
    Chainon* GetSuivant();
    Trajet* GetTrajet();
    // Méthodes
    void ToString();
// Constructeurs
    Chainon(Trajet* t, Chainon* suivant);
    ~Chainon();
private:
    Trajet* trajet;
    Chainon* suivant;
};

#endif