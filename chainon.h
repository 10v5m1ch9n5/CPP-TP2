#include "trajet_simple.h"
class Chainon
{
public:
    // Get Set
    void SetSuivant(Chainon* c);
    void SetTrajetSimple(TrajetSimple* ts);
    Chainon* GetSuivant();
    TrajetSimple* GetTrajetSimple();
    // Méthodes
    void ToString();
    // Constructeurs
    Chainon(TrajetSimple* ts, Chainon* suivant);
private:
    TrajetSimple* ts;
    Chainon* suivant;
};