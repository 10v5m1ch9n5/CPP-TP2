//
// Created by lucas on 03/12/2020.
//

#include <iostream>
#include <cstring>
using namespace std;
#include "trajet_compose.h"
#include "CouleurTTY.h"

TrajetCompose::TrajetCompose() : Trajet(0)
{
#ifdef MAP
    cout << CouleurTTY(JAUNE) << "MAP : Appel au constructeur de TrajetCompose" << CouleurTTY(RESET) << endl;
#endif
    listeChainee = new ListeChainee();
    nbFoisPointe=0;
}

TrajetCompose::~TrajetCompose() noexcept
{
#ifdef MAP
    cout << CouleurTTY(JAUNE) << "MAP : Appel au destructeur de TrajetCompose" << CouleurTTY(RESET) << endl;
#endif
    delete listeChainee;
}

bool TrajetCompose::AjoutPossible(Trajet *t)
{
    if(t == nullptr)
        return false;
    if(listeChainee->GetTaille() != 0 && strcmp(t->GetDepart(), GetArrive()) != 0)
    {
        cout << CouleurTTY(ROUGE) <<  "Ville de départ différente de la ville d'arrivée du trajet. Annulation." << CouleurTTY(RESET) << endl;
        return false;
    }
    return true;
}

void TrajetCompose::AjouterTrajetSimple(const char *villeDepart, const char *villeArrivee, const char *moyenTransport)
{
    TrajetSimple* ts = new TrajetSimple(villeDepart, villeArrivee, moyenTransport);
    if(AjoutPossible(ts))
        listeChainee->Ajouter(ts);
    else
        delete ts;
}

void TrajetCompose::AjouterTrajetSimple(TrajetSimple *ts)
{
    if(AjoutPossible(ts))
    {
        TrajetSimple *trajetCopie = new TrajetSimple(ts->GetDepart(), ts->GetArrive(), ts->GetMoyenTransport());
        listeChainee->Ajouter(trajetCopie);
    }
}

void TrajetCompose::AjouterTrajetCompose(TrajetCompose *tc)
{
    if(AjoutPossible(tc))
        listeChainee->Ajouter(tc);
}

void TrajetCompose::AjouterTrajet(Trajet *t)
{
    AjouterTrajetCompose(dynamic_cast<TrajetCompose*>(t));
    AjouterTrajetSimple(dynamic_cast<TrajetSimple*>(t));
}

const char * TrajetCompose::GetArrive()
{
    if(listeChainee->GetTaille() == 0)
        return nullptr;
    return listeChainee->Get(listeChainee->GetTaille()-1)->GetTrajet()->GetArrive();
}

const char * TrajetCompose::GetDepart()
{
    if(listeChainee->GetTaille() == 0)
        return nullptr;
    return listeChainee->Get(0)->GetTrajet()->GetDepart();
}

void TrajetCompose::ToString()
{
    cout << GetDepart() << " -> " << GetArrive();
    cout << " [ ";
    Chainon* courant = listeChainee->Get(0);
    while (courant->GetSuivant() != nullptr)
    {
        courant->GetTrajet()->ToString();
        cout << " | ";
        courant = courant->GetSuivant();
    }
    courant->GetTrajet()->ToString();
    cout << " ]";
}

TrajetSimple* TrajetCompose::SaveComposé(int index)
{
    Chainon* courant = listeChainee->Get(index);
    return dynamic_cast<TrajetSimple*>(courant->GetTrajet());
}

int TrajetCompose::GetTaillec()
{
    return listeChainee->GetTaille();
}
