// Cette classe représente un chainon d'une liste chainée de trajets.
// Chaque chainon contient un trajet et un pointeur vers le chainon suivant.

#ifndef CHAINON_H
#define CHAINON_H

#include "trajet.h"
class Chainon
{
public:
// Get Set
    void SetSuivant(Chainon* c);
    void SetTrajet(Trajet* t); // Méthode inutilisée
    Chainon* GetSuivant();
    Trajet* GetTrajet();
// Méthodes
    void ToString(); // Sert uniquement pour déboguer
// Constructeurs
    Chainon(Trajet* t, Chainon* suivant);
    ~Chainon();
private:
    Trajet* trajet;
    Chainon* suivant;
};

#endif