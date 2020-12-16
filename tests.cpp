#include <iostream>
using namespace std;
#include "trajet_compose.h"
#include "Catalogue.h"
#include "CouleurTTY.h"

int main()
{
    Catalogue catalogue;
    catalogue.Charger();
    catalogue.AfficherTrajets();
}
