#include <iostream>
using namespace std;
#include "trajet_compose.h"

int main()
{
    TrajetSimple* ts = new TrajetSimple("Paris Gare de Lyon", "Lyon Part-Dieu", "TGV");
    TrajetSimple* ts2 = new TrajetSimple("Lyon Part-Dieu", "Marseille Saint-Charles", "TGV");
    TrajetSimple* ts3 = new TrajetSimple("Lyon Part-Dieu", "Gaston Berger", "Tramway");

    cout << ts->GetDepart() << endl;

    return 0;
}