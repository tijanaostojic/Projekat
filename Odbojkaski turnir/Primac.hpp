#ifndef PRIMAC_HPP_INCLUDED
#define PRIMAC_HPP_INCLUDED
#include "IGRAC.HPP"
class Primac:public Igrac
{
protected:
    int brojPrijema;
    int PoenSmec;
public:
    Primac(string i, string p, int g, int PS, int brP=0):Igrac(i, p, g){
        brojPrijema=brP;
        PoenSmec=PS;
    }
    Primac(Primac const &a):Igrac(a.ime, a.prezime, a.godine){}
};

#endif // PRIMAC_HPP_INCLUDED
