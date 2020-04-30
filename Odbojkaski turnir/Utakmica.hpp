#ifndef UTAKMICA_HPP_INCLUDED
#define UTAKMICA_HPP_INCLUDED
#include "TIM.HPP"
#include "HALA.HPP"
#include "TEHNICAR.HPP"
class Utakmica
{
protected:
    Tim tim1;
    Tim tim2;
    int RezTim1;
    int RezTim2;
    Hala hala;
public:
    Utakmica(int rezt1=0, int rezt2=0, string ime1="", int brojekipa1=0, string imetrenera1="", string prezimetrenera1="",string ime2="", int brojekipa2=0, string imetrenera2="", string prezimetrenera2="", string i="", string o="", string d="", int brojS=0, int brojTerena1=0, int kapacitet1=0)
    :tim1(ime1, brojekipa1, imetrenera1, prezimetrenera1), tim2(ime2, brojekipa2, imetrenera2, prezimetrenera2), hala(i, o, d, brojS, brojTerena1, kapacitet1){
        RezTim1=rezt1;
        RezTim2=rezt2;
    }


};

#endif // UTAKMICA_HPP_INCLUDED
