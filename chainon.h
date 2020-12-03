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
private:
    Trajet* trajet;
    Chainon* suivant;
};