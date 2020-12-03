#include <iostream>
using namespace std;
#include "liste_chainee.h"

int main()
{
    TrajetSimple* ts = new TrajetSimple("Paris Gare de Lyon", "Lyon Part-Dieu", "TGV");
    TrajetSimple* ts2 = new TrajetSimple("Lyon Part-Dieu", "Marseille Saint-Charles", "TGV");
    TrajetSimple* ts3 = new TrajetSimple("Lyon Part-Dieu", "Gaston Berger", "Tramway");

    Trajet* catalogue[10];

    Trajet* trajetptr = ts;
    catalogue[0] = trajetptr;
    catalogue[0]->ToString();
    return 0;
}