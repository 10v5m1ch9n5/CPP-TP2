#include <iostream>
using namespace std;
#include "trajet_compose.h"
#include "Catalogue.h"
#include "CouleurTTY.h"

int main()
{
    Catalogue catalogue;
    TrajetSimple* ts3 = new TrajetSimple("Marseille", "Bordeaux", "Bateau");
    TrajetSimple* ts2 = new TrajetSimple("Lyon", "Marseille", "TGV");
    TrajetSimple* ts1 = new TrajetSimple("Paris", "Lyon", "TGV");
    TrajetCompose* tc1 = new TrajetCompose();
    tc1->AjouterTrajet(ts1);
    tc1->AjouterTrajet(ts2);
    TrajetCompose* tc2 = new TrajetCompose();
    tc2->AjouterTrajet(tc1);
    tc2->AjouterTrajet(ts3);
    catalogue.AjouterTrajet(ts1);
    catalogue.AjouterTrajet(ts2);
    catalogue.AjouterTrajet(ts3);
    catalogue.AjouterTrajet(tc1);
    catalogue.AjouterTrajet(tc2);
    catalogue.AfficherTrajets();
    catalogue.Sauvegarder();
}
