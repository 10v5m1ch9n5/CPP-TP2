//
// Created by lucas on 10/12/2020.
//
// Utile uniquement pour la recherche récursive !
//
// Le nom "Noeud" de cette classe vient de la terminologie des arbres n-aires.
// Un objet Noeud peut être la racine d'un arbre (donc ne pas avoir de parent)
// ou bien posséder un parent (maximum) et plusieurs enfants (nombre indéterminé) collectés dans une ListeChaineeGenerique<Noeud>.
//
// La méthode "DetruireCascade" possède un intérêt particuler pour l'implémentation de la recherche avancée.
// Les trajets possibles entre deux villes sont constitués en composant à chaque trajet tous les trajets possibles, et ainsi de suite
// jusqu'à ce que l'on arrive à la ville d'arrivée (cas de figure où le trajet est conservé) ou bien à une ville d'arrivée n'étant la ville
// de départ d'aucun autre trajet. Dans ce cas la méthode DetruireCascade est appelée sur le Noeud "sans issue" pour le détruire ainsi que
// tous ses noeuds parents n'ayant qu'un noeud enfant.

#ifndef C_TP2_NOEUD_H
#define C_TP2_NOEUD_H

#include "trajet.h"
#include "ListeChaineeGenerique.h"

class Noeud
{
private:
    ListeChaineeGenerique<Noeud>* enfants;
    Trajet* trajet;
    Noeud* parent;
    int indice;
    void ActualiserIndicesEnfants();
public:
    explicit Noeud(Trajet* t);
    ~Noeud();
    void AjouterEnfant(Noeud* noeud);
    void SupprimerEnfant(int index);
    int GetNbEnfants();
    Trajet* GetTrajet();
    bool EstRacine();
    void SetParent(Noeud* p);
    void SetIndice(int i);
    int GetIndice();
    void DetruireCascade(int i = 0);
    Noeud* GetEnfant(const int i);
    void Debrancher();
};


#endif //C_TP2_NOEUD_H
