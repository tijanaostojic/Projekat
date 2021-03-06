#ifndef PRIMAC_HPP_INCLUDED
#define PRIMAC_HPP_INCLUDED
#include "IGRAC.HPP"
#include "LIBERO.HPP"
class Primac:public Igrac
{
protected:
    int brojPrijema;
    int PoenSmec;
public:
    Primac(){}
    Primac(string i, string p, int g, int PS=0, int brP=0):Igrac(i, p, g){
        brojPrijema=brP;
        PoenSmec=PS;
    }

    string getIme()const {return ime;}
    string getPrezime()const {return prezime;}
    int getKorisnost()const{return korisnost;}
    void setKorisnost(int korisnostt){
        korisnost=korisnostt;
    }
    Primac(const Primac &a):Igrac(a.ime, a.prezime, a.godine), brojPrijema(a.brojPrijema), PoenSmec(a.PoenSmec){}

    void PoentirajSmecp(){
        PoenSmec++;
        korisnost++;
        cout<<"Primac korisnost: +1"<<endl;
    }

    void predstaviSe(){
        Igrac::predstaviSe();
        cout<<" - primac."<<endl;
    }

    int identifikacija(){return 3;}
};

#endif // PRIMAC_HPP_INCLUDED
