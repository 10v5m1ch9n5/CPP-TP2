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
#include <fstream>
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
            // cout << " || NB enfants = " << noeud->GetNbEnfants();
            cout << endl;
#endif
            trajetTrouve = true;
        }
        c = c->GetSuivant();
    }

    if (!trajetTrouve)
    {
#ifdef DEBUG
        cout << "Pas de continuité trouvée pour : " << villeDepart << endl;
#endif
        noeud->Debrancher();
        return;
    }



    int i = 0;
    int n;
    while ( (n = noeud->GetNbEnfants() ) > 0 && i < n)
    {
#ifdef DEBUG
        cout << "Recherche récursive dans : ";
        noeud->GetEnfant(i)->GetTrajet()->ToString();
        cout << endl;
#endif
        RechercheRecursive(villeArrivee, noeud->GetEnfant(i++));
        if (noeud->GetNbEnfants() < n)
            i--;
    }
    if (!noeud->GetNbEnfants())
        noeud->Debrancher();
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

void Catalogue::Sauvegarder( const char* filename)
{
    string const nomFichier("/Users/alexandresenouci/Desktop/lalili.txt");
    ofstream monFlux(nomFichier.c_str());
    Chainon *courant = this->liste->Get(0);
    int input;
    cin >> input;
    switch (input)
    {
        case 1:
            cin >> input;
            while (courant != nullptr)
            {
                TrajetSimple *trajetSimple = dynamic_cast<TrajetSimple *>(courant->GetTrajet());
                TrajetCompose *trajetCompose = dynamic_cast<TrajetCompose *>(courant->GetTrajet());
                if (trajetSimple != nullptr && input != 3)
                {
                    monFlux << "ts" << "\n" << endl;
                    monFlux << trajetSimple->GetDepart() << "\n" << endl;
                    monFlux << trajetSimple->GetArrive() << "\n" << endl;
                    monFlux << trajetSimple->GetMoyenTransport() << "\n" << endl;
                }
                if (trajetCompose != nullptr && input != 2)
                {
                    monFlux << "tc" << "\n" << endl;
                    TrajetSimple *ts;
                    int index = trajetCompose->GetTaillec();
                    for (int i = 0; i < index; i++)
                    {
                        ts = trajetCompose->SaveCompose(index - 1);
                        monFlux << "ts" << "\n" << endl;
                        monFlux << ts->GetDepart() << "\n" << endl;
                        monFlux << ts->GetArrive() << "\n" << endl;
                        monFlux << ts->GetMoyenTransport() << "\n" << endl;

                    }
                    monFlux << "end" << "\n" << endl;
                }
                courant = courant->GetSuivant();
            }
            break;
            /*
        case 2:
            char* villeDepart = new char [25];
            char* villeArrivee = new char [25];
            cin >> input;
            if (input)
            cin.ignore(1);
            cout << "Entrez la ville de départ :" << endl;
            cin.getline(villeDepart, 25);
            cout << "Entrez la ville d'arrivée :" << endl;
            cin.getline(villeArrivee, 25);
            while (courant != nullptr)
            {
                TrajetSimple *trajetSimple = dynamic_cast<TrajetSimple *>(courant->GetTrajet());
                TrajetCompose *trajetCompose = dynamic_cast<TrajetCompose *>(courant->GetTrajet());
                if (trajetSimple != nullptr && strcmp(courant->GetTrajet()->GetDepart(), villeDepart) == 0
                    && strcmp(courant->GetTrajet()->GetArrive(), villeArrivee) == 0)
                {
                    monFlux << "ts" << "\n" << endl;
                    monFlux << trajetSimple->GetDepart() << "\n" << endl;
                    monFlux << trajetSimple->GetArrive() << "\n" << endl;
                    monFlux << trajetSimple->GetMoyenTransport() << "\n" << endl;
                }
                if (trajetCompose != nullptr && strcmp(courant->GetTrajet()->GetDepart(), villeDepart) == 0
                    && strcmp(courant->GetTrajet()->GetArrive(), villeArrivee) == 0)
                {
                    monFlux << "tc" << "\n" << endl;
                    TrajetSimple *ts;
                    int index = trajetCompose->GetTaillec();
                    for (int i = 0; i < index; i++)
                    {
                        ts = trajetCompose->SaveCompose(index - 1);
                        monFlux << "ts" << "\n" << endl;
                        monFlux << ts->GetDepart() << "\n" << endl;
                        monFlux << ts->GetArrive() << "\n" << endl;
                        monFlux << ts->GetMoyenTransport() << "\n" << endl;

                    }
                    monFlux << "end" << "\n" << endl;

                }

                courant = courant->GetSuivant();
            }
            delete villeDepart[];
            delete villeArrivee[];
            break;
             */
    }
}
void Catalogue::Charger(const char *filename)
{
    cout << CouleurTTY(VERT) << "Début du chargement..." << CouleurTTY(RESET) << endl;
    ifstream fichier(filename);
    if (!fichier.is_open())
    {
        cerr << CouleurTTY(ROUGE) << "Charger : Impossible d'ouvrir le fichier !" << CouleurTTY(RESET) << endl;
        return;
    }

    string ligne;
    while (getline(fichier, ligne))
    {
        if (ligne == "quit:")
            break;

        if(ligne == "ts:")
        {
            TrajetSimple* ts = LectureTrajetSimple(fichier);
            liste->Ajouter(ts);
        }

        if (ligne == "tc:")
        {
            TrajetCompose* tc = LectureTrajetCompose(fichier);
            liste->Ajouter(tc);
        }
    }

    fichier.close();
    cout << CouleurTTY(VERT) << "Chargement terminé !" << CouleurTTY(RESET) << endl;
}

TrajetCompose* Catalogue::LectureTrajetCompose(std::ifstream &fs)
{
    TrajetCompose* tc = new TrajetCompose();
    string ligne;
    while (getline(fs, ligne))
    {
        if (ligne == "end:")
            return tc;

        if(ligne == "ts:")
        {
            TrajetSimple* ts = LectureTrajetSimple(fs);
            tc->AjouterTrajet(ts);
            delete ts;
        }

        if (ligne == "tc:")
        {
            TrajetCompose* nouveau = LectureTrajetCompose(fs);
            tc->AjouterTrajet(nouveau);
        }
    }

    cerr << CouleurTTY(ROUGE) << "Erreur dans la lecture du trajet composé !" << CouleurTTY(RESET) << endl;
    return nullptr;
}

TrajetSimple * Catalogue::LectureTrajetSimple(std::ifstream &fs)
{
    char* villeDepart = new char [25];
    fs.getline(villeDepart, 25);
    char* villeArrivee = new char [25];
    fs.getline(villeArrivee, 25);
    char* moyenTransport = new char [25];
    fs.getline(moyenTransport, 25);
    TrajetSimple* ts = new TrajetSimple(villeDepart, villeArrivee, moyenTransport);
    delete[] villeDepart;
    delete[] villeArrivee;
    delete[] moyenTransport;
    return ts;
}
