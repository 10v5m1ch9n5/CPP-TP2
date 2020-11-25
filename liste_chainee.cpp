//
// Created by lucas on 25/11/2020.
//

#include "liste_chainee.h"

ListeChainee::ListeChainee(int taille)
{
    this->taille = taille;
    this->premier = new Chainon;
    Chainon* courant = premier;
    for(int i = 0; i < taille; i++)
    {
        courant->SetSuivant(new Chainon());
    }
}