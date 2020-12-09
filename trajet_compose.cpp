//
// Created by lucas on 03/12/2020.
//

#include <iostream>
#include <cstring>
using namespace std;
#include "trajet_compose.h"
#include "CouleurTTY.h"

TrajetCompose::TrajetCompose() {
#ifdef MAP
    cout << CouleurTTY(JAUNE) << "MAP : Appel au constructeur de TrajetCompose" << CouleurTTY(RESET) << endl;
#endif
    listeChainee = new ListeChainee();
}

TrajetCompose::~TrajetCompose() noexcept {
#ifdef MAP
    cout << CouleurTTY(JAUNE) << "MAP : Appel au destructeur de TrajetCompose" << CouleurTTY(RESET) << endl;
#endif
    delete listeChainee;
}

void TrajetCompose::AjouterTrajet(const char *villeDepart, const char *villeArrivee, const char *moyenTransport) {
    TrajetSimple* ts = new TrajetSimple(villeDepart, villeArrivee, moyenTransport);
    AjouterTrajet(ts);
    delete ts;
}

void TrajetCompose::AjouterTrajet(Trajet * t) {
    if(listeChainee->GetTaille() != 0 && strcmp(t->GetDepart(), GetArrive()) != 0)
    {
        cout <<  "Ville de départ différente de la ville d'arrivée du trajet" << endl;
        return;
    }
    TrajetSimple* trajetCopie = new TrajetSimple(t->GetDepart(), t->GetArrive(), "inutile");
    listeChainee->Ajouter(trajetCopie);
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
