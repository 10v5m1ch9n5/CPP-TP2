#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-auto"
//
// Created by lucas on 08/12/2020.
//

#include "Catalogue.h"
#include "CouleurTTY.h"
#include "ListeChaineeGenerique.h"
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

void Catalogue::RechercheRecursive(const char *villeDepart, const char *villeArrivee, Noeud *noeud)
{
    cout << "Recherche de " << villeDepart << " à " << villeArrivee << endl;
    if (strcmp(villeDepart, villeArrivee) == 0)
        return;

    Chainon* c = liste->Get(0);
    while (c != nullptr)
    {
        Trajet* t = c->GetTrajet();
        if (strcmp(t->GetDepart(), villeDepart) == 0)
        {
            Noeud* nouveau = new Noeud(t);
            noeud->AjouterEnfant(nouveau);
            RechercheRecursive(t->GetArrive(), villeArrivee, nouveau);
        }
        c = c->GetSuivant();
    }
    delete noeud;
}

void Catalogue::RechercheAvancee(const char *villeDepart, const char *villeArrivee)
{
    ListeChaineeGenerique<Noeud>* racines = new ListeChaineeGenerique<Noeud>();
    Chainon* c = liste->Get(0);
    while (c != nullptr)
    {
        Trajet* t = c->GetTrajet();
        if (strcmp(villeDepart, t->GetDepart()) == 0)
        {
            Noeud* nouveau = new Noeud(t);
            racines->Ajouter(nouveau);
            RechercheRecursive(t->GetArrive(), villeArrivee, nouveau);
        }
        c = c->GetSuivant();
    }

}
#pragma clang diagnostic pop