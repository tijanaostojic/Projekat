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
    static int brojUtakmica; // retrospektiva nakon 10 utakmica

    Utakmica( Tim t1, Tim t2, Hala h, int rezt1=0, int rezt2=0):tim1(t1), tim2(t2), hala(h){
        RezTim1=rezt1;
        RezTim2=rezt2;
        brojUtakmica++;
    }
    ~Utakmica(){
        brojUtakmica--;
    }

};

#endif // UTAKMICA_HPP_INCLUDED
