//
// Created by lucas on 08/12/2020.
//

#include "Catalogue.h"
#include <iostream>
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