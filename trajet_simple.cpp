#include "trajet_simple.h"
#include "CouleurTTY.h"
#include <iostream>
#include <cstring>

using namespace std;

TrajetSimple::TrajetSimple(const char* villeDepart, const char* villeArrivee, const char* moyenTransport)
{
#ifdef MAP
    cout << CouleurTTY(JAUNE) << "MAP : Appel au constructeur de TrajetSimple" << CouleurTTY(RESET) << endl;
#endif
    depart = new char [25];
    arrivee = new char [25];
    this->moyenTransport = new char [25];
    strcpy(depart, villeDepart);
    strcpy(arrivee, villeArrivee);
    strcpy(this->moyenTransport, moyenTransport);
    nbFoisPointe=0;
}

TrajetSimple::~TrajetSimple() noexcept {
#ifdef MAP
    cout << CouleurTTY(JAUNE) << "MAP : Appel au destructeur de TrajetSimple" << CouleurTTY(RESET) << endl;
#endif
    delete[] depart;
    delete[] arrivee;
    delete[] moyenTransport;
}

void TrajetSimple::ToString()
{
cout << this->depart << " -> " << this->arrivee << " (" << this->moyenTransport << ")";
}

const char* TrajetSimple::GetDepart()
{
    return depart;
}

const char* TrajetSimple::GetArrive()
{
    return arrivee;
}

const char * TrajetSimple::GetMoyenTransport()
{
    return moyenTransport;
}
