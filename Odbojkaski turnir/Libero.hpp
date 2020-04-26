#ifndef LIBERO_HPP_INCLUDED
#define LIBERO_HPP_INCLUDED
#include "IGRAC.HPP"
class Libero:public Igrac
{
protected:
    int Prijem;
    int Odbrana;
    int Zastita;
public:
    Libero(int pr=0, int o=0, int z=0, string i, string p, int g):Igrac(i, p, g){
        Prijem=pr;
        Odbrana=o;
        Zastita=z;
    }
};

#endif // LIBERO_HPP_INCLUDED
