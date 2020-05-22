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

    string getIme()const {return ime;}
    string getPrezime()const {return prezime;}
    int getKorisnost()const{return korisnost;}
    void setKorisnost(int korisnostt){
        korisnost=korisnostt;
    }
    friend ostream& operator<<(ostream& izlaz, const Igrac& o)
    {

        izlaz<<"Ime: "<<o.ime<<endl;
        izlaz<<"Prezime: "<<o.prezime<<endl;
        izlaz<<"Godine: "<<o.godine<<endl;
        izlaz<<"Korisnost: "<<o.korisnost<<endl;
        return izlaz;

    }

    virtual void predstaviSe(){
        cout<<ime<<" "<<prezime<<", "<<godine<<" godina";
    }

    virtual int identifikacija(){return 0;}
};

#endif // IGRAC_HPP_INCLUDED
