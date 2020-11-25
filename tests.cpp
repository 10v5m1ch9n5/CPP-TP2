#include <iostream>
#include "liste_chainee.h"

int main()
{
    TrajetSimple* ts = new TrajetSimple("Paris Gare de Lyon", "Lyon Part-Dieu", "TGV");
    TrajetSimple* ts2 = new TrajetSimple("Lyon Part-Dieu", "Marseille Saint-Charles", "TGV");
    TrajetSimple* ts3 = new TrajetSimple("Lyon Part-Dieu", "Gaston Berger", "Tramway");

    ListeChainee liste;
    liste.Ajouter(ts);
    liste.Ajouter(ts2);
    liste.Ajouter(ts3);
    //liste.ToString();
    //liste.Supprimer(1);
    //liste.ToString();
    return 0;
}