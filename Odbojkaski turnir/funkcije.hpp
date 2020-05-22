#ifndef FUNKCIJE_HPP_INCLUDED
#define FUNKCIJE_HPP_INCLUDED
#include "KOREKTOR.HPP"
#include "LIBERO.HPP"
#include "PRIMAC.HPP"
#include "SREDNJI_BLOKER.HPP"
#include "TEHNICAR.HPP"
#include "TIM.HPP"
vector<string> splitSen(string str, char c=',')
{
    string w = "";
    vector<string> v;
    for (auto rem : str)
    {
        if (rem==c)
        {
            v.push_back(w);
            w="";
        }
        else
        {
            w=w+rem;
        }
    }
    v.push_back(w);

    return v;
}
void citajTxt(string nazivFajla)
{
    string linija;
    ifstream fajl (nazivFajla);
    if (fajl.is_open())
    {
        while ( getline (fajl,linija) )
        {
            cout<<linija<<endl;
        }
        fajl.close();
    }

    else
        cout << "Neuspesno otvoren fajl";

}

Libero izaberiLibera( Tim &tim1, Tim &tim2, Tim &tim3)
{
    int liberokorisnost[3];
    Libero najboljilibero();
    liberokorisnost[0]=tim1.getigraci()[0]->getKorisnost();
    liberokorisnost[1]=tim1.getigraci()[0]->getKorisnost();
    liberokorisnost[2]=tim3.getigraci()[0]->getKorisnost();
    int max=liberokorisnost[0], maxl=0;
    for(int i=1; i<3; i++)
    {
        if(liberokorisnost[i]>max)
        {
            max=liberokorisnost[i];
            maxl=i;
        }
    }
    switch(maxl)
    {
    case 0:
        najboljilibero=((*tim1)->getigraci())[0];
        break;
    case 1:
        najboljilibero=tim2.getigraci()[1];
        break;
    case 3:
        najboljilibero=tim3.getigraci()[2];
        break;
    }
    return najboljilibero;
}
Primac izaberiPrimaca( Tim tim1, Tim tim2, Tim tim3)
{
    int primackorisnost[3];
    Primac najboljiprimac();
    primackorisnost[0]=tim1.getigraci()[0].getKorisnost();
    primackorisnost[1]=tim2.getigraci()[0].getKorisnost();
    primackorisnost[2]=tim3.getigraci()[0].getKorisnost();
    int max=primackorisnost[0], maxp=0;
    for(int i=1; i<3; i++)
    {
        if(primackorisnost[i]>max)
        {
            max=primackorisnost[i];
            maxp=i;
        }
    }
    switch(maxp)
    {
    case 0:
        najboljiprimac=tim1.getigraci()[0];
        break;
    case 1:
        najboljiprimac=tim2.getigraci()[1];
        break;
    case 3:
        najboljiprimac=tim3.getigraci()[2];
        break;
    }
    return najboljiprimac;
}
Tehnicar izaberiTehnicara(Tim tim1, Tim tim2, Tim tim3)
{
    int tehnicarkorisnost[3];
    Tehnicar najboljitehnicar();
    tehnicarkorisnost[0]=tim1.getigraci()[0].getKorisnost();
    tehnicarkorisnost[1]=tim2.getigraci()[0].getKorisnost();
    tehnicarkorisnost[2]=tim3.getigraci()[0].getKorisnost();
    int max=tehnicarkorisnost[0], maxt=0;
    for(int i=1; i<3; i++)
    {
        if(tehnicarkorisnost[i]>max)
        {
            max=tehnicarkorisnost[i];
            maxt=i;
        }
    }
    switch(maxt)
    {
    case 0:
        najboljitehnicar=tim1.getigraci()[0];
        break;
    case 1:
        najboljitehnicar=tim2.getigraci()[1];
        break;
    case 3:
        najboljitehnicar=tim3.getigraci()[2];
        break;
    }
    return najboljitehnicar;
}
SrednjiBloker izaberisrednjaka( Tim tim1, Tim tim2, Tim tim3)
{
    int srednjakorisnost[3];
    SrednjiBloker najboljisrednjak();
    srednjakorisnost[0]=tim1.getigraci()[0].getKorisnost();
    srednjakorisnost[1]=tim2.getigraci()[0].getKorisnost();
    srednjakorisnost[2]=tim3.getigraci()[0].getKorisnost();
    int max=srednjakorisnost[0], maxsb=0;
    for(int i=1; i<3; i++)
    {
        if(srednjakorisnost[i]>max)
        {
            max=srednjakorisnost[i];
            maxsb=i;
        }
    }
    switch(maxsb)
    {
    case 0:
        najboljisrednjak=tim1.getigraci()[0];
        break;
    case 1:
        najboljisrednjak=tim2.getigraci()[1];
        break;
    case 3:
        najboljisrednjak=tim3.getigraci()[2];
        break;
    }
    return najboljisrednjak;
}
Korektor izaberiKorektora( Tim tim1, Tim tim2, Tim tim3)
{
    int korektorkorisnost[3];
    Korektor najboljikorektor();
    korektorkorisnost[0]=tim1.getigraci()[0].getKorisnost();
    korektorkorisnost[1]=tim2.getigraci()[0].getKorisnost();
    korektorkorisnost[2]=tim3.getigraci()[0].getKorisnost();
    int max=korektorkorisnost[0], maxk=0;
    for(int i=1; i<3; i++)
    {
        if(korektorkorisnost[i]>max)
        {
            max=korektorkorisnost[i];
            maxk=i;
        }
    }
    switch(maxk)
    {
    case 0:
        najboljikorektor=tim1.getigraci()[0];
        break;
    case 1:
        najboljikorektor=tim2.getigraci()[1];
        break;
    case 3:
        najboljikorektor=tim3.getigraci()[2];
        break;
    }
    return najboljikorektor;
}
void meni(const Hala &h1,const Hala &h2,const Hala &h3,const Hala &h4, const Grad &g1, const Grad &g2, const Grad &g3, const Tim &tim1, const Tim &tim2, const Tim &tim3)
{
    cout<<"Sta zelite da vidite"<<endl;
    cout<<"1 - timove"<<endl;
    cout<<"2 - hale"<<endl;
    cout<<"3 - gradove"<<endl;
    cout<<"4 - rezultati utakmica"<<endl;
    cout<<"5 - unesite korisnost svim igracima"<<endl;
    int izbor;
    cin>>izbor;

    int xxx;


    //cout << Utakmica::brojUtakmica << endl;
    if(izbor==1)
    {
        cout<<"-----Timovi:-----"<<endl<<endl<<endl;

        cout<<"-> Tim 1 - Strand Volley <-" <<endl;

        cout<<g1<<endl;
        tim1.ispisiIgrace();
        cout<<endl;



        cout<<"-> Tim 2 - NS Volley Team <-"<<endl;

        cout<<g2<<endl;
        tim2.ispisiIgrace();
        cout<<endl;

        cout<<"-> Tim 3 - Star <-"<<endl;

        cout<<g3<<endl;
        tim3.ispisiIgrace();
        cout<<endl;


    }

    if(izbor==2)
    {
        cout<<"-----Hale u kojima su utakmice odigrane:-----"<<endl<<endl<<endl;

        cout<<"Hala 1: "<<endl<<h1<<endl;
        cout<<"Hala 2: "<<endl<<h2<<endl;
        cout<<"Hala 3: "<<endl<<h3<<endl;
        cout<<"Hala 4: "<<endl<<h4<<endl;
    }

    if(izbor==3)
    {
        citajTxt("gradovi.txt");
    }
    if(izbor==4)
    {
        cout<<"----Odigrane utakmice----"<<endl<<endl<<endl;
        cout<<"1. Strand Volley - NS Volley Team, 3:2"<<endl;
        cout<<"2. Strand Volley - Star, 1:3"<<endl;
        cout<<"3. NS Volley Team - Star, 0:3"<<endl<<endl<<endl;
    }
    if(izbor==5)
    {


    }


    cout<<"Kliknite bilo koje dugme osim 0 da se vratite na meni, a 0 da zavrsite program."<<endl;
    cin>>xxx;
    if(xxx==0)
    {
        return;
    }

    system("cls");
    meni(h1, h2, h3, h4, g1, g2, g3,  tim1, tim2, tim3);

}

#endif // FUNKCIJE_HPP_INCLUDED
