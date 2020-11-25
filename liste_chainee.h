#include "chainon.h"
class ListeChainee
{
public:
    ListeChainee(int taille);
protected:
    Chainon* premier;
    int taille;
};