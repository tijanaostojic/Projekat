#ifndef GRAD_HPP_INCLUDED
#define GRAD_HPP_INCLUDED
class Grad
{
protected:
    string ime;
    string okrug;
    string drzava;
    int brojStanovnika;
public:
    Grad(string i, string o, string d, int brS)
    {
        ime=i;
        okrug=o;
        drzava=d;
        brojStanovnika=brS;
    }
    friend ostream& operator<<(ostream& izlaz, const Grad& o)
    {

        izlaz<<"Ime grada: "<<o.ime<<endl;
        izlaz<<"Okrug: "<<o.okrug<<endl;
        izlaz<<"Drzava: "<<o.drzava<<endl;
        izlaz<<"Broj stanovnika: "<<o.brojStanovnika;
        return izlaz;

    }
};



#endif // GRAD_HPP_INCLUDED
