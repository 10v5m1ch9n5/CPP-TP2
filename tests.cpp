#include <iostream>
using namespace std;
#include "liste_chainee.h"
#include "trajet_simple.h"

int main()
{
    TrajetSimple* ts = new TrajetSimple("Paris Gare de Lyon", "Lyon Part-Dieu", "TGV");
    //TrajetSimple* ts2 = new TrajetSimple("Lyon Part-Dieu", "Marseille Saint-Charles", "TGV");
    //TrajetSimple* ts3 = new TrajetSimple("Lyon Part-Dieu", "Gaston Berger", "Tramway");

    cout << ts->GetDepart() << endl;
    cout << ts->GetArrive() << endl;
    return 0;
}