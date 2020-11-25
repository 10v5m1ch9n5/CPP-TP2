//
// Created by lucas on 25/11/2020.
//
#define DEBUG

#include "liste_chainee.h"

ListeChainee::ListeChainee()
{
    this->taille = 0;
    this->premier = nullptr;
    this->dernier = nullptr;
}

void  ListeChainee::ToString() {
    Chainon* courant = this->premier;

    while (courant->GetSuivant() != nullptr)
    {
       courant->GetTrajetSimple()->ToString();
       courant = courant->GetSuivant();
    }
    courant->GetTrajetSimple()->ToString();
    delete courant;
}

void ListeChainee::Ajouter(TrajetSimple *ts) {
    Chainon* nouveau = new Chainon(ts, nullptr);
    if (taille == 0) {
        this->premier = this->dernier = nouveau;
        taille++;
        return;
    }
    this->dernier->SetSuivant(nouveau);
    this->dernier = this->dernier->GetSuivant();
    taille++;
}

void ListeChainee::Supprimer(int index) {
    Chainon* courant = this->premier;
    if (index == 0)
    {
        this->premier = courant->GetSuivant();
        taille--;
        delete courant;
        return;
    }
    Chainon* precedent;
    for (int i = 0; i < index; i++) {
        precedent = courant;
        courant = courant->GetSuivant();
    }
    precedent->SetSuivant(courant->GetSuivant());
    taille--;
    delete courant;
}

Chainon* ListeChainee::Get(int index) {
    Chainon* courant = this->premier;
    for (int i = 0; i < index; i++)
    {
        courant = courant->GetSuivant();
    }
    return courant;
}
