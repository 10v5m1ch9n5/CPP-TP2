//
// Created by lucas on 10/12/2020.
//

#include "Noeud.h"
#include "CouleurTTY.h"
#include <iostream>

Noeud::Noeud(Trajet *t)
{
#ifdef MAP
    cout << CouleurTTY(JAUNE) << "MAP : Appel au constructeur de Noeud" << CouleurTTY(RESET) << endl;
#endif
    trajet = t;
    t->NouvelleReference();
    enfants = new ListeChaineeGenerique<Noeud>();
    indice = -1;
    parent = nullptr;
}

Noeud::~Noeud()
{
#ifdef MAP
    cout << CouleurTTY(JAUNE) << "MAP : Appel au destructeur de Noeud { ";
    trajet->ToString();
    cout << " }" << endl;
#endif
    delete enfants;
    if (trajet->GetNbReferences() > 1)
        trajet->EnleverReference();
    else
        delete trajet;
}

void Noeud::AjouterEnfant(Noeud *noeud)
{
    noeud->SetParent(this);
    noeud->SetIndice(enfants->GetTaille());
    enfants->Ajouter(noeud);
}

void Noeud::SupprimerEnfant(int index)
{
    enfants->Supprimer(index);
    ActualiserIndicesEnfants();
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

inline int Noeud::GetIndice()
{
    return indice;
}

inline void Noeud::SetIndice(int i)
{
    this->indice = i;
}

void Noeud::DetruireCascade(int i)
{
    SupprimerEnfant(i);
    if (EstRacine())
        return;
    if (GetNbEnfants() == 0)
        parent->DetruireCascade(GetIndice());
}

Noeud * Noeud::GetEnfant(const int i)
{
    return enfants->Get(i);
}

void Noeud::ActualiserIndicesEnfants()
{
    for (int i = 0 ; i < enfants->GetTaille(); i++)
    {
        enfants->Get(i)->SetIndice(i);
    }
}

void Noeud::Debrancher()
{
    if (EstRacine())
        return;
    parent->SupprimerEnfant(GetIndice());
}
