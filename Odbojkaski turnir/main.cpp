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


    Grad g1("Novi Sad", "Juznobacki", "Srbija", 350000);
    Grad g2("Beograd", "Grad Beograd", "Srbija", 1347000);
    Grad g3("Kikinda", "Severnobanatski", "Srbija", 40000);
    Hala h1("Beograd", "Grad Beograd", "Srbija", 1347000, 2, 200);
    Hala h2("Novi Sad", "Juznobacki", "Srbija", 350000, 3, 70);
    Hala h3("Kikinda", "Severnobanatski", "Srbija", 40000, 1, 50);
    Hala h4("Loznica", "Macvanski", "Srbija", 85000, 1, 100);

    meni(h1, h2, h3, h4, g1, g2, g3, tim1, tim2, tim3);


    /*Igrac i1("Tijana", "Ostojic", 17, 0);
    cout<<endl;
    i1.predstaviSe();
    cout<<endl;
    l1.predstaviSe();*/

    //Utakmica u1(tim1, tim2, h1, 3, 2);


    cout<<endl;

    cout<<endl;
    tim1.pretraga("libero");
    cout<<endl<<endl<<endl;
    tim1.pretraga("korektor");

    /*tim1.ispisiIgrace();
    cout<<endl;

    tim1.izadji(sb1);

    cout<<endl;
    tim1.ispisiIgrace();*/



    return 0;
}
