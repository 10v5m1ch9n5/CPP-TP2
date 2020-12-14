// Cette classe est parent des classes TrajetSimple et TrajetCompose.
// Aucun objet Trajet n'est créé dans toute l'application.
// - Méthode ToString : Affiche des informations sur le trajet

#ifndef TRAJET_H
#define TRAJET_H

class Trajet
{
public:
    virtual void ToString() {} ;
    virtual const char* GetDepart() {return nullptr;};
    virtual const char* GetArrive() {return nullptr;};
    virtual ~Trajet() = default;
// Permet de gérer la destruction (cf. conclusion du rapport)
    inline Trajet(int nbFoisPointe) { this->nbFoisPointe = nbFoisPointe; };
    inline void NouvelleReference(){nbFoisPointe++;};
    inline int GetNbReferences() const{return nbFoisPointe;};
    inline void EnleverReference(){nbFoisPointe--;};
protected:
    int nbFoisPointe;
};

#endif