#ifndef SREDNJI_BLOKER_HPP_INCLUDED
#define SREDNJI_BLOKER_HPP_INCLUDED
#include "IGRAC.HPP"
#include "KOREKTOR.HPP"
class SrednjiBloker:public Igrac
{
protected:
    int Blokovi;
    int poenSmec;
    int zastitaTehnicar;
public:
    SrednjiBloker(){}
    SrednjiBloker(string i, string p, int g, int B=0, int PS=0):Igrac(i, p, g){
        Blokovi=B;
        poenSmec=PS;
    }

    string getIme()const {return ime;}
    string getPrezime()const{return prezime;}
    int getKorisnost()const{return korisnost;}
    void setKorisnost(int korisnostt){
        korisnost=korisnostt;
    }
    SrednjiBloker(const SrednjiBloker &a):Igrac(a.ime, a.prezime, a.godine), Blokovi(a.Blokovi), poenSmec(a.poenSmec), zastitaTehnicar(a.zastitaTehnicar){}

    void Blokiraj(){
        Blokovi++;
        korisnost++;
        cout<< "Srednji bloker korisnost: +1" << endl;
    }

    void predstaviSe(){
        Igrac::predstaviSe();
        cout<<" - srednjak."<<endl;
    }

    int identifikacija(){return 4;}
};










#endif // SREDNJI_BLOKER_HPP_INCLUDED
