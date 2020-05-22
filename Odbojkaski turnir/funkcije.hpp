#ifndef FUNKCIJE_HPP_INCLUDED
#define FUNKCIJE_HPP_INCLUDED

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
void meni(const Hala &h1,const Hala &h2,const Hala &h3,const Hala &h4, const Grad &g1, const Grad &g2, const Grad &g3, const Tim &tim1, const Tim &tim2, const Tim &tim3){
    cout<<"Sta zelite da vidite"<<endl;
    cout<<"1 - timove"<<endl;
    cout<<"2 - hale"<<endl;
    cout<<"3 - gradove"<<endl;
    int izbor;
    cin>>izbor;

    int xxx;


    //cout << Utakmica::brojUtakmica << endl;
    if(izbor==1){
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

    if(izbor==2){
    cout<<"-----Hale u kojima su utakmice odigrane:-----"<<endl<<endl<<endl;

    cout<<"Hala 1: "<<endl<<h1<<endl;
    cout<<"Hala 2: "<<endl<<h2<<endl;
    cout<<"Hala 3: "<<endl<<h3<<endl;
    cout<<"Hala 4: "<<endl<<h4<<endl;
    }

    if(izbor==3){
        citajTxt("gradovi.txt");
    }
    cout<<"Kliknite bilo koje dugme osim 0 da se vratite na meni, a 0 da zavrsite program."<<endl;
    cin>>xxx;
    if(xxx==0){
        return;
    }
    system("cls");
    meni(h1, h2, h3, h4, g1, g2, g3,  tim1, tim2, tim3);

}

#endif // FUNKCIJE_HPP_INCLUDED
