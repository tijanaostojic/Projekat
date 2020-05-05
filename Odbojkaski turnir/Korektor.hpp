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
    Korektor(string i, string p,int g, int PSmec=0, int PServis=0, int Blok=0):Igrac(i, p, g){
        PoenSmec=PSmec;
        PoenServis=PServis;
        Blokiran=Blok;
    }
    Korektor(Korektor const &a):Igrac(a.ime, a.prezime, a.godine){}

    void setBlokiran(int brojBlokiran){
        Blokiran+=brojBlokiran;
    }
};

#endif // KOREKTOR_HPP_INCLUDED
