// Une liste chainée de trajets utilisée par le catalogue et les trajets composés.

#ifndef LISTECHAINEE_H
#define LISTECHAINEE_H

#include "chainon.h"
class ListeChainee
{
public:
// Méthodes
    void ToString();
    void Ajouter(Trajet* t);
    void Supprimer(int index);
    Chainon* Get(int index);
    int GetTaille() const;
// Constructeurs
    ListeChainee();
    ~ListeChainee();
protected:
    Chainon* premier;
    Chainon* dernier;
    int taille;
};

#endif