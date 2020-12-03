#include "trajet.h"
#include "liste_chainee.h"
class TrajetCompose : public Trajet
{
private:
    ListeChainee* lc;
public:
// Constructeur
    TrajetCompose(ListeChainee* lc);
// Destructeur
    ~TrajetCompose();
};