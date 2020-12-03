#include "trajet_simple.h"
#include <iostream>
#include <cstring>
using namespace std;

TrajetSimple::TrajetSimple(const char* villeDepart, const char* villeArrivee, const char* moyenTransport)
{
    this->depart = villeDepart;
    this->arrivee = villeArrivee;
    this->moyenTransport = moyenTransport;
}

void TrajetSimple::ToString()
{
    cout << "De "<< this->depart << " à " << this->arrivee << " en " << this->moyenTransport << endl;
}

const char* TrajetSimple::GetDepart()
{
    return depart;
}

const char* TrajetSimple::GetArrive()
{
    return arrivee;
}
