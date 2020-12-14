// Classe représentant les trajets composés
// - La méthode AjouterTrajetSimple publique permet d'ajouter un trajet simple dans le trajet composé sans que celui-ci existe préalablement dans le catalogue.
// - La méthode AjouterTrajet permet d'ajouter un trajet déjà existant au catalogue. Elle appelle une des deux méthodes privées AjouterTrajetSimple ou AjouterTrajetCompose
// - La méthode AjoutPossble vérifie que la ville de départ du trajet à ajouter est bien la ville d'arrivée du dernier trajet ajouté au trajet composé en train d'être constitué.


#ifndef TRAJETCOMPOSE_H
#define TRAJETCOMPOSE_H

#include "trajet_simple.h"
#include "liste_chainee.h"

class TrajetCompose : public Trajet
{
private:
    ListeChainee* listeChainee;
    bool AjoutPossible(Trajet* t);
    void AjouterTrajetSimple(TrajetSimple* ts);
    void AjouterTrajetCompose(TrajetCompose* tc);
public:
// Constructeur
    TrajetCompose();
// Destructeur
    ~TrajetCompose();
// Methodes
    const char * GetDepart() override;
    const char * GetArrive() override;
    void ToString() override;
    void AjouterTrajetSimple(const char* villeDepart, const char* villeArrivee, const char* moyenTransport);
    void AjouterTrajet(Trajet* t);
};

#endif
