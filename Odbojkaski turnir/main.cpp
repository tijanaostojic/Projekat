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

int Utakmica::brojUtakmica=0;


void Blokiraj(SrednjiBloker &sb, Korektor &k){
        sb.Blokiraj();

        k.setBlokiran(1);
        //cout<< "Korektor: -1, srednji bloker +1" << endl;
    }
vector<Igrac> getIgraciIzFajla(string nazivF)
{
    string linija;
    int i=0;
    ifstream fajl (nazivF);
    vector<Igrac*> igraci;
    vector<string> rezultat;
    if (fajl.is_open())
    {
        while ( getline (fajl,linija) )
        {
            if (i==0)
                continue;
            cout<<linija<<endl;
            rezultat = splitSen(linija);
            tip = rezultat[3];
            /// Tijana,Ostojic,16,S,45

            if (tip=="L")
            {
                Libero* l = new Libero(rezultat[0], rezultat[1], stoi(rezultat[2]));
                /// moze i l.setKorisnost(rezultat[4]);
                igraci.push_back(l);
            }
            else if (tip=="K")
            {
                Korektor* k = new Korektor();
                igraci.push_back(k);
            }
            /// ...

            i++;
        }
        fajl.close();
        return igraci;
    }

    else
        cout << "Neuspesno otvoren fajl";

}
Tim getTimIzFajla(string nazivF)
{

    string linija;
    int i=0;
    ifstream fajl (nazivF);
    vector<string> rezultat;
    if (fajl.is_open())
    {
        while ( getline (fajl,linija) )
        {
            if (i==0){
                rezultat = splitSen(linija);
                /// Star,1,5,Goran,Kamasi
                Tim t(rezultat[0], stoi(rezultat[1]),stoi(rezultat[2]),rezultat[3],rezultat[4] );
                return t;
            }

            i++;
        }
        fajl.close();
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

    Libero l1("Draga", "Cirovic", 17);
    Primac p1("Lea", "Keneski", 16);
    Tehnicar t1("Jelena", "Jankovic", 16);
    SrednjiBloker sb1("Tijana", "Ostojic", 17);
    Korektor k1("Lena", "Kutanjac", 16);

    Tim tim1("Strand volley", 3, 40, "Igor", "Tesic");
    tim1.dodajIgraca(&l1);
    tim1.dodajIgraca(&p1);
    tim1.dodajIgraca(&t1);
    tim1.dodajIgraca(&sb1);
    tim1.dodajIgraca(&k1);

    Libero l2("Irina", "Pokrajac", 18);
    Primac p2("Ira", "Pantelic", 16);
    Tehnicar t2("Sladjana", "Petkovic", 17);
    SrednjiBloker sb2("Maja", "Bjedov", 17);
    Korektor k2("Masa", "Mudric", 16);

    Tim tim2("NS Volley Team", 2, 20, "Ivona", "Sobot");
    tim2.dodajIgraca(&l2);
    tim2.dodajIgraca(&p2);
    tim2.dodajIgraca(&t2);
    tim2.dodajIgraca(&sb2);
    tim2.dodajIgraca(&k2);

    Libero l3("Vanja", "Vucurovic", 21);
    Primac p3("Milica", "Joldic", 15);
    Tehnicar t3("Bojana", "Balaban", 18);
    SrednjiBloker sb3("Bojana", "Knezevic", 16);
    Korektor k3("Andjela", "Bjelic", 17);

    Tim tim3("Star", 1, 5, "Goran", "Kamasi");
    tim3.dodajIgraca(&l3);
    tim3.dodajIgraca(&p3);
    tim3.dodajIgraca(&t3);
    tim3.dodajIgraca(&sb3);
    tim3.dodajIgraca(&k3);


    Turnir t("Srbija, zenski");

    for (int i=0; i<5; i++)
    {

        /// ucitaj igrace iz fajla
        vector<Igrac*> igraci = getIgraciIzFajla("fajl"+i+".txt");
        Tim t = getTimIzFajla("fajl"+i+".txt");
        t.setIgraci(igraci);
        turnir.addTim(t);
    }
    Grad g1("Novi Sad", "Juznobacki", "Srbija", 350000);
    Grad g2("Beograd", "Grad Beograd", "Srbija", 1347000);
    Grad g3("Kikinda", "Severnobanatski", "Srbija", 40000);
    Hala h1("Beograd", "Grad Beograd", "Srbija", 1347000, 2, 200);
    Hala h2("Novi Sad", "Juznobacki", "Srbija", 350000, 3, 70);
    Hala h3("Kikinda", "Severnobanatski", "Srbija", 40000, 1, 50);
    Hala h4("Loznica", "Macvanski", "Srbija", 85000, 1, 100);

    Utakmica u1(tim1, tim2, h1, 3, 2);
    Utakmica u2(tim1, tim3, h2, 3, 0);
    Utakmica u3(tim2, tim3, h3, 3, 1);
    /// za sve igrace tima iz turnira t.getTimovi()
    for();
    cout<<"Upisite korisnost igraca tima "<<tim1.getIme()<<":"<<endl;
    tim1.korisnostTima();
    cout<<endl;
    cout<<"Upisite korisnost igraca tima "<<tim2.getIme()<<":"<<endl;
    tim2.korisnostTima();
    cout<<endl;
    cout<<"Upisite korisnost igraca tima "<<tim3.getIme()<<":"<<endl;
    tim3.korisnostTima();
    cout<<endl;


    Libero* najboljiL = new Libero (izaberiLibera(tim1, tim2, tim3));
    pisiTxt("najboljiigraci.txt", "Najbolji libero je: "+najboljiL->getIme()+" "+najboljiL->getPrezime()+"\n", 'w');

    Primac* najboljiP = Primac(izaberiPrimaca(tim1, tim2, tim3));
    pisiTxt("najboljiigraci.txt", "Najbolji primac je: "+najboljiP->getIme()+" "+najboljiP->getPrezime()+"\n", 'a');

    Tehnicar* najboljiT = new Tehnicar(izaberiTehnicara(tim1, tim2, tim3));
    pisiTxt("najboljiigraci.txt", "Najbolji tehnicar je: "+najboljiT->getIme()+" "+najboljiT->getPrezime()+"\n", 'a');

    SrednjiBloker* najboljiS = new SrednjiBloker(izaberisrednjaka(tim1, tim2, tim3));
    pisiTxt("najboljiigraci.txt", "Najbolji srednjak je: "+najboljiS->getIme()+" "+najboljiS->getPrezime()+"\n", 'a');

    Korektor* najboljiK = new Korektor(izaberikorektora(tim1, tim2, tim3));
    pisiTxt("najboljiigraci.txt", "Najbolji korektor je: "+najboljiK->getIme()+" "+najboljiK->getPrezime()+"\n", 'a');

    citajTxt("najboljiigraci.txt");
    cout<<endl<<endl<<endl<<endl;
    meni(h1, h2, h3, h4, g1, g2, g3, tim1, tim2, tim3);




    return 0;
}
