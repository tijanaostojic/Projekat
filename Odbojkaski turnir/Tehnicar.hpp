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

    string getIme()const {return ime;}
    string getPrezime()const {return prezime;}

    Tehnicar(Tehnicar const &a):Igrac(a.ime, a.prezime, a.godine), Dizanje(a.Dizanje), PoenKuvanje(a.PoenKuvanje){}

    void Kuvaj(SrednjiBloker &sb){
        sb.setzastitaTehnicar(1);
        PoenKuvanje++;
        cout << "Srednji bloker: -1" << endl << "Tehnicar: +1";
    }

    void predstaviSe(){
        Igrac::predstaviSe();
        cout<<"Igram na poziciji tehnicara."<<endl;
    }

    int identifikacija(){return 5;}
};

#endif // TEHNICAR_HPP_INCLUDED
