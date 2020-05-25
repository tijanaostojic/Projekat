#ifndef KOREKTOR_HPP_INCLUDED
#define KOREKTOR_HPP_INCLUDED
#include "IGRAC.HPP"
#include "PRIMAC.HPP"
class Korektor:public Igrac
{
protected:
    int PoenSmec;
    int PoenServis;
    int Blokiran;
public:
    Korektor(){}
    Korektor(string i, string p,int g, int PSmec=0, int PServis=0, int Blok=0):Igrac(i, p, g){
        PoenSmec=PSmec;
        PoenServis=PServis;
        Blokiran=Blok;
    }
    Korektor(const Korektor &a):Igrac(a.ime, a.prezime, a.godine), PoenSmec(a.PoenSmec), PoenServis(a.PoenServis), Blokiran(a.Blokiran){}

    string getIme()const{return ime;}
    string getPrezime()const {return prezime;}
    int getKorisnost()const{return korisnost;}
    void setKorisnost(int korisnostt){
        korisnost=korisnostt;
    }
    void PoentirajSmeck(){
        PoenSmec++;
        korisnost++;
        cout<<"Korektor korisnost: +1"<<endl;
    }



    void predstaviSe(){
        Igrac::predstaviSe();
        cout<<" - korektor."<<endl;
    }

    int identifikacija(){return 1;}
};

#endif // KOREKTOR_HPP_INCLUDED
