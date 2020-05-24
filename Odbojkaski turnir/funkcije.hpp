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
void pisiTxt(string nazivFajla, string tekst, char mode='a')
{
    ofstream fajl;

    if (mode=='a'){
        fajl.open (nazivFajla, ios_base::app);
    }else{
        fajl.open (nazivFajla);
    }

    fajl << tekst;

    fajl.close();

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

Libero* izaberiLibera( Tim &tim1, Tim &tim2, Tim &tim3)
{
    int liberokorisnost[3];
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
    if(maxl==0)
            return (Libero*)tim1.getigraci()[0];

    else if(maxl==1)

            return (Libero*)tim2.getigraci()[0];
    else
            return (Libero*)tim3.getigraci()[0];

}
Primac* izaberiPrimaca( Tim &tim1, Tim &tim2, Tim &tim3)
{
    int primackorisnost[3];
    primackorisnost[0]=tim1.getigraci()[1]->getKorisnost();
    primackorisnost[1]=tim1.getigraci()[1]->getKorisnost();
    primackorisnost[2]=tim3.getigraci()[1]->getKorisnost();
    int max=primackorisnost[0], maxp=0;
    for(int i=1; i<3; i++)
    {
        if(primackorisnost[i]>max)
        {
            max=primackorisnost[i];
            maxp=i;
        }
    }
    if(maxp==0)
            return (Primac*)tim1.getigraci()[1];

    else if(maxp==1)

            return (Primac*)tim2.getigraci()[1];
    else
            return (Primac*)tim3.getigraci()[1];

}
Tehnicar* izaberiTehnicara( Tim &tim1, Tim &tim2, Tim &tim3)
{
    int tehnicarkorisnost[3];
    tehnicarkorisnost[0]=tim1.getigraci()[2]->getKorisnost();
    tehnicarkorisnost[1]=tim1.getigraci()[2]->getKorisnost();
    tehnicarkorisnost[2]=tim3.getigraci()[2]->getKorisnost();
    int max=tehnicarkorisnost[0], maxt=0;
    for(int i=1; i<3; i++)
    {
        if(tehnicarkorisnost[i]>max)
        {
            max=tehnicarkorisnost[i];
            maxt=i;
        }
    }
    if(maxt==0)
            return (Tehnicar*)tim1.getigraci()[2];

    else if(maxt==1)

            return (Tehnicar*)tim2.getigraci()[2];
    else
            return (Tehnicar*)tim3.getigraci()[2];

}
SrednjiBloker* izaberisrednjaka( Tim &tim1, Tim &tim2, Tim &tim3)
{
    int srednjakkorisnost[3];
    srednjakkorisnost[0]=tim1.getigraci()[3]->getKorisnost();
    srednjakkorisnost[1]=tim1.getigraci()[3]->getKorisnost();
    srednjakkorisnost[2]=tim3.getigraci()[3]->getKorisnost();
    int max=srednjakkorisnost[0], maxsb=0;
    for(int i=1; i<3; i++)
    {
        if(srednjakkorisnost[i]>max)
        {
            max=srednjakkorisnost[i];
            maxsb=i;
        }
    }
    if(maxsb==0)
            return (SrednjiBloker*)tim1.getigraci()[3];

    else if(maxsb==1)

            return (SrednjiBloker*)tim2.getigraci()[3];
    else
            return (SrednjiBloker*)tim3.getigraci()[3];

}
Korektor* izaberikorektora( Tim &tim1, Tim &tim2, Tim &tim3)
{
    int korektorkorisnost[3];
    korektorkorisnost[0]=tim1.getigraci()[4]->getKorisnost();
    korektorkorisnost[1]=tim1.getigraci()[4]->getKorisnost();
    korektorkorisnost[2]=tim3.getigraci()[4]->getKorisnost();
    int max=korektorkorisnost[0], maxk=0;
    for(int i=1; i<3; i++)
    {
        if(korektorkorisnost[i]>max)
        {
            max=korektorkorisnost[i];
            maxk=i;
        }
    }
    if(maxk==0)
            return (Korektor*)tim1.getigraci()[4];

    else if(maxk==1)

            return (Korektor*)tim2.getigraci()[4];
    else
            return (Korektor*)tim3.getigraci()[4];

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
        cout<<"2. Strand Volley - Star, 3:0"<<endl;
        cout<<"3. NS Volley Team - Star, 3:1"<<endl<<endl<<endl;
        cout<<"=================="<<endl;
        cout<<"-----1. MESTO-----"<<endl;
        cout<<"=================="<<endl;
        cout<<"---Strand Volley---"<<endl;
        cout<<"=================="<<endl<<endl<<endl;
        cout<<"=================="<<endl;
        cout<<"-----2. MESTO-----"<<endl;
        cout<<"=================="<<endl;
        cout<<"--NS Volley Team--"<<endl;
        cout<<"=================="<<endl<<endl<<endl;
        cout<<"=================="<<endl;
        cout<<"-----3. MESTO-----"<<endl;
        cout<<"=================="<<endl;
        cout<<"-------Star-------"<<endl;
        cout<<"=================="<<endl<<endl<<endl;
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
