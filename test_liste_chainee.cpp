//
// Created by lucas on 11/12/2020.
//

#include "ListeChaineeGenerique.h"
#include "Noeud.h"
#include "trajet_compose.h"

int main()
{
    TrajetSimple* t1 = new TrajetSimple("Paris", "Lyon", "TGV");
    TrajetSimple* t2 = new TrajetSimple("Lyon", "Marseille", "TGV");
    TrajetCompose* t3 = new TrajetCompose();
    t3->AjouterTrajet(t1);
    t3->AjouterTrajet(t2);

    Noeud* n1 = new Noeud(t1);
    Noeud* n2 = new Noeud(t2);
    Noeud* n3 = new Noeud(t3);

    ListeChaineeGenerique<Noeud>* liste = new ListeChaineeGenerique<Noeud>();
    liste->Ajouter(n1);
    liste->Ajouter(n2);
    liste->Ajouter(n3);

    for (int i = 0; i < liste->GetTaille(); i++)
    {
        liste->Get(i)->GetTrajet()->ToString();
    }
}
