#ifndef SREDNJI_BLOKER_HPP_INCLUDED
#define SREDNJI_BLOKER_HPP_INCLUDED
#include "KOREKTOR.HPP"
class SrednjiBloker:public Igrac
{
protected:
    int Blokovi;
    int poenSmec;
    int zastitaTehnicar;
public:
    SrednjiBloker(string i, string p, int g, int B=0, int PS=0):Igrac(i, p, g){
        Blokovi=B;
        poenSmec=PS;
    }

    SrednjiBloker(SrednjiBloker const &a):Igrac(a.ime, a.prezime, a.godine){}

    void Blokiraj(Korektor &k){
        Blokovi++;
        k.setBlokiran(1);
        cout<< "Korektor: -1" << endl << "Srednji bloker +1" << endl;
    }
    void setzastitaTehnicar(int kuvanje){
        zastitaTehnicar-=kuvanje;
    }
};










#endif // SREDNJI_BLOKER_HPP_INCLUDED
