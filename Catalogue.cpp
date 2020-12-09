//
// Created by lucas on 08/12/2020.
//

#include "Catalogue.h"
#include <iostream>
#include <cstring>
using namespace std;

Catalogue::Catalogue() {
#ifdef MAP
    cout << "MAP : Appel au constructeur de Catalogue" << endl;
#endif
    liste = new ListeChainee();
}

Catalogue::~Catalogue() {
#ifdef MAP
    cout << "MAP : Appel au destructeur de Catalogue" << endl;
#endif
    delete liste;
}

void Catalogue::AjouterTrajet(Trajet* trajet) {
    liste->Ajouter(trajet);
}

void Catalogue::AfficherTrajets() {
    liste->ToString();
}

void Catalogue::RechercherTrajet(char *villeDepart, char *villeArrivee)
{
    cout << "Résultats de la recherche :" << endl;
    if (liste->GetTaille() == 0)
        return;

    Chainon* courant = liste->Get(0);
    while (courant != nullptr)
    {
        if(strcmp(courant->GetTrajet()->GetDepart(), villeDepart) == 0
        && strcmp(courant->GetTrajet()->GetArrive(), villeArrivee) == 0)
        {
            courant->ToString();
        }
        courant = courant->GetSuivant();
    }
}