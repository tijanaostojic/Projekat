#ifndef TEHNICAR_HPP_INCLUDED
#define TEHNICAR_HPP_INCLUDED
#include "SREDNJI_BLOKER.hpp"
enum dizanje{lose, dobro};
class Tehnicar:public Igrac
{
protected:
    dizanje Dizanje;
    int PoenKuvanje;
public:
    Tehnicar(string i, string p, int g, dizanje D=lose, int PKuvanje=0, int dobroD=0, int loseD=0):Igrac(i, p ,g){
        Dizanje=D;
        PoenKuvanje=PKuvanje;
    }

    Tehnicar(Tehnicar const &a):Igrac(a.ime, a.prezime, a.godine){}

    void Kuvaj(SrednjiBloker &sb){
        sb.setzastitaTehnicar(1);
        PoenKuvanje++;
        cout << "Srednji bloker: -1" << endl << "Tehnicar: +1";
    }

};

#endif // TEHNICAR_HPP_INCLUDED
