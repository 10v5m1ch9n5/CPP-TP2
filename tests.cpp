#include <iostream>
using namespace std;
#include "liste_chainee.h"
#include "trajet.h"

int main()
{
    TrajetSimple* ts = new TrajetSimple("Paris Gare de Lyon", "Lyon Part-Dieu", "TGV");
    TrajetSimple* ts2 = new TrajetSimple("Lyon Part-Dieu", "Marseille Saint-Charles", "TGV");
    TrajetSimple* ts3 = new TrajetSimple("Lyon Part-Dieu", "Gaston Berger", "Tramway");


    ListeChainee<Trajet>* lc = new ListeChainee<Trajet>();
    lc->Ajouter(ts);
    lc->Ajouter(ts2);
    lc->Ajouter(ts3);
    return 0;
}