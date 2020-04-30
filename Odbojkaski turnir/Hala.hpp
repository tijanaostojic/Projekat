#ifndef HALA_HPP_INCLUDED
#define HALA_HPP_INCLUDED
class Hala
{
protected:
    Grad grad;
    int brojTerena;
    int kapacitet;
    int Ljudi;
public:
    Hala(string i="", string o="", string d="", int brojS=0, int brojTerena1=0, int kapacitet1=0):grad(i, o, d, brojS){
        brojTerena=brojTerena1;
        kapacitet=kapacitet1;
    }
};


#endif // HALA_HPP_INCLUDED
