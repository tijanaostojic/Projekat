#ifndef TEHNICAR_HPP_INCLUDED
#define TEHNICAR_HPP_INCLUDED
#include "IGRAC.HPP"
class Tehnicar:public Igrac
{
protected:
    int Dizanje;
    int PoenKuvanje;
public:
    Tehnicar(int D=0, int PKuvanje=0, string i, string p, int g):Igrac(i, p ,g){
        Dizanje=D;
        PoenKuvanje=PKuvanje;
    }
};

#endif // TEHNICAR_HPP_INCLUDED
