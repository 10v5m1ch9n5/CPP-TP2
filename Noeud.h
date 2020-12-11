//
// Created by lucas on 10/12/2020.
//
// Utile uniquement pour la recherche récursive !

#ifndef C_TP2_NOEUD_H
#define C_TP2_NOEUD_H

#include "trajet.h"
#include "ListeChaineeGenerique.h"

class Noeud
{
private:
    ListeChaineeGenerique<Noeud>* enfants;
    Trajet* trajet;
    Noeud* parent;
public:
    Noeud(Trajet* t, Noeud* parent= nullptr);
    ~Noeud();
    void AjouterEnfant(Noeud* noeud);
    int GetNbEnfants();
    Trajet* GetTrajet();
    bool EstRacine();
    void SetParent(Noeud* p);
};


#endif //C_TP2_NOEUD_H
