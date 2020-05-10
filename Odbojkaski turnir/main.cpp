#include <iostream>
#include <fstream>
#include <string>

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

int Utakmica::brojUtakmica=0;

void citajTxt(string nazivFajla)
{
    string linija;
    ifstream fajl (nazivFajla);
    if (fajl.is_open())
    {
        while ( getline (fajl,linija) )
        {
            cout << linija << '\n';
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
    citajTxt("gradovi.txt");

    cout << Utakmica::brojUtakmica << endl;

    Grad g1("Novi Sad", "Juznobacki", "Srbija", 350000);
    cout<<g1<<endl<<endl;

    Hala h1("Novi Sad", "Juznobacki", "Srbija", 350000, 3, 200);
    cout<<h1<<endl;

    Igrac i1("Tijana", "Ostojic", 17, 0);
    cout<<i1;


    return 0;
}
