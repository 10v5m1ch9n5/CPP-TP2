//
// Created by lucas on 12/12/2020.
//

#ifndef C_TP2_PILEDENOEUDS_H
#define C_TP2_PILEDENOEUDS_H

#include "Noeud.h"

class PileDeNoeuds
{
private:
    Noeud* base;
    Noeud* sommet;
public:
    PileDeNoeuds();
    ~PileDeNoeuds();
    void Empiler(Noeud* n);
    Noeud* Depiler();
};


#endif //C_TP2_PILEDENOEUDS_H
