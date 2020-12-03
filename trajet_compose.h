#ifndef TRAJETCOMPOSE_H
#define TRAJETCOMPOSE_H

#include "trajet.h"
#include "liste_chainee.h"

class TrajetCompose : public Trajet
{
private:
    ListeChainee<Trajet>* lc;
public:
// Constructeur
    TrajetCompose(ListeChainee<Trajet>* lc);
// Destructeur
    ~TrajetCompose() {};
};

#endif
