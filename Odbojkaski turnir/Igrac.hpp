#ifndef IGRAC_HPP_INCLUDED
#define IGRAC_HPP_INCLUDED

class Igrac
{
protected:
    string ime;
    string prezime;
    int godine;
public:
    Igrac(string i="", string p="", int g=0){
        ime=i;
        prezime=p;
        godine=g;
    }
};

#endif // IGRAC_HPP_INCLUDED
