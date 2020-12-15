//
// Created by lucas on 08/12/2020.
//

#include "Catalogue.h"
#include "CouleurTTY.h"
#include "ListeChaineeGenerique.h"
#include "trajet_compose.h"
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
    if (liste->GetTaille() == 0)
        return;

    Chainon* courant = liste->Get(0);
    cout << CouleurTTY(VERT);
    while (courant != nullptr)
    {
        if(strcmp(courant->GetTrajet()->GetDepart(), villeDepart) == 0
        && strcmp(courant->GetTrajet()->GetArrive(), villeArrivee) == 0)
        {
            courant->GetTrajet()->ToString();
            cout << endl;
        }
        courant = courant->GetSuivant();
    }
    cout << CouleurTTY(RESET);
}

void Catalogue::RechercheRecursive(const char *villeArrivee, Noeud *noeud)
{
    const char* villeDepart = noeud->GetTrajet()->GetArrive();
    if (strcmp(villeDepart, villeArrivee) == 0)
        return;

    bool trajetTrouve = false;
    Chainon* c = liste->Get(0);
    while (c != nullptr) // Ajout des enfants
    {
        Trajet* t = c->GetTrajet();
        if (strcmp(t->GetDepart(), villeDepart) == 0)
        {
            Noeud* nouveau = new Noeud(t);
            noeud->AjouterEnfant(nouveau);
#ifdef DEBUG
            cout << "Ajout enfant : ";
            t->ToString();
            cout << endl;
#endif
            // RechercheRecursive(t->GetArrive(), villeArrivee, nouveau);
            trajetTrouve = true;
        }
        c = c->GetSuivant();
    }

    if (!trajetTrouve)
    {
#ifdef DEBUG
        cout << "Pas de continuité trouvée pour : " << villeDepart << endl;
#endif
        noeud->DetruireCascade();
        return;
    }



    for (int i = 0; i < noeud->GetNbEnfants(); ++i)
    {
#ifdef DEBUG
        cout << "Recherche récursive dans : ";
        noeud->GetEnfant(i)->GetTrajet()->ToString();
        cout << endl;
#endif
        RechercheRecursive(villeArrivee, noeud->GetEnfant(i));
    }
}

void Catalogue::RechercheAvancee(const char *villeDepart, const char *villeArrivee)
{
#ifdef DEBUG
    cout << "Construction de l'arbre..." << endl;
#endif
    // Construire un arbre avec toutes les possibilités
    ListeChaineeGenerique<Noeud>* racines = new ListeChaineeGenerique<Noeud>();
    Chainon* c = liste->Get(0);
    while (c != nullptr)
    {
        Trajet* t = c->GetTrajet();
        if (strcmp(villeDepart, t->GetDepart()) == 0)
        {
            Noeud* nouveau = new Noeud(t);
            racines->Ajouter(nouveau);
#ifdef DEBUG
            cout << "-> Nouvelle racine (" << racines->GetTaille()-1 << ") : " << villeDepart << " -> " << t->GetArrive() << endl;
#endif
            RechercheRecursive(villeArrivee, nouveau);
        }
        c = c->GetSuivant();
    }


#ifdef DEBUG
    cout << "Nettoyage des racines..." << endl;
#endif
    // Enlever les racines qui n'aboutissent à aucun résultat
    int i = 0;
    while (i < racines->GetTaille())
    {
        if (racines->Get(i)->GetNbEnfants() == 0)
        {
            if (strcmp(racines->Get(i)->GetTrajet()->GetDepart(), villeDepart) == 0 && strcmp(racines->Get(i)->GetTrajet()->GetArrive(), villeArrivee) == 0)
            {
                cout << CouleurTTY(VERT);
                racines->Get(i)->GetTrajet()->ToString();
                cout << CouleurTTY(RESET) << endl;
            }
            racines->Supprimer(i);
#ifdef DEBUG
            cout << "-> Racine supprimée" << endl;
#endif
            i = 0;
        }
        else
        {
            i++;
        }
    }


#ifdef DEBUG
    cout << "Affichage des résultats..." << endl;
#endif
    // Afficher les résultats
    ListeChainee resultats;
    int iRacine = 0;
    while (racines->GetTaille() > 0) // Parcours de chaque racine
    {
        Noeud* racineCourante = racines->Get(iRacine);
#ifdef DEBUG
        cout << "Racine n° " << iRacine << endl;
#endif
        while (racineCourante->GetNbEnfants() != 0) // Parcours de tous les trajets possibles dans la racine
        {
            TrajetCompose resultat;
            Noeud* noeudCourant = racineCourante;
            while (true)
            {
                resultat.AjouterTrajet(noeudCourant->GetTrajet());
                Noeud* precedent = noeudCourant;
                noeudCourant = noeudCourant->GetEnfant(0);
                if (noeudCourant == nullptr)
                {
                    precedent->DetruireCascade();
                    cout << CouleurTTY(VERT);
                    resultat.ToString();
                    cout << CouleurTTY(RESET) << endl;
                    break;
                }
            }
        }


        if (iRacine++ == racines->GetTaille()-1)
            break;
    }

    delete racines;
}
