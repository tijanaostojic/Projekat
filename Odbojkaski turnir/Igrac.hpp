#ifndef IGRAC_HPP_INCLUDED
#define IGRAC_HPP_INCLUDED

class Igrac
{
protected:
    string ime;
    string prezime;
    int godine;
    int korisnost;
public:
    Igrac(string i="", string p="", int g=0, int k=0){
        ime=i;
        prezime=p;
        godine=g;
        korisnost=k;
    }

    friend ostream& operator<<(ostream& izlaz, const Igrac& o)
    {

        izlaz<<"Ime: "<<o.ime<<endl;
        izlaz<<"Prezime: "<<o.prezime<<endl;
        izlaz<<"Godine: "<<o.godine<<endl;
        izlaz<<"Korisnost: "<<o.korisnost;
        return izlaz;

    }
};

#endif // IGRAC_HPP_INCLUDED
