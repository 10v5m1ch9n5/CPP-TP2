#include <iostream>
using namespace std;
#include "trajet_compose.h"
#include "Catalogue.h"
#include "CouleurTTY.h"

int main()
{
    TrajetSimple* ts = new TrajetSimple("Paris Gare de Lyon", "Lyon Part-Dieu", "TGV");
    TrajetSimple* ts2 = new TrajetSimple("Lyon Part-Dieu", "Marseille Saint-Charles", "TGV");
    TrajetSimple* ts3 = new TrajetSimple("Lyon Part-Dieu", "Gaston Berger", "Tramway");
    TrajetCompose* tc = new TrajetCompose();
    // TrajetSimple* ts4 = new TrajetSimple("Marseille", "Bordeaux", "Avion");
    tc->AjouterTrajet(ts);
    tc->AjouterTrajet(ts2);

    Catalogue catalogue;

    catalogue.AjouterTrajet(ts);
    catalogue.AjouterTrajet(ts2);
    catalogue.AjouterTrajet(ts3);
    // catalogue.AjouterTrajet(ts4);
    catalogue.AjouterTrajet(tc);
    catalogue.AfficherTrajets();

    cout << CouleurTTY(CYAN) << "RESULTATS RECHERCHE RECURSIVE" << CouleurTTY(RESET) << endl;
    catalogue.RechercheRecursive("Paris Gare de Lyon", "Gaston Berger")->ToString();

    return 0;
}