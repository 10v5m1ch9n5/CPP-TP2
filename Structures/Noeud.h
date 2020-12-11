//
// Created by lucas on 10/12/2020.
//
// Utile uniquement pour la recherche récursive !

#ifndef C_TP2_NOEUD_H
#define C_TP2_NOEUD_H

#include "structures_header.h"

class Noeud
{
private:
    int nbEnfants;
    Noeud** enfants;
    Trajet* trajet;
public:
    Noeud(Trajet* t);
    AjouterEnfant(Noeud* );
};


#endif //C_TP2_NOEUD_H
