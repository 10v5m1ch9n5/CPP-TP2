#include "trajet.h"
class TrajetSimple
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
    void ToString();
};