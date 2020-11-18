#include "trajet_simple.h"
#include <iostream>
#include <cstring>
using namespace std;

TrajetSimple::TrajetSimple(const char* villeDepart, const char* villeArrivee, const char* moyenTransport)
{
    int taille = strlen(villeDepart);
    this->depart = new char[taille+1];
    strcpy(this->depart, villeDepart);

    taille = strlen(villeArrivee);
    this->arrivee = new char[taille+1];
    strcpy(this->arrivee, villeArrivee);

    taille = strlen(moyenTransport);
    this->moyenTransport = new char[taille+1];
    strcpy(this->moyenTransport, moyenTransport);
}

void TrajetSimple::ToString()
{
    cout << "De "<< this->depart << " à " << this->arrivee << " en " << this->moyenTransport << endl;
}