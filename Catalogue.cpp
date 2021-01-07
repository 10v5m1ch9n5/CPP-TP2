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

void Catalogue::Sauvegarder()
{
    string const nomFichier("/Users/alexandresenouci/Desktop/test.txt");
    ofstream monFlux(nomFichier.c_str());
    Chainon *courant = this->liste->Get(0);
    int input;
    cout << "veuillez choisir un mode de sauvegarde" << endl;
    cout << "1) sauvegarde par type de trajet" << endl;
    cout << "2) sauvegarde en fonction de depart et/ou arrivé" << endl;
    cin >> input;
    switch (input)
    {
        case 1:
            cout << "veuillez choisir un mode de sauvegarde de trajet" << endl;
            cout << "1) sauvegarde intégrale" << endl;
            cout << "2) sauvegarde trajet simple" << endl;
            cout << "3) sauvegarde trajet composé" << endl;
            cin >> input;
            while (courant != nullptr)
            {
                TrajetSimple *trajetSimple = dynamic_cast<TrajetSimple *>(courant->GetTrajet());
                TrajetCompose *trajetCompose = dynamic_cast<TrajetCompose *>(courant->GetTrajet());
                if (trajetSimple != nullptr && input != 3)
                {
                    monFlux << "ts:" << endl;
                    monFlux << trajetSimple->GetDepart() << endl;
                    monFlux << trajetSimple->GetArrive() << endl;
                    monFlux << trajetSimple->GetMoyenTransport() << endl;
                }
                if (trajetCompose != nullptr && input != 2)
                {
                    monFlux << "tc:" << endl;
                    TrajetSimple *ts;
                    int index = trajetCompose->GetTaillec();
                    for (int i = 0; i < index; i++)
                    {
                        ts = trajetCompose->SaveCompose(i);
                        monFlux << "ts:" << endl;
                        monFlux << ts->GetDepart() << endl;
                        monFlux << ts->GetArrive() << endl;
                        monFlux << ts->GetMoyenTransport() << endl;

                    }
                    monFlux << "end:" << endl;
                }
                courant = courant->GetSuivant();
            }
            break;

        case 2:
            char* villeDepart = new char [25];
            char* villeArrivee = new char [25];
            cout << "veuillez choisir un mode de sauvegarde depart/arrivé" << endl;
            cout << "1) sauvegarde en fonction d'un depart" << endl;
            cout << "2) sauvegarde en fonction d'un arrivé" << endl;
            cout << "3) sauvegarde en fonction d'un départ et arrivé" << endl;
            cin >> input;
            if (input == 1 )
            {
                cin.ignore(1);
                cout << "Entrez la ville de départ :" << endl;
                cin.getline(villeDepart, 25);
            }
            if (input == 2 )
            {
                cin.ignore(1);
                cout << "Entrez la ville d'arrivée :" << endl;
                cin.getline(villeArrivee, 25);
            }
            if (input ==3)
            {
                cin.ignore(1);
                cout << "Entrez la ville de départ :" << endl;
                cin.getline(villeDepart, 25);
                cout << "Entrez la ville d'arrivée :" << endl;
                cin.getline(villeArrivee, 25);
            }

            while (courant != nullptr)
            {
                TrajetSimple *trajetSimple = dynamic_cast<TrajetSimple *>(courant->GetTrajet());
                TrajetCompose *trajetCompose = dynamic_cast<TrajetCompose *>(courant->GetTrajet());
                switch(input)
                {
                    case 1:
                        if (trajetSimple != nullptr && strcmp(courant->GetTrajet()->GetDepart(), villeDepart) == 0)
                        {
                            monFlux << "ts:" << endl;
                            monFlux << trajetSimple->GetDepart() << endl;
                            monFlux << trajetSimple->GetArrive() << endl;
                            monFlux << trajetSimple->GetMoyenTransport() << endl;
                        }
                        if (trajetCompose != nullptr && strcmp(courant->GetTrajet()->GetDepart(), villeDepart) == 0)
                        {
                            monFlux << "tc:" << endl;
                            TrajetSimple *ts;
                            int index = trajetCompose->GetTaillec();
                            for (int i = 0; i < index; i++)
                            {
                                ts = trajetCompose->SaveCompose(i);
                                monFlux << "ts:" << endl;
                                monFlux << ts->GetDepart() << endl;
                                monFlux << ts->GetArrive() << endl;
                                monFlux << ts->GetMoyenTransport() << endl;

                            }
                            monFlux << "end:" << endl;
                        }
                    case 2:
                        if (trajetSimple != nullptr && strcmp(courant->GetTrajet()->GetArrive(), villeArrivee) == 0)
                        {
                            monFlux << "ts:" << endl;
                            monFlux << trajetSimple->GetDepart() << endl;
                            monFlux << trajetSimple->GetArrive() << endl;
                            monFlux << trajetSimple->GetMoyenTransport() << endl;
                        }
                        if (trajetCompose != nullptr && strcmp(courant->GetTrajet()->GetArrive(), villeArrivee) == 0)
                        {
                            monFlux << "tc:" << endl;
                            TrajetSimple *ts;
                            int index = trajetCompose->GetTaillec();
                            for (int i = 0; i < index; i++)
                            {
                                ts = trajetCompose->SaveCompose(i);
                                monFlux << "ts:" << endl;
                                monFlux << ts->GetDepart() << endl;
                                monFlux << ts->GetArrive() << endl;
                                monFlux << ts->GetMoyenTransport() << endl;

                            }
                            monFlux << "end:" << endl;
                        }
                    case 3:
                        if (trajetSimple != nullptr && strcmp(courant->GetTrajet()->GetDepart(), villeDepart) == 0
                            && strcmp(courant->GetTrajet()->GetArrive(), villeArrivee) == 0)
                        {
                            monFlux << "ts:" << endl;
                            monFlux << trajetSimple->GetDepart() << endl;
                            monFlux << trajetSimple->GetArrive() << endl;
                            monFlux << trajetSimple->GetMoyenTransport() << endl;
                        }
                        if (trajetCompose != nullptr && strcmp(courant->GetTrajet()->GetDepart(), villeDepart) == 0
                            && strcmp(courant->GetTrajet()->GetArrive(), villeArrivee) == 0)
                        {
                            monFlux << "tc:" << endl;
                            TrajetSimple *ts;
                            int index = trajetCompose->GetTaillec();
                            for (int i = 0; i < index; i++)
                            {
                                ts = trajetCompose->SaveCompose(i);
                                monFlux << "ts:" << endl;
                                monFlux << ts->GetDepart() << endl;
                                monFlux << ts->GetArrive() << endl;
                                monFlux << ts->GetMoyenTransport() << endl;

                            }
                            monFlux << "end:" << endl;
                        }
                }
                courant = courant->GetSuivant();

            }
            delete [] villeDepart;
            delete [] villeArrivee;


    }
}

