//
// Created by lucas on 29/11/2020.
//
#include <iostream>
#include "liste_chainee.h"
using namespace std;

int main()
{
    int input;
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
