#ifndef TRAJET_H
#define TRAJET_H
class Trajet
{
    public:
    virtual void ToString() {} ;
    virtual const char* GetDepart() {};
    virtual const char* GetArrive() {};
    virtual ~Trajet() = default;
};

#endif