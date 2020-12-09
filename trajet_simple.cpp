#include "trajet_simple.h"
#include <iostream>

using namespace std;

TrajetSimple::TrajetSimple(const char* villeDepart, const char* villeArrivee, const char* moyenTransport)
{
#ifdef MAP
    cout << "MAP : Appel au constructeur de TrajetSimple" << endl;
#endif
    this->depart = villeDepart;
    this->arrivee = villeArrivee;
    this->moyenTransport = moyenTransport;
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
