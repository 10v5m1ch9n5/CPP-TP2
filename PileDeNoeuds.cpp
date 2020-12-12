//
// Created by lucas on 12/12/2020.
//

#include "PileDeNoeuds.h"
#include "CouleurTTY.h"
#include <iostream>

PileDeNoeuds::PileDeNoeuds()
{
#ifdef MAP
    cout << CouleurTTY(JAUNE) << "Appel au constructeur de PileDeNoeuds" << CouleurTTY(RESET) << endl;
#endif
    base = nullptr;
    sommet = nullptr;
}

PileDeNoeuds::~PileDeNoeuds()
{
#ifdef MAP
    cout << CouleurTTY(JAUNE) << "Appel au destructeur de PileDeNoeuds" << CouleurTTY(RESET) << endl;
#endif
}

void PileDeNoeuds::Empiler(Noeud *n)
{

}