#include "chainon.h"
class ListeChainee
{
public:
// Méthodes
    void ToString(void);
    void Ajouter(TrajetSimple* ts);
    void Supprimer(int index);
    Chainon* Get(int index);
// Constructeurs
    ListeChainee();
protected:
    Chainon* premier;
    Chainon* dernier;
    int taille;
};