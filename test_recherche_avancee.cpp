//
// Created by lucas on 16/12/2020.
//
#include <iostream>
using namespace std;
#include "trajet_compose.h"
#include "Catalogue.h"
#include "CouleurTTY.h"

int main()
{
    TrajetSimple* ts5 = new TrajetSimple("Robinson RER", "Chatelet Les Halles", "RER B");
    TrajetSimple* ts6 = new TrajetSimple("Chatelet Les Halles", "Gare de Lyon", "RER A");
    TrajetSimple* ts7 = new TrajetSimple("Chatelet Les Halles", "Gare de Lyon", "Metro 14");
    TrajetSimple* ts = new TrajetSimple("Gare de Lyon", "Lyon Part-Dieu", "TGV");
    TrajetSimple* ts9 = new TrajetSimple("Paris CDG", "Tokyo NRT", "Avion");
    TrajetSimple* ts2 = new TrajetSimple("Lyon Part-Dieu", "Marseille Saint-Charles", "TGV");
    TrajetSimple* ts3 = new TrajetSimple("Lyon Part-Dieu", "Gaston Berger", "Tramway");
    // TrajetSimple* ts8 = new TrajetSimple("Gare de Lyon", "Marseille Saint-Charles", "TGV");
    TrajetSimple* ts10 = new TrajetSimple("Tokyo NRT", "Nippori", "Skyliner");
    TrajetSimple* ts11 = new TrajetSimple("Tokyo NRT", "Tokyo", "Narita Express");
    TrajetSimple* ts12 = new TrajetSimple("Nippori", "Ueno", "JR Yamanote");
    TrajetSimple* ts13 = new TrajetSimple("Ueno", "Akihabara", "JR Yamanote");
    TrajetSimple* ts14 = new TrajetSimple("Ueno", "Honjo", "JR Takasaki");

    TrajetCompose* tc = new TrajetCompose();
    tc->AjouterTrajetSimple("Gare de Lyon", "Lyon Part-Dieu", "TGV");
    tc->AjouterTrajetSimple("Lyon Part-Dieu", "La Doua Gaston Berger", "Tramway T4");

    TrajetCompose* tc2 = new TrajetCompose();
    tc2->AjouterTrajet(ts5);
    tc2->AjouterTrajetSimple("Chatelet Les Halles", "Paris CDG", "RER B");

    Catalogue catalogue;

    catalogue.AjouterTrajet(ts);
    catalogue.AjouterTrajet(ts2);
    catalogue.AjouterTrajet(ts3);
    catalogue.AjouterTrajet(ts5);
    catalogue.AjouterTrajet(ts6);
    catalogue.AjouterTrajet(ts7);
    // catalogue.AjouterTrajet(ts8);
    catalogue.AjouterTrajet(ts9);
    catalogue.AjouterTrajet(tc);
    catalogue.AjouterTrajet(tc2);
    catalogue.AjouterTrajet(ts10);
    catalogue.AjouterTrajet(ts11);
    catalogue.AjouterTrajet(ts12);
    catalogue.AjouterTrajet(ts13);
    catalogue.AjouterTrajet(ts14);
    catalogue.AfficherTrajets();

    cout << CouleurTTY(ROUGE) << "RESULTATS RECHERCHE RECURSIVE" << CouleurTTY(RESET) << endl;
    catalogue.RechercheAvancee("Robinson RER", "Akihabara");
    cout << CouleurTTY(ROUGE) << "RESULTATS RECHERCHE RECURSIVE" << CouleurTTY(RESET) << endl;
    catalogue.RechercheAvancee("Robinson RER", "Marseille Saint-Charles");
    cout << CouleurTTY(ROUGE) << "RESULTATS RECHERCHE RECURSIVE" << CouleurTTY(RESET) << endl;
    catalogue.RechercheAvancee("Chatelet Les Halles", "Marseille Saint-Charles");

    return 0;
}
