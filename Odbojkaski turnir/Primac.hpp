#ifndef PRIMAC_HPP_INCLUDED
#define PRIMAC_HPP_INCLUDED
#include "IGRAC.HPP"
class Primac:public Igrac
{
protected:
    int brojPrijema;
    int PoenSmec;
public:
    Primac(int brP=0, int PS, string i, string p, int g):Igrac(i, p, g){
        brojPrijema=brPrijem;
        PoenSmec=PSmec;
    }
};

#endif // PRIMAC_HPP_INCLUDED
