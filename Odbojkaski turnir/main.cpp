#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#include "GODISTE.HPP"
#include "GRAD.HPP"
#include "KOLA.HPP"
#include "KOREKTOR.HPP"
#include "LIBERO.HPP"
#include "PRIMAC.HPP"
#include "SREDNJI_BLOKER.HPP"
#include "TEHNICAR.HPP"
#include "TIM.HPP"
#include "UTAKMICA.HPP"
#include "HALA.HPP"
#include "FUNKCIJE.HPP"
#include "TURNIR.HPP"
int Utakmica::brojUtakmica=0;



vector <Igrac*> getIgraciIzFajla(string nazivF)
{
    string linija;
    int i=0;
    ifstream fajl (nazivF);
    vector <Igrac*> igraci;
    vector<string> rezultat;
    string tip;
    if (fajl.is_open())
    {
        while ( getline (fajl,linija) )
        {
            if(linija=="")
                break;
            if (i>0)
            {
                rezultat = splitSen(linija);
                tip = rezultat[3];
                /// Tijana,Ostojic,16,S,45
                if (tip=="L")
                {
                    Libero* l = new Libero(rezultat[0], rezultat[1], stoi(rezultat[2]));
                    l->setKorisnost(stoi(rezultat[4]));
                    igraci.push_back(l);

                }
                else if (tip=="K")
                {
                    Korektor* k = new Korektor(rezultat[0], rezultat[1], stoi(rezultat[2]));
                    k->setKorisnost(stoi(rezultat[4]));
                    igraci.push_back(k);
                }
                else if (tip=="S")
                {
                    SrednjiBloker* s = new SrednjiBloker(rezultat[0], rezultat[1], stoi(rezultat[2]));
                    s->setKorisnost(stoi(rezultat[4]));
                    igraci.push_back(s);
                }
                else if (tip=="P")
                {
                    Primac* p = new Primac(rezultat[0], rezultat[1], stoi(rezultat[2]));
                    p->setKorisnost(stoi(rezultat[4]));
                    igraci.push_back(p);
                }
                else if (tip=="T")
                {
                    Tehnicar* t = new Tehnicar(rezultat[0], rezultat[1], stoi(rezultat[2]));
                    t->setKorisnost(stoi(rezultat[4]));
                    igraci.push_back(t);
                }
            }
            i++;

        }
        fajl.close();
        return igraci;
    }

    else
        cout << "Neuspesno otvoren fajl";

}
Tim* getTimIzFajla(string nazivF)
{

    string linija;
    ifstream fajl (nazivF);
    vector<string> rezultat;
    if (fajl.is_open())
    {
        getline (fajl,linija);

        rezultat = splitSen(linija);
        /// Star,1,5,Goran,Kamasi
        Tim* t= new Tim(rezultat[0], stoi(rezultat[1]),stoi(rezultat[2]),rezultat[3],rezultat[4] );
        fajl.close();
        return t;
    }
    else
        cout << "Neuspesno otvoren fajl";
}
int main()
{
    /*1. Program sluzi za pravljenje izvestaja o utakmicama: statistiku svakog igraca, rezultat...
    Na osnovu njega predvidja pobednika turnira, kao i najbolje igrace u svakoj poziciji na osnovu njihove statistike na svim utakmicama.
    Program predvidja pobednika tako sto posle svakog kola racuna procenat sanse za pobedu nekog tima.*/
    /* 2. Korisnik unosi rezultate svih utamica i statistiku igraca na osnovu cega program bira pobednika i
    najboljeg igraca na svakoj poziciji*/

    cout<<"==============================="<<endl;
    cout<<"-------ODBOJKASKI TURNIR-------"<<endl;
    cout<<"==============================="<<endl;
    Grad g1("Novi Sad", "Juznobacki", "Srbija", 350000);
    Grad g2("Beograd", "Grad Beograd", "Srbija", 1347000);
    Grad g3("Kikinda", "Severnobanatski", "Srbija", 40000);
    Hala h1("Beograd", "Grad Beograd", "Srbija", 1347000, 2, 200);
    Hala h2("Novi Sad", "Juznobacki", "Srbija", 350000, 3, 70);
    Hala h3("Kikinda", "Severnobanatski", "Srbija", 40000, 1, 50);
    Hala h4("Loznica", "Macvanski", "Srbija", 85000, 1, 100);

    Turnir t("Srbija, zenski");

    for (auto i=0; i<5; i++)
    {
        /// ucitaj igrace iz fajla
        vector <Igrac*> igraci = getIgraciIzFajla("fajl"+to_string(i)+".txt");
        Tim* team =  new Tim();
        team = getTimIzFajla("fajl"+to_string(i)+".txt");
        team->setIgraci(igraci);
        t.addTim(team);
    }
    Libero* najboljiL = new Libero();
    najboljiL = izaberiLibera(t);
    pisiTxt("najboljiigraci.txt", "Najbolji libero je: "+najboljiL->getIme()+" "+najboljiL->getPrezime()+"\n", 'w');

    Primac* najboljiP = new Primac();
    najboljiP = izaberiPrimaca(t);
    pisiTxt("najboljiigraci.txt", "Najbolji primac je: "+najboljiP->getIme()+" "+najboljiP->getPrezime()+"\n", 'a');

    Tehnicar* najboljiT = new Tehnicar();
    najboljiT = izaberiTehnicara(t);
    pisiTxt("najboljiigraci.txt", "Najbolji tehnicar je: "+najboljiT->getIme()+" "+najboljiT->getPrezime()+"\n", 'a');

    SrednjiBloker* najboljiS = new SrednjiBloker();
    najboljiS = izaberisrednjaka(t);
    pisiTxt("najboljiigraci.txt", "Najbolji srednjak je: "+najboljiS->getIme()+" "+najboljiS->getPrezime()+"\n", 'a');

    Korektor* najboljiK = new Korektor();
    najboljiK = izaberikorektora(t);
    pisiTxt("najboljiigraci.txt", "Najbolji korektor je: "+najboljiK->getIme()+" "+najboljiK->getPrezime()+"\n", 'a');

    citajTxt("najboljiigraci.txt");
    cout<<endl<<endl<<endl<<endl;
    //meni(h1, h2, h3, h4, g1, g2, g3, tim1, tim2, tim3);*/




    return 0;
}
