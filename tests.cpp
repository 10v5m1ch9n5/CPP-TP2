#include <iostream>
using namespace std;
#include "liste_chainee.h"

int main()
{
    char* ville = new char[25];
    cin.getline(ville, 25);
    cout << ville << endl;

    TrajetSimple* ts = new TrajetSimple("Paris Gare de Lyon", "Lyon Part-Dieu", "TGV");
    TrajetSimple* ts2 = new TrajetSimple("Lyon Part-Dieu", "Marseille Saint-Charles", "TGV");
    TrajetSimple* ts3 = new TrajetSimple("Lyon Part-Dieu", "Gaston Berger", "Tramway");

    ListeChainee liste;
    liste.Ajouter(ts);
    liste.Ajouter(ts2);
    liste.Ajouter(ts3);
    liste.Get(2)->ToString();
    return 0;
}