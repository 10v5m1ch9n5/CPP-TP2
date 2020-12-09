#ifndef TRAJETCOMPOSE_H
#define TRAJETCOMPOSE_H

#include "trajet_simple.h"
#include "liste_chainee.h"

class TrajetCompose : public Trajet
{
private:
    ListeChainee* listeChainee;
public:
// Constructeur
    TrajetCompose();
// Destructeur
    ~TrajetCompose();
// Methodes
    const char * GetDepart() override;
    const char * GetArrive() override;
    void ToString() override;
    void AjouterTrajet(const char* villeDepart, const char* villeArrivee, const char* moyenTransport);
    void AjouterTrajet(Trajet * t);
};

#endif
