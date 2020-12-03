#include <iostream>
using namespace std;
#include "trajet_compose.h"

int main()
{
    TrajetSimple* ts = new TrajetSimple("Paris Gare de Lyon", "Lyon Part-Dieu", "TGV");
    TrajetSimple* ts2 = new TrajetSimple("Lyon Part-Dieu", "Marseille Saint-Charles", "TGV");
    TrajetSimple* ts3 = new TrajetSimple("Lyon Part-Dieu", "Gaston Berger", "Tramway");


    TrajetCompose tc;
    tc.AjouterTrajet(ts2);
    tc.AjouterTrajet(ts3);
    tc.ToString();

    return 0;
}