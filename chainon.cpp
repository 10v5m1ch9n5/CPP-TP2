#include "chainon.h"
#include <iostream>
using namespace std;

// Constructeurs
Chainon::Chainon(Trajet* t, Chainon* suivant = nullptr)
{
    this->suivant = suivant;
    this->trajet = t;
}

// Get Set
void Chainon::SetSuivant(Chainon *c) {
    this->suivant = c;
}

void Chainon::SetTrajet(Trajet *t) {
    this->trajet = t;
}

Chainon* Chainon::GetSuivant() {
    return this->suivant;
}

Trajet* Chainon::GetTrajet() {
    return this->trajet;
}

// Méthodes
void Chainon::ToString() {
    cout << "Chainon : ";
    if(this->trajet == nullptr)
    {
        cout << "vide" << endl;
        return;
    }
    cout << endl;
    this->trajet->ToString();
    if(this->suivant == nullptr)
    {
        cout << "chainon suivant inexistant" << endl;
        return;
    }
    cout << "chainon suivant défini" << endl;
}