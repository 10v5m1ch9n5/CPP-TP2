//
// Created by lucas on 08/12/2020.
//

#ifndef C_TP2_CATALOGUE_H
#define C_TP2_CATALOGUE_H

#include "trajet.h"
#include "liste_chainee.h"
#include "Noeud.h"

class Catalogue {
private:
    ListeChainee* liste;
    void RechercheRecursive(const char * villeDepart, const char * villeArrivee, Noeud* noeud);
public:
    Catalogue();
    ~Catalogue();
    void AjouterTrajet(Trajet* trajet);
    void AfficherTrajets();
    void RechercherTrajet(char* villeDepart, char* villeArrivee);
    void RechercheAvancee(const char * villeDepart, const char* villeArrivee);
    Trajet* GetTrajet(int n);
};


#endif //C_TP2_CATALOGUE_H
