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
    Grad(string i, string o, string d, int brS){
        ime=i;
        okrug=o;
        drzava=d;
        brojStanovnika=brS;
    }
};



#endif // GRAD_HPP_INCLUDED
