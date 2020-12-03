#include "chainon.h"
#include <iostream>
using namespace std;

// Constructeurs
template<class T>
Chainon<T>::Chainon(T* element, Chainon<T>* suivant)
{
    this->suivant = suivant;
    this->element = element;
}

// Get Set
template<class T>
void Chainon<T>::SetSuivant(Chainon<T> *c) {
    this->suivant = c;
}

template<class T>
void Chainon<T>::SetElement(T *element)
{
    this->element = element;
}

template<class T>
Chainon<T>* Chainon<T>::GetSuivant() {
    return this->suivant;
}

template<class T>
T* Chainon<T>::GetElement() {
    return this->element;
}

// Méthodes
template<class T>
void Chainon<T>::ToString() {
    cout << "Chainon : ";
    if(this->element == nullptr)
    {
        cout << "vide" << endl;
        return;
    }
    cout << endl;
    this->element->ToString();
    if(this->suivant == nullptr)
    {
        cout << "chainon suivant inexistant" << endl;
        return;
    }
    cout << "chainon suivant défini" << endl;
}

template class Chainon<Trajet>;
template class Chainon<TrajetSimple>;
// template class Chainon<TrajetCompose>;