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
    TrajetSimple* ts5 = new TrajetSimple("Robinson RER", "Chatelet Les Halles", "RER B");
    TrajetSimple* ts6 = new TrajetSimple("Chatelet Les Halles", "Paris Gare de Lyon", "RER A");
    TrajetSimple* ts7 = new TrajetSimple("Chatelet Les Halles", "Paris Gare de Lyon", "Metro 14");
    TrajetSimple* ts8 = new TrajetSimple("Paris Gare de Lyon", "Marseille Saint-Charles", "TGV");

    Catalogue catalogue;

    catalogue.AjouterTrajet(ts);
    catalogue.AjouterTrajet(ts2);
    catalogue.AjouterTrajet(ts3);
    catalogue.AjouterTrajet(ts5);
    catalogue.AjouterTrajet(ts6);
    catalogue.AjouterTrajet(ts7);
    catalogue.AjouterTrajet(ts8);
    catalogue.AfficherTrajets();

    cout << CouleurTTY(CYAN) << "RESULTATS RECHERCHE RECURSIVE" << CouleurTTY(RESET) << endl;
    catalogue.RechercheAvancee("Robinson RER", "Marseille Saint-Charles");

    return 0;
}