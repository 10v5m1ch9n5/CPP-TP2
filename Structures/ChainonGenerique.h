//
// Created by lucas on 10/12/2020.
//

#ifndef C_TP2_CHAINONGENERIQUE_H
#define C_TP2_CHAINONGENERIQUE_H

template<typename T>
class ChainonGenerique
{
private:
    T* element;
    ChainonGenerique<T>* suivant;
};


#endif //C_TP2_CHAINONGENERIQUE_H
