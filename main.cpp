//
// Created by lucas on 29/11/2020.
//
#include <iostream>
#include "liste_chainee.h"
using namespace std;

Trajet* catalogue;
int iCatalogue;

void AjouterTrajetSimple()
{
    char* villeDepart = new char [25];
    char* villeArrivee = new char [25];
    char* moyenTransport = new char [25];
    cout << "Entrez la ville de départ :" << endl;
    cin.getline(villeDepart, 25);
    cout << "Entrez la ville d'arrivée :" << endl;
    cin.getline(villeArrivee, 25);
    cout << "Entez le moyen de transport :" << endl;
    cin.getline(moyenTransport, 25);

    catalogue[iCatalogue] = new TrajetSimple(villeDepart, villeArrivee, moyenTransport);
}

void AjouterTrajetCompose()
{

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

int main()
{
    int input;
    catalogue = new Trajet[100];
    iCatalogue = 0;
    bool quitter = false;

    while (true)
    {
        cout << "Entrer l'action à réaliser :" << endl;
        cout << "1 : Ajouter un trajet au catalogue" << endl;
        cout << "2 : Afficher un trajet" << endl;
        cout << "3 : Rechercher un parcours" << endl;
        cout << "4 : Quitter l'application" << endl;

        cin >> input;
        switch (input)
        {
            case 1:
                cout << "Ajouter" << endl;
                break;
            case 2:
                cout << "Afficher" << endl;
                break;
            case 3:
                cout << "Rechercher" << endl;
                break;
            case 4:
                quitter = true;
                break;
            default:
                cout << "Veuillez entrer un chiffre correct." << endl;
        }

        if(quitter)
        {
            cout << "Au revoir !" << endl;
            break;
        }
    }
}
