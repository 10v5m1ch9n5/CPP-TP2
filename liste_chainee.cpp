//
// Created by lucas on 25/11/2020.
//

#include "liste_chainee.h"
#include <iostream>
using namespace std;

ListeChainee::ListeChainee()
{
#ifdef MAP
    cout << "MAP : Appel au constructeur de ListeChainee" << endl;
#endif
    this->taille = 0;
    this->premier = nullptr;
    this->dernier = nullptr;
}

ListeChainee::~ListeChainee() {
#ifdef MAP
    cout << "MAP : Appel au destructeur de ListeChainee" << endl;
#endif
    delete premier;
    /*
    Chainon* courant = premier;
    while (courant != nullptr)
    {
        Chainon* suivant = courant->GetSuivant();
        delete courant;
        courant = suivant;
    }
     */
}

void  ListeChainee::ToString() {
    Chainon* courant = this->premier;
    int i = 1;
    while (courant != nullptr)
    {
        cout << i++ << "- ";
        courant->GetTrajet()->ToString();
        courant = courant->GetSuivant();
    }
}

void ListeChainee::Ajouter(Trajet *t) {
    Chainon* nouveau = new Chainon(t, nullptr);
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

int ListeChainee::GetTaille() const {
    return taille;
}