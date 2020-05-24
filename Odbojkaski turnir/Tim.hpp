#ifndef TIM_HPP_INCLUDED
#define TIM_HPP_INCLUDED
#include "KOREKTOR.HPP"
#include "LIBERO.HPP"
#include "PRIMAC.HPP"
#include "SREDNJI_BLOKER.HPP"
#include "TEHNICAR.HPP"
class Tim
{
protected:
    string Ime;
    int brojEkipa;
    int brojIgraca;
    string imeTrenera;
    string prezimeTrenera;
    vector <Igrac*> igraci;
public:
    Tim(string i, int brE, int brI, string imeT, string prezimeT)
    {
        Ime=i;
        brojEkipa=brE;
        brojIgraca=brI;
        imeTrenera=imeT;
        prezimeTrenera=prezimeT;
    }
    Tim(const Tim &a):Ime(a.Ime), brojEkipa(a.brojEkipa), brojIgraca(a.brojIgraca), imeTrenera(a.imeTrenera), prezimeTrenera(a.prezimeTrenera){}
    string getIme()const{return Ime;}
    vector <Igrac*> getigraci()const{return igraci;}

    void dodajIgraca(Igrac *i)
    {
        igraci.push_back(i);
    }

    void korisnostTima(){
        int x;
    for (auto it=igraci.begin(); it!=igraci.end(); it++)
        {
            (*it)->predstaviSe();
            cin>>x;
            (*it)->setKorisnost(x);
        }

    for (auto it=igraci.begin(); it!=igraci.end(); it++)
        {
            (*it)->predstaviSe();
            cout<<"   Korisnost: ";
           cout<<(*it)->getKorisnost()<<endl;
        }
    }

    void ispisiIgrace()const
    {
        cout<<"Igraci tima "<<Ime<<": "<<endl;
        for (auto it=igraci.begin(); it!=igraci.end(); it++)
        {
            (*it)->predstaviSe();
        }
    }

    void pretraga(string s)
    {
        int a=0;
        int b=0;
        if(s=="korektor"||s=="Korektor")
            a=1;
        if(s=="libero"||s=="Libero")
            a=2;
        if(s=="primac"||s=="Primac")
            a=3;
        if(s=="srednjak"||s=="Srednjak"|| s=="Srednji bloker")
            a=4;
        if(s=="tehnicar"||s=="Tehnicar")
            a=5;
        for (auto it=igraci.begin(); it!=igraci.end(); it++)
        {
            if((*it)->identifikacija()==a)
            {
                cout<<"PRETRAGA PRONADJENA"<<endl;
                cout<< **it <<endl;
                b++;
                break;
            }
        }
        if(b==0)
            cout<<"Ne postoji igrac na toj poziciji"<<endl;
    }

    bool izadji(const Igrac &i)
    {
        for (auto it=igraci.begin(); it!=igraci.end(); it++)
        {
            if (i.getIme()==(*it)->getIme() && i.getPrezime()==(*it)->getPrezime())
            {
                igraci.erase(it);
                return true;
            }
        }
        return false;
    }

    void setIgraci(vector<Igrac*> igr){
        igraci=igr;
    }
};

#endif // TIM_HPP_INCLUDED
