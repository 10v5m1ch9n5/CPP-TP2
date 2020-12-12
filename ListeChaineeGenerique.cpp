//
// Created by lucas on 10/12/2020.
//

#include "ListeChaineeGenerique.h"
#include "CouleurTTY.h"
#include "Noeud.h"
#include <ostream>
using namespace std;

template<typename T>
ListeChaineeGenerique<T>::ListeChaineeGenerique()
{
#ifdef MAP
    cout << CouleurTTY(JAUNE) << "Appel au constructeur de ListeChaineeGenerique" << CouleurTTY(RESET) << endl;
#endif
    premier = nullptr;
    taille = 0;
}

template<typename T>
ListeChaineeGenerique<T>::~ListeChaineeGenerique<T>()
{
#ifdef MAP
    cout << CouleurTTY(JAUNE) << "Appel au constructeur de ListeChaineeGenerique" << CouleurTTY(RESET) << endl;
#endif
    while (premier != nullptr)
    {
        SupprimerPremier();
    }
}

template<typename T>
void ListeChaineeGenerique<T>::Ajouter(T* element)
{
    ChainonGenerique<T>* chainon = new ChainonGenerique<T>(element);
    if (taille == 0)
    {
        premier = chainon;
        taille++;
        return;
    }

    ChainonGenerique<T>* courant = premier;
    while (courant->GetSuivant() != nullptr)
    {
        courant = courant->GetSuivant();
    }
    courant->SetSuivant(chainon);
    taille++;
}

template<typename T>
T * ListeChaineeGenerique<T>::Get(int index)
{
    if (GetTaille() == 0)
        return nullptr;
    ChainonGenerique<T>* courant = premier;
    for (int i = 0; i < index && i < taille ; i++)
    {
        courant = courant->GetSuivant();
    }
    return courant->GetElement();
}

template<typename T>
void ListeChaineeGenerique<T>::Supprimer(int index)
{
    if (index == 0)
    {
        SupprimerPremier();
        return;
    }

    ChainonGenerique<T>* courant = premier;
    ChainonGenerique<T>* precedent;

    for (int i = 0; i < index; ++i)
    {
        precedent = courant;
        courant = courant->GetSuivant();
    }

    precedent->SetSuivant(courant->GetSuivant());
    delete courant;
    taille--;
}

template<typename T>
void ListeChaineeGenerique<T>::SupprimerPremier()
{
    if (taille == 0)
        return;
    ChainonGenerique<T>* suivant = premier->GetSuivant();
    delete premier;
    premier = suivant;
    taille--;
}

template<typename T>
inline int ListeChaineeGenerique<T>::GetTaille()
{
    return taille;
}

template class ListeChaineeGenerique<Noeud>;
