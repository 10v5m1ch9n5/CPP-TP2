#include "chainon.h"
class ListeChainee
{
public:
// Méthodes
    void ToString(void);
    void Ajouter(Trajet* t);
    void Supprimer(int index);
    Chainon* Get(int index);
    int GetTaille();
// Constructeurs
    ListeChainee();
protected:
    Chainon* premier;
    Chainon* dernier;
    int taille;
};