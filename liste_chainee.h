#ifndef LISTECHAINEE_H
#define LISTECHAINEE_H

#include "chainon.h"

template <class T>
class ListeChainee
{
public:
// Méthodes
    void Ajouter(T* element);
    void Supprimer(int index);
    Chainon<T>* Get(int index);
// Constructeurs
    ListeChainee();
protected:
    Chainon<T>* premier;
    Chainon<T>* dernier;
    int taille{};
};

#endif
