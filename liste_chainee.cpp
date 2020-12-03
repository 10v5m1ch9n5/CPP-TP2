//
// Created by lucas on 25/11/2020.
//
#include "liste_chainee.h"

template<class T>
ListeChainee<T>::ListeChainee()
{
    this->taille = 0;
    this->premier = nullptr;
    this->dernier = nullptr;
}

template<class T>
void ListeChainee<T>::Ajouter(T* element) {
    Chainon<T>* nouveau = new Chainon<T>(element, nullptr);
    if (taille == 0) {
        this->premier = this->dernier = nouveau;
        taille++;
        return;
    }
    this->dernier->SetSuivant(nouveau);
    this->dernier = this->dernier->GetSuivant();
    taille++;
}

template<class T>
void ListeChainee<T>::Supprimer(int index) {
    Chainon<T>* courant = this->premier;
    if (index == 0)
    {
        this->premier = courant->GetSuivant();
        taille--;
        delete courant;
        return;
    }
    Chainon<T>* precedent;
    for (int i = 0; i < index; i++) {
        precedent = courant;
        courant = courant->GetSuivant();
    }
    precedent->SetSuivant(courant->GetSuivant());
    taille--;
    delete courant;
}

template<class T>
Chainon<T>* ListeChainee<T>::Get(int index) {
    Chainon<T>* courant = this->premier;
    for (int i = 0; i < index; i++)
    {
        courant = courant->GetSuivant();
    }
    return courant;
}

template class ListeChainee<Trajet>;
template class ListeChainee<TrajetSimple>;
// template class ListeChainee<TrajetCompose>;