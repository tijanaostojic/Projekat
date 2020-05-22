#ifndef TEHNICAR_HPP_INCLUDED
#define TEHNICAR_HPP_INCLUDED
#include "SREDNJI_BLOKER.hpp"
enum dizanje{lose, dobro};
class Tehnicar:public Igrac
{
protected:
    dizanje Dizanje;
    int PoenKuvanje;
    //int brojDizanja; dal ovo pisati
public:
    Tehnicar(string i, string p, int g, dizanje D=lose, int PKuvanje=0, int dobroD=0, int loseD=0):Igrac(i, p ,g){
        Dizanje=D;
        PoenKuvanje=PKuvanje;
    }

    string getIme()const {return ime;}
    string getPrezime()const {return prezime;}

    Tehnicar(const Tehnicar &a):Igrac(a.ime, a.prezime, a.godine), Dizanje(a.Dizanje), PoenKuvanje(a.PoenKuvanje){}

    void dizanje(SrednjiBloker &sb){
        PoenKuvanje++;
        korisnost++;
        sb.setzastitaTehnicar(1);
        cout << "Srednji bloker: -1" << endl << "Tehnicar: +1";
    }

    void setDizanje(int brojZastitaodLibera){
        Dizanje=lose;
        korisnost=0;
    }
    void predstaviSe(){
        Igrac::predstaviSe();
        cout<<" - tehnicar."<<endl;
    }

    int identifikacija(){return 5;}
};

#endif // TEHNICAR_HPP_INCLUDED
