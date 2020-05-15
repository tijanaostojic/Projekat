#ifndef KOREKTOR_HPP_INCLUDED
#define KOREKTOR_HPP_INCLUDED
#include "IGRAC.HPP"
class Korektor:public Igrac
{
protected:
    int PoenSmec;
    int PoenServis;
    int Blokiran;
public:
    Korektor(string i, string p,int g, int PSmec=0, int PServis=0, int Blok=0):Igrac(i, p, g){
        PoenSmec=PSmec;
        PoenServis=PServis;
        Blokiran=Blok;
    }
    Korektor(Korektor const &a):Igrac(a.ime, a.prezime, a.godine), PoenSmec(a.PoenSmec), PoenServis(a.PoenServis), Blokiran(a.Blokiran){}

    string getIme()const {return ime;}
    string getPrezime()const {return prezime;}

    void setBlokiran(int brojBlokiran){
        Blokiran+=brojBlokiran;
    }

    void predstaviSe(){
        Igrac::predstaviSe();
        cout<<"Igram na poziciji korektora."<<endl;
    }

    int identifikacija(){return 1;}
};

#endif // KOREKTOR_HPP_INCLUDED
