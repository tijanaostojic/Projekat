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
    Tehnicar(){}
    Tehnicar(string i, string p, int g, dizanje D=lose, int PKuvanje=0, int dobroD=0, int loseD=0):Igrac(i, p ,g){
        Dizanje=D;
        PoenKuvanje=PKuvanje;
    }

    string getIme()const {return ime;}
    string getPrezime()const {return prezime;}
    int getKorisnost()const{return korisnost;}
    void setKorisnost(int korisnostt){
        korisnost=korisnostt;
    }
    Tehnicar(const Tehnicar &a):Igrac(a.ime, a.prezime, a.godine), Dizanje(a.Dizanje), PoenKuvanje(a.PoenKuvanje){}

    void dizanje(){
        PoenKuvanje++;
        korisnost++;
        cout << "Tehnicar korisnost: +1"<<endl;
    }
    void predstaviSe(){
        Igrac::predstaviSe();
        cout<<" - tehnicar."<<endl;
    }

    int identifikacija(){return 5;}
};

#endif // TEHNICAR_HPP_INCLUDED
