#ifndef KOREKTOR_HPP_INCLUDED
#define KOREKTOR_HPP_INCLUDED
#include "IGRAC.HPP"
class Korektor:public Igrac
{
protected:
    int PoenSmec;
    int PoenServis;
public:
    Korektor(int PSmec=0, int PServis=0, string i, string p, int g):Igrac(i, p, g){
        PoenSmec=PSmec;
        PoenServis=PServis;
    }
};

#endif // KOREKTOR_HPP_INCLUDED
