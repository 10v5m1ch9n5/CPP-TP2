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
