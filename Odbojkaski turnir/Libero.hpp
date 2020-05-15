#ifndef LIBERO_HPP_INCLUDED
#define LIBERO_HPP_INCLUDED
#include "IGRAC.HPP"
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

    void predstaviSe(){
        Igrac::predstaviSe();
        cout<<"Igram na poziciji libera."<<endl;
    }

    int identifikacija(){return 2;}
};

#endif // LIBERO_HPP_INCLUDED
