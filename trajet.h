#ifndef TRAJET_H
#define TRAJET_H
class Trajet
{
public:
    virtual void ToString() {} ;
    virtual const char* GetDepart() {return nullptr;};
    virtual const char* GetArrive() {return nullptr;};
    virtual ~Trajet() = default;
    inline void NouvelleReference(){nbFoisPointe++;};
    inline int GetNbReferences() const{return nbFoisPointe;};
    inline void EnleverReference(){nbFoisPointe--;};
    // inline Trajet(){nbFoisPointe=0;};
protected:
    int nbFoisPointe;
};

#endif