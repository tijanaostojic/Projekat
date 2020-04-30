#ifndef TEHNICAR_HPP_INCLUDED
#define TEHNICAR_HPP_INCLUDED
#include "IGRAC.HPP"
class Tehnicar:public Igrac
{
protected:
    dizanje Dizanje;
    int PoenKuvanje;
public:
    Tehnicar(dizanje D=lose, int PKuvanje=0, string i, string p, int g, int dobroD=0, int loseD=0):Igrac(i, p ,g){
        Dizanje=D;
        PoenKuvanje=PKuvanje;
    }
    void Kuvaj(Srednji_Bloker sb){
        sb.setzastitaTehnicar(1);
        PoenKuvanje++;
        cout << "Srednji bloker: -1" << endl << "Tehnicar: +1";
    }

};

#endif // TEHNICAR_HPP_INCLUDED
