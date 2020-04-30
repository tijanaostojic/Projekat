#ifndef KOREKTOR_HPP_INCLUDED
#define KOREKTOR_HPP_INCLUDED
#include "IGRAC.HPP"
class Korektor:public Igrac
{
protected:
    int PoenSmec;
    int PoenServis;
    int Blokiran;
public:
    Korektor(int PSmec=0, int PServis=0, string i, string p, int g, int Blok=0):Igrac(i, p, g){
        PoenSmec=PSmec;
        PoenServis=PServis;
        Blokiran=Blok;
    }
    void setBlokiran(int brojBlokiran){
        Blokiran+=brojBlokiran;
    }
};

#endif // KOREKTOR_HPP_INCLUDED
