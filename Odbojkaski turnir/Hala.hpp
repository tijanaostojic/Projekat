#ifndef HALA_HPP_INCLUDED
#define HALA_HPP_INCLUDED
#include "GRAD.HPP"
class Hala
{
protected:
    Grad grad;
    int brojTerena;
    int kapacitet;
public:
    Hala(string i="", string o="", string d="", int brojS=0, int brojTerena1=0, int kapacitet1=0):grad(i, o, d, brojS)
    {
        brojTerena=brojTerena1;
        kapacitet=kapacitet1;
    }

    Hala(const Hala &a):grad(a.grad), brojTerena(a.brojTerena), kapacitet(a.kapacitet){}

    friend ostream& operator<<(ostream& izlaz, const Hala& o)
    {

        izlaz<<o.grad<<endl;
        izlaz<<"Broj terena: "<<o.brojTerena<<endl;
        izlaz<<"Kapacitet: "<<o.kapacitet<<endl;
        return izlaz;

    }
};


#endif // HALA_HPP_INCLUDED
