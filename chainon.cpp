#include "chainon.h"
#include <iostream>

// Constructeurs
Chainon::Chainon(TrajetSimple* ts, Chainon* suivant)
{
#ifdef MAP
    cout << "Contructeur de Chainon appelé" << endl;
#endif
    this->suivant = suivant;
    this->ts = ts;
}

Chainon::Chainon()
{
#ifdef MAP
    cout << "Contructeur de Chainon appelé" << endl;
#endif
    this->suivant = nullptr;
    this->ts = nullptr;
}
// Méthodes
void Chainon::SetSuivant(Chainon *c) {
    this->suivant = c;
}

void Chainon::SetTrajetSimple(TrajetSimple *ts) {
    this->ts = ts;
}