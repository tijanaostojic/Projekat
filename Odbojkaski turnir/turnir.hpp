#ifndef TURNIR_HPP_INCLUDED
#define TURNIR_HPP_INCLUDED

class Turnir{
private:
    string naziv;
    vector<Tim*> sviTimovi;
public:
    Turnir(string ime){
        naziv=ime;
    }
    void addTim(Tim *t){
        sviTimovi.push_back(t);
    }
    vector<Tim*> getTimovi()const{return sviTimovi;}
    ~Turnir(){sviTimovi.clear();}
};



#endif // TURNIR_HPP_INCLUDED
