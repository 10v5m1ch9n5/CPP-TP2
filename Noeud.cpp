//
// Created by lucas on 10/12/2020.
//

#include "Noeud.h"
#include "CouleurTTY.h"
#include <iostream>

Noeud::Noeud(Trajet *t, Noeud* parent)
{
#ifdef MAP
    cout << CouleurTTY(JAUNE) << "Appel au constructeur de Noeud" << CouleurTTY(RESET) << endl;
#endif
    trajet = t;
    enfants = new ListeChaineeGenerique<Noeud>();
    this->parent = parent;
}

Noeud::~Noeud()
{
#ifdef MAP
    cout << CouleurTTY(JAUNE) << "Appel au destructeur de Noeud" << CouleurTTY(RESET) << endl;
#endif
    delete enfants;
}

void Noeud::AjouterEnfant(Noeud *noeud)
{
    noeud->SetParent(this);
    enfants->Ajouter(noeud);
}

inline int Noeud::GetNbEnfants()
{
    return enfants->GetTaille();
}

Trajet * Noeud::GetTrajet()
{
    return trajet;
}

bool Noeud::EstRacine()
{
    return parent == nullptr;
}

void Noeud::SetParent(Noeud *p)
{
    parent = p;
}