void Catalogue::Charger(const char *filename)
{
    bool tsUniquement, tcUniquement, departImpose, arriveeImposee;
    tsUniquement = tcUniquement = departImpose = arriveeImposee = false;
    char* villeDepart = nullptr;
    char* villeArrivee = nullptr;

    int input;
    cout << "Quel type de chargement effectuer ?" << endl;
    cout << "1 : Charger tous les trajets" << endl;
    cout << "2 : Charger uniquement les trajets simples" << endl;
    cout << "3 : Charger uniquement les trajets composés" << endl;
    cout << "4 : Charger en spécifiant la ville de départ ou la ville d'arrivée" << endl;
    cin >> input;

    switch (input)
    {
        case 2:
            tsUniquement = true;
            break;
        case 3:
            tcUniquement = true;
            break;
        case 4:
            cout << "Spécifier la ville de départ ? (0/1)" << endl;
            cin >> input;
            cin.ignore(1);
            if (input)
            {
                cout << "Entrez la ville de départ :" << endl;
                departImpose = true;
                villeDepart = new char [25];
                cin.getline(villeDepart, 25);
            }
            cout << "Spécifier la ville d'arrivée ? (0/1)" << endl;
            cin >> input;
            cin.ignore(1);
            if (input)
            {
                cout << "Entrez la ville d'arrivée :" << endl;
                arriveeImposee = true;
                villeArrivee = new char [25];
                cin.getline(villeArrivee, 25);
            }
        default:
        case 1:
            break;
    }

    cout << CouleurTTY(VERT) << "Début du chargement..." << CouleurTTY(RESET) << endl;
    ifstream fichier(filename);
    if (!fichier.is_open())
    {
        cerr << CouleurTTY(ROUGE) << "ConfigurerChargement : Impossible d'ouvrir le fichier !" << CouleurTTY(RESET) << endl;
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

            // TODO : factoriser ce code dans une même fonction
            bool arriveeCorrespond = arriveeImposee && strcmp(ts->GetArrive(), villeArrivee) == 0;
            bool departCorrespond = departImpose && strcmp(ts->GetDepart(), villeDepart) == 0;
            if( !tcUniquement && ((!departImpose && !arriveeImposee) || (departImpose && arriveeImposee && departCorrespond && arriveeCorrespond) || (departImpose && !arriveeImposee && departCorrespond) || (!departImpose && arriveeImposee && arriveeCorrespond)) )
                liste->Ajouter(ts);
            else
                delete ts;
        }

        if (ligne == "tc:")
        {
            TrajetCompose* tc = LectureTrajetCompose(fichier);

            bool arriveeCorrespond = arriveeImposee && strcmp(tc->GetArrive(), villeArrivee) == 0;
            bool departCorrespond = departImpose && strcmp(tc->GetDepart(), villeDepart) == 0;
            if( !tsUniquement && ((!departImpose && !arriveeImposee) || (departImpose && arriveeImposee && departCorrespond && arriveeCorrespond) || (departImpose && !arriveeImposee && departCorrespond) || (!departImpose && arriveeImposee && arriveeCorrespond)) )
                liste->Ajouter(tc);
            else
                delete tc;
        }
    }

    fichier.close();
    cout << CouleurTTY(VERT) << "Chargement terminé !" << CouleurTTY(RESET) << endl;

    if (departImpose)
        delete[] villeDepart;
    if (arriveeImposee)
        delete[] villeArrivee;
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
