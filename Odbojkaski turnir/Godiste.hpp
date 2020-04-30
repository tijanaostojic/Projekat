#ifndef GODISTE_HPP_INCLUDED
#define GODISTE_HPP_INCLUDED
enum kategorija{Junior, Pionir, Kadet, Senior};
class Godiste
{
protected:
    int godina;
    kategorija kategorija1;
public:
    Godiste(int g=0, kategorija k=Junior){
        godina=g;
        kategorija1=k;
    }
};


#endif // GODISTE_HPP_INCLUDED
