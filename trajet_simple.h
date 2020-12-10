#ifndef TRAJETSIMPLE_H
#define TRAJETSIMPLE_H

#include "trajet.h"
class TrajetSimple : public Trajet
{
// Attributs
    private:
    char* depart;
    char* arrivee;
    char* moyenTransport;
// Constructeurs
    public:
    TrajetSimple(const char* villeDepart, const char* villeArrivee, const char* moyenTransport);
// Méthodes
    void ToString() override;
    const char* GetDepart() override;
    const char* GetArrive() override;
    const char* GetMoyenTransport();
// Destructeurs
    ~TrajetSimple();
};

#endif