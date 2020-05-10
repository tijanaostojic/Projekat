#ifndef TIM_HPP_INCLUDED
#define TIM_HPP_INCLUDED
#include "KOREKTOR.HPP"
#include "LIBERO.HPP"
#include "PRIMAC.HPP"
#include "SREDNJI_BLOKER.HPP"
#include "TEHNICAR.HPP"
class Tim
{
protected:
    string Ime;
    int brojEkipa;
    int brojIgraca;
    string imeTrenera;
    string prezimeTrenera;
    Igrac igraci[7];
    Korektor korektor;
    Libero libero;
    Primac primac;
    SrednjiBloker srednjak;
    Tehnicar tehnicar;
public:
    Tim(string i, int brE, int brI, string imeT, string prezimeT, Primac p, Korektor k, Libero l, Tehnicar t, SrednjiBloker s):primac(p), korektor(k), libero(l), tehnicar(t), srednjak(s){
        Ime=i;
        brojEkipa=brE;
        brojIgraca=brI;
        imeTrenera=imeT;
        prezimeTrenera=prezimeT;
    }
    Tim(Tim const &a);
};

#endif // TIM_HPP_INCLUDED
