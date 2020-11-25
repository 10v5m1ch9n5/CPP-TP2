#include "trajet_simple.h"
class Chainon
{
public:
    void SetSuivant(Chainon* c);
    void SetTrajetSimple(TrajetSimple* ts);
    Chainon(TrajetSimple* ts, Chainon* suivant);
    Chainon();
private:
    TrajetSimple* ts;
    Chainon* suivant;
};