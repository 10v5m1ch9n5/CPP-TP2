#include "trajet_simple.h"
#include "CouleurTTY.h"
#include <iostream>
#include <cstring>

using namespace std;

TrajetSimple::TrajetSimple(const char* villeDepart, const char* villeArrivee, const char* moyenTransport) : Trajet(0)
{
    depart = new char [25];
    arrivee = new char [25];
    this->moyenTransport = new char [25];
    strcpy(depart, villeDepart);
    strcpy(arrivee, villeArrivee);
    strcpy(this->moyenTransport, moyenTransport);
#ifdef MAP
    cout << CouleurTTY(JAUNE) << "MAP : Appel au constructeur de TrajetSimple ";
    ToString();
    cout << CouleurTTY(RESET) << endl;
#endif
}

TrajetSimple::TrajetSimple(const TrajetSimple &t) : Trajet(0)
{
#ifdef MAP
    cout << CouleurTTY(JAUNE) << "MAP : Appel au constructeur de copie de TrajetSimple" << endl;
#endif
    depart = new char [25];
    arrivee = new char [25];
    moyenTransport = new char [25];
    strcpy(depart, t.depart);
    strcpy(arrivee, t.arrivee);
    strcpy(moyenTransport, t.moyenTransport);
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
