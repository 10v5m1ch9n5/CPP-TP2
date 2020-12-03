#ifndef TRAJETSIMPLE_H
#define TRAJETSIMPLE_H

#include "trajet_simple.h"
template <class T>
class Chainon
{
public:
    // Get Set
    void SetSuivant(Chainon<T>* c);
    void SetElement(T* element);
    Chainon* GetSuivant();
    T* GetElement();
    // Méthodes
    void ToString();
    // Constructeurs
    Chainon(T* element, Chainon* suivant);
private:
    T* element;
    Chainon* suivant;
};

#endif
