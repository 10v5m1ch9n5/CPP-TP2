#include "chainon.h"
#include <iostream>
using namespace std;

// Constructeurs
Chainon::Chainon(TrajetSimple* ts = nullptr, Chainon* suivant = nullptr)
{
#ifdef MAP
    cout << "Contructeur de Chainon appelé" << endl;
#endif
    this->suivant = suivant;
    this->ts = ts;
}

// Get Set
void Chainon::SetSuivant(Chainon *c) {
    this->suivant = c;
}

void Chainon::SetTrajetSimple(TrajetSimple *ts) {
    this->ts = ts;
}

Chainon* Chainon::GetSuivant() {
    return this->suivant;
}

TrajetSimple* Chainon::GetTrajetSimple() {
    return this->ts;
}

// Méthodes
void Chainon::ToString() {
    cout << "Chainon : ";
    if(this->ts == nullptr)
    {
        cout << "vide" << endl;
        return;
    }
    cout << endl;
    this->ts->ToString();
    if(this->suivant == nullptr)
    {
        cout << "chainon suivant inexistant" << endl;
        return;
    }
    cout << "chainon suivant défini" << endl;
}