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
    int indice;
    void ActualiserIndicesEnfants();
public:
    explicit Noeud(Trajet* t);
    ~Noeud();
    void AjouterEnfant(Noeud* noeud);
    void SupprimerEnfant(int index);
    int GetNbEnfants();
    Trajet* GetTrajet();
    bool EstRacine();
    void SetParent(Noeud* p);
    void SetIndice(int i);
    int GetIndice();
    void DetruireCascade(int i = 0);
    Noeud* GetEnfant(int i);
};


#endif //C_TP2_NOEUD_H
