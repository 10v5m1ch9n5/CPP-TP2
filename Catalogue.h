//
// Created by lucas on 08/12/2020.
//

#ifndef C_TP2_CATALOGUE_H
#define C_TP2_CATALOGUE_H

#include "trajet.h"
#include "liste_chainee.h"

class Catalogue {
private:
    ListeChainee* liste;
public:
    Catalogue();
    ~Catalogue();
    void AjouterTrajet(Trajet* trajet);
    void AfficherTrajets();
    void RechercherTrajet(Trajet* trajet);
};


#endif //C_TP2_CATALOGUE_H
