//
// Created by lucas on 29/11/2020.
//
#include <iostream>
#include <limits>
#include "trajet_compose.h"
#include "Catalogue.h"
using namespace std;

Catalogue catalogue;

void AjouterTrajetSimple()
{
    cin.ignore(1);
    char* villeDepart = new char [25];
    char* villeArrivee = new char [25];
    char* moyenTransport = new char [25];
    cout << "Entrez la ville de départ :" << endl;
    cin.getline(villeDepart, 25);
    cout << "Entrez la ville d'arrivée :" << endl;
    cin.getline(villeArrivee, 25);
    cout << "Entez le moyen de transport :" << endl;
    cin.getline(moyenTransport, 25);

    TrajetSimple* ts = new TrajetSimple(villeDepart, villeArrivee, moyenTransport);
    catalogue.AjouterTrajet(ts);

    delete[] villeDepart;
    delete[] villeArrivee;
    delete[] moyenTransport;
}

void AjouterTrajetCompose()
{
    int input;
    bool quitter = false;
    TrajetCompose *tc = new TrajetCompose();
    while (!quitter)
    {
        cout << "Que faire ?" << endl;
        cout << "1. Ajouter un trajet simple personnalisé" << endl;
        cout << "2. Ajouter un trajet existant" << endl;
        cout << "3. Conclure l'ajout" << endl;

        char *villeDepart = new char[25];
        char *villeArrivee = new char[25];
        char *moyenTransport = new char[25];
        int nTrajet;

        cin >> input;
        switch (input)
        {
            case 1:
                cin.ignore(1);
                cout << "Entrez la ville de départ" << endl;
                cin.getline(villeDepart, 25);
                cout << "Entez la ville d'arrivée" << endl;
                cin.getline(villeArrivee, 25);
                cout << "Entez le moyen de transport" << endl;
                cin.getline(moyenTransport, 25);
                tc->AjouterTrajet(villeDepart, villeArrivee, moyenTransport);
                break;
            case 2:
                cout << "Entez le numéro de votre trajet :" << endl;
                catalogue.AfficherTrajets();
                cin >> nTrajet;
                tc->AjouterTrajet(catalogue.GetTrajet(nTrajet-1));
                break;
            default:
                quitter = true;
                break;
        }

        delete[] villeDepart;
        delete[] villeArrivee;
        delete[] moyenTransport;
    }
    catalogue.AjouterTrajet(tc);

}

void AjouterTrajet()
{
    int input;
    cout << "1. Ajouter un trajet simple" << endl;
    cout << "2. Ajouter un trajet composé" << endl;
    cin >> input;
    switch (input) {
        case 1:
            AjouterTrajetSimple();
            break;
        case 2:
            AjouterTrajetCompose();
            break;
        default:
            cout << "Entrée incorrecte." << endl;
            break;
    }
}
void Rechercherparcours()
{
    char* villeDepart = new char [25];
    char* villeArrivee = new char [25];
    cin.ignore(1);
    cout << "Entrez la ville de départ :" << endl;
    cin.getline(villeDepart, 25);
    cout << "Entrez la ville d'arrivée :" << endl;
    cin.getline(villeArrivee, 25);

    catalogue.RechercherTrajet(villeDepart, villeArrivee);

    delete[] villeDepart;
    delete[] villeArrivee;
}

void AfficherCatalogue()
{
    catalogue.AfficherTrajets();
}

int main()
{
    int input;
    bool quitter = false;

    while (true)
    {
        cout << "Entrer l'action à réaliser :" << endl;
        cout << "1 : Ajouter un trajet au catalogue" << endl;
        cout << "2 : Afficher le catalogue" << endl;
        cout << "3 : Rechercher un parcours" << endl;
        cout << "4 : Quitter l'application" << endl;

        cin >> input;
        switch (input)
        {
            case 1:
                AjouterTrajet();
                break;
            case 2:
                AfficherCatalogue();
                break;
            case 3:
                Rechercherparcours();
                break;
            case 4:
                quitter = true;
                break;
            default:
                cout << "Veuillez entrer un chiffre correct." << endl;
                // Sortir cin de son "fail state" :
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
        }

        if(quitter)
        {
            cout << "Au revoir !" << endl;
            break;
        }
    }
}
