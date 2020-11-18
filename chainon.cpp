#include "chainon.h"
#include "trajet_simple.h"

// Constructeur
Chainon:Chainon(TrajetSimple* ts, Chainon* suivant)
{
    this->suivant = suivant;
    this->ts = ts;
}