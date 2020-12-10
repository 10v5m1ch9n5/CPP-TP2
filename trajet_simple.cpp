#include "trajet_simple.h"
#include <iostream>
#include <cstring>

using namespace std;

TrajetSimple::TrajetSimple(const char* villeDepart, const char* villeArrivee, const char* moyenTransport)
{
#ifdef MAP
    cout << "MAP : Appel au constructeur de TrajetSimple" << endl;
#endif
    depart = new char [25];
    arrivee = new char [25];
    this->moyenTransport = new char [25];
    strcpy(depart, villeDepart);
    strcpy(arrivee, villeArrivee);
    strcpy(this->moyenTransport, moyenTransport);
}

TrajetSimple::~TrajetSimple() noexcept {
#ifdef MAP
    cout << "MAP : Appel au destructeur de TrajetSimple" << endl;
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
