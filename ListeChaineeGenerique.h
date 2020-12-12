//
// Created by lucas on 10/12/2020.
//

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
    T* Get(int index);
    void Supprimer(int index);
    int GetTaille();
};


#endif //C_TP2_LISTECHAINEEGENERIQUE_H
