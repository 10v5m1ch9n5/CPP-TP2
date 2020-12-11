//
// Created by lucas on 10/12/2020.
//

#include "ChainonGenerique.h"
#include "CouleurTTY.h"
#include "Noeud.h"
#include <ostream>

template<typename T>
ChainonGenerique<T>::ChainonGenerique(T *element, ChainonGenerique<T> *suivant)
{
#ifdef MAP
    cout << CouleurTTY(JAUNE) << "Appel au constructeur de ChainonGenerique" << CouleurTTY(RESET) << endl;
#endif
    this->element = element;
    this->suivant = suivant;
}

template<typename T>
ChainonGenerique<T>::~ChainonGenerique<T>()
{
#ifdef MAP
    cout << CouleurTTY(JAUNE) << "Appel au destructeur de ChainonGenerique" << CouleurTTY(RESET) << endl;
#endif
}

template<typename T>
inline ChainonGenerique<T> * ChainonGenerique<T>::GetSuivant()
{
    return suivant;
}

template<typename T>
inline T * ChainonGenerique<T>::GetElement()
{
    return element;
}

template<typename T>
inline void ChainonGenerique<T>::SetSuivant(ChainonGenerique<T> *suivant)
{
    this->suivant = suivant;
}

template<typename T>
inline void ChainonGenerique<T>::SetElement(T *element)
{
    this->element = element;
}

template class ChainonGenerique<Noeud>;
