#ifndef TRAJET_H
#define TRAJET_H
class Trajet
{
public:
    virtual void ToString() {} ;
    virtual const char* GetDepart() {return nullptr;};
    virtual const char* GetArrive() {return nullptr;};
    virtual ~Trajet() = default;
// Permet de gérer la destruction
    inline void NouvelleReference(){nbFoisPointe++;};
    inline int GetNbReferences() const{return nbFoisPointe;};
    inline void EnleverReference(){nbFoisPointe--;};
protected:
    int nbFoisPointe;
};

#endif