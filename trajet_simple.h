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
    void ToString();
    char* GetDepart(TrajetSimple* trajetSimple);
    char* GetArrive(TrajetSimple* trajetSimple);
// Destructeurs
    ~TrajetSimple();

    const char *GetDepart();
};