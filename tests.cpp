#include <iostream>
using namespace std;
#include "trajet_compose.h"
#include "Catalogue.h"

int main()
{
    TrajetSimple* ts = new TrajetSimple("Paris Gare de Lyon", "Lyon Part-Dieu", "TGV");
    TrajetSimple* ts2 = new TrajetSimple("Lyon Part-Dieu", "Marseille Saint-Charles", "TGV");
    TrajetSimple* ts3 = new TrajetSimple("Lyon Part-Dieu", "Gaston Berger", "Tramway");
    TrajetCompose* ts4 = new TrajetCompose();
    ts4->AjouterTrajet(ts);
    ts4->AjouterTrajet(ts2);

    Catalogue catalogue;

    catalogue.AjouterTrajet(ts3);
    catalogue.AjouterTrajet(ts4);
    catalogue.AfficherTrajets();

    delete ts;
    delete ts2;
    delete ts3;
    delete ts4;
    return 0;
}