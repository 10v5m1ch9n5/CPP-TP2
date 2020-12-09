//
// Created by lucas on 03/12/2020.
//

#include <iostream>
#include <cstring>
using namespace std;
#include "trajet_compose.h"

TrajetCompose::TrajetCompose() {
#ifdef MAP
    cout << "MAP : Appel au constructeur de TrajetCompose" << endl;
#endif
    listeChainee = new ListeChainee();
}

TrajetCompose::~TrajetCompose() noexcept {
#ifdef MAP
    cout << "MAP : Appel au destructeur de TrajetCompose" << endl;
#endif
    delete listeChainee;
}

void TrajetCompose::AjouterTrajet(const char *villeDepart, const char *villeArrivee, const char *moyenTransport) {
    TrajetSimple* ts = new TrajetSimple(villeDepart, villeArrivee, moyenTransport);
    AjouterTrajet(ts);
}

void TrajetCompose::AjouterTrajet(Trajet * t) {
    if(listeChainee->GetTaille() != 0 && strcmp(t->GetDepart(), GetArrive()) != 0)
    {
        cout <<  "Ville de départ différente de la ville d'arrivée du trajet" << endl;
        return;
    }
    listeChainee->Ajouter(t);
}

const char * TrajetCompose::GetArrive() {
    if(listeChainee->GetTaille() == 0)
        return nullptr;
    return listeChainee->Get(listeChainee->GetTaille()-1)->GetTrajet()->GetArrive();
}

const char * TrajetCompose::GetDepart() {
    if(listeChainee->GetTaille() == 0)
        return nullptr;
    return listeChainee->Get(0)->GetTrajet()->GetDepart();
}

void TrajetCompose::ToString() {
    cout << "De " << GetDepart() << " à " << GetArrive();
    cout << " [ ";
    Chainon* courant = listeChainee->Get(0);
    while (courant->GetSuivant() != nullptr)
    {
        cout << courant->GetTrajet()->GetDepart();
        cout << " -> ";
        cout << courant->GetTrajet()->GetArrive();
        cout << " | ";
        courant = courant->GetSuivant();
    }
    cout << courant->GetTrajet()->GetDepart();
    cout << " -> ";
    cout << courant->GetTrajet()->GetArrive();
    cout << " ]" << endl;
}
