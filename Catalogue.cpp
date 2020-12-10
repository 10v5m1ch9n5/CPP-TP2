//
// Created by lucas on 08/12/2020.
//

#include "Catalogue.h"
#include "CouleurTTY.h"
#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

Catalogue::Catalogue() {
#ifdef MAP
    cout << CouleurTTY(JAUNE) << "MAP : Appel au constructeur de Catalogue" << CouleurTTY(RESET) << endl;
#endif
    liste = new ListeChainee();
}

Catalogue::~Catalogue() {
#ifdef MAP
    cout << CouleurTTY(JAUNE) << "MAP : Appel au destructeur de Catalogue" << CouleurTTY(RESET) << endl;
#endif
    delete liste;
}

void Catalogue::AjouterTrajet(Trajet* trajet) {
    liste->Ajouter(trajet);
}

void Catalogue::AfficherTrajets() {
    liste->ToString();
}

Trajet * Catalogue::GetTrajet(int n) {
    assert(n < liste->GetTaille());
    return liste->Get(n)->GetTrajet();
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
            courant->GetTrajet()->ToString();
        }
        courant = courant->GetSuivant();
    }
}

ListeChainee* Catalogue::RechercheRecursive(const char *villeDepart, const char *villeArrivee)
{
    ListeChainee* resultats = new ListeChainee();

    if(strcmp(villeDepart, villeArrivee) != 0)
    {
        Chainon* c = liste->Get(0);
        while (c != nullptr)
        {
            if (strcmp(c->GetTrajet()->GetDepart(), villeDepart) == 0)
            {
                resultats->Ajouter(c->GetTrajet());
                RechercheRecursive(c->GetTrajet()->GetArrive(), villeArrivee);
            }
        }
    }
    else
    {
        return nullptr;
    }
}
