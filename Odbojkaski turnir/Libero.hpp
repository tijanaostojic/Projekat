#ifndef LIBERO_HPP_INCLUDED
#define LIBERO_HPP_INCLUDED
#include "IGRAC.HPP"
#include "TEHNICAR.HPP"
class Libero:public Igrac
{
protected:
    int Prijem;
    int Odbrana;
    int Zastita;
public:
    Libero(string i, string p, int g, int pr=0, int o=0, int z=0):Igrac(i, p, g){
        Prijem=pr;
        Odbrana=o;
        Zastita=z;
    }

    string getIme()const {return ime;}
    string getPrezime()const {return prezime;}

    Libero(Libero const &a):Igrac(a.ime, a.prezime, a.godine),Prijem(a.Prijem), Odbrana(a.Odbrana), Zastita(a.Zastita){}

    void dobraZastita(Tehnicar &t){
        Zastita++;
        korisnost++;
        t.setDizanje(1);
        cout<<"Libero +1, tehnicar -1"<<endl;
    }

    void setdobroDodavanje(int brojDobrihDodavanja){
        Odbrana+=brojDobrihDodavanja;
        korisnost-=korisnost;
    }

    void predstaviSe(){
        Igrac::predstaviSe();
        cout<<" - libero."<<endl;
    }

    int identifikacija(){return 2;}
};

#endif // LIBERO_HPP_INCLUDED
