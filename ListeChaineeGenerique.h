//
// Created by lucas on 10/12/2020.
//
// Une liste chainée générique utilisée uniquement dans l'implémentation de la recherche avancée.
// Chaque noeud possède une liste chainée de noeuds enfants représentant les trajets pouvant être effectués depuis l'arrivée du trajet du noeud parent.


#ifndef C_TP2_LISTECHAINEEGENERIQUE_H
#define C_TP2_LISTECHAINEEGENERIQUE_H

#include "ChainonGenerique.h"

template<typename T>
class ListeChaineeGenerique
{
private:
    ChainonGenerique<T>* premier;
    int taille;
    void SupprimerPremier();
public:
    ListeChaineeGenerique();
    ~ListeChaineeGenerique();
    void Ajouter(T* element);
    T* Get(const int index);
    void Supprimer(int index);
    int GetTaille();
};


#endif //C_TP2_LISTECHAINEEGENERIQUE_H
