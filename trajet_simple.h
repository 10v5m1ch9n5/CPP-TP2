#ifndef TRAJETSIMPLE_H
#define TRAJETSIMPLE_H

#include "trajet.h"
class TrajetSimple : public Trajet
{
// Attributs
    private:
    const char* depart;
    const char* arrivee;
    const char* moyenTransport;
// Constructeurs
    public:
    TrajetSimple(const char* villeDepart, const char* villeArrivee, const char* moyenTransport);
// Méthodes
    void ToString();
    const char* GetDepart();
    const char* GetArrive();
// Destructeurs
    ~TrajetSimple() = default;
};

#endif