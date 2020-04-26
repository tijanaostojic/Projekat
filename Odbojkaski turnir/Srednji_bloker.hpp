#ifndef SREDNJI_BLOKER_HPP_INCLUDED
#define SREDNJI_BLOKER_HPP_INCLUDED
#include "IGRAC.HPP"
class SrednjiBloker:public Igrac
{
protected:
    int Blokovi;
    int poenSmec;
public:
    SrednjiBloker(int B=0, int PS=0, string i, string p, int g):Igrac(i, p, g){
        Blokovi=B;
        poenSmec=PSmec;
    }
};










#endif // SREDNJI_BLOKER_HPP_INCLUDED
