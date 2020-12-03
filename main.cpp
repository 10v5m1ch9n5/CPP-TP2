//
// Created by lucas on 29/11/2020.
//
#include <iostream>
#include <cstring>
#include "liste_chainee.h"
using namespace std;

Trajet* catalogue[100];
int iCatalogue;

void AjouterTrajetSimple()
{
    TrajetSimple* tsptr;
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

    catalogue[iCatalogue] = new TrajetSimple(villeDepart, villeArrivee, moyenTransport);
    iCatalogue++;

    delete[] villeDepart;
    delete[] villeArrivee;
    delete[] moyenTransport;
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
void Rechercherparcours()
{
    char* villeDepart = new char [25];
    char* villeArrivee = new char [25];

    cout << "Entrez la ville de départ :" << endl;
    cin.getline(villeDepart, 25);
    cout << "Entrez la ville d'arrivée :" << endl;
    cin.getline(villeArrivee, 25);
    for(int i = 0; i < iCatalogue; i++)
    {
        if (strcmp(villeDepart, catalogue[i]->GetDepart()) == 0 and strcmp(villeArrivee, catalogue[i]->GetArrive()) == 0)
        {
            cout << "Trajet n° " << i << " :" << endl;
            catalogue[i]->ToString();
        }
    }




}
void AfficherCatalogue()
{
    for(int i = 0; i < iCatalogue; i++)
    {
        cout << "Trajet n° " << i << " :" << endl;
        catalogue[i]->ToString();
    }
}

int main()
{
    int input;
    iCatalogue = 0;
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
                break;
        }

        if(quitter)
        {
            cout << "Au revoir !" << endl;
            break;
        }
    }
}
