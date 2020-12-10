//
// Created by lucas on 25/11/2020.
//

#include "liste_chainee.h"
#include <iostream>
#include "CouleurTTY.h"
using namespace std;

ListeChainee::ListeChainee()
{
#ifdef MAP
    cout << CouleurTTY(JAUNE) << "MAP : Appel au constructeur de ListeChainee" << CouleurTTY(RESET) << endl;
#endif
    this->taille = 0;
    this->premier = nullptr;
    this->dernier = nullptr;
}

ListeChainee::~ListeChainee() {
#ifdef MAP
    cout << CouleurTTY(JAUNE) << "MAP : Appel au destructeur de ListeChainee" << CouleurTTY(RESET) << endl;
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
    cout << CouleurTTY(BLEU);
    while (courant != nullptr)
    {
        cout << i++ << "- ";
        courant->GetTrajet()->ToString();
        cout << endl;
        courant = courant->GetSuivant();
    }
    cout << CouleurTTY(RESET);
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