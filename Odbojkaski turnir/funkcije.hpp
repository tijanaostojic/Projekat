#ifndef FUNKCIJE_HPP_INCLUDED
#define FUNKCIJE_HPP_INCLUDED
#include "KOREKTOR.HPP"
#include "LIBERO.HPP"
#include "PRIMAC.HPP"
#include "SREDNJI_BLOKER.HPP"
#include "TEHNICAR.HPP"
#include "TIM.HPP"
#include "TURNIR.HPP"
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

Libero* izaberiLibera(const Turnir &t)
{
    vector<int> liberokorisnost;
    vector<Tim*> timovi=t.getTimovi();
    unsigned int i;
    string unos;
    for(i=0; i<timovi.size() ; i++){
        liberokorisnost.push_back(timovi[i]->getigraci()[0]->getKorisnost());
    }
    int max=liberokorisnost[0], maxl=0, jednako, jednakol;
    for(unsigned int i=1; i<timovi.size() ; i++)
    {
        if(liberokorisnost[i]>max)
        {
            max=liberokorisnost[i];
            maxl=i;
        }
        if(liberokorisnost[i]==max){
            jednako=liberokorisnost[i];
            jednakol=i;
        }
    }
    if(jednakol!=maxl && jednako==max){
        cout<<"Ova dva igraca imaju istu korisnost: "<< endl;
        cout<<timovi[maxl]->getigraci()[0]->getIme()<<" "<<timovi[maxl]->getigraci()[0]->getPrezime()<<endl;
        cout<<timovi[jednakol]->getigraci()[0]->getIme()<<" "<<timovi[jednakol]->getigraci()[0]->getPrezime()<<endl;
        cout<<"Ukucajte ime igraca kojem zelite da povecate korisnost"<<endl;
        cin>>unos;
        if(unos==timovi[jednakol]->getigraci()[0]->getIme()){
            Libero* lib = new Libero(timovi[jednakol]->getigraci()[0]->getIme(), timovi[jednakol]->getigraci()[0]->getPrezime(),timovi[jednakol]->getigraci()[0]->getGodine());
            lib->dobraZastita();
            return lib;
        }
        else if(unos==timovi[maxl]->getigraci()[0]->getIme()){
            Libero* libb = new Libero(timovi[maxl]->getigraci()[0]->getIme(), timovi[maxl]->getigraci()[0]->getPrezime(),timovi[maxl]->getigraci()[0]->getGodine());
            libb->dobraZastita();
            return libb;
        }
    }
    return (Libero*)(timovi[maxl]->getigraci()[0]);

}

Primac* izaberiPrimaca(const Turnir &t)
{
    vector<int> primackorisnost;
    vector<Tim*> timovi=t.getTimovi();
    unsigned int  i;
    string unos;
    for(i=0; i<timovi.size() ; i++){
        primackorisnost.push_back(timovi[i]->getigraci()[1]->getKorisnost());
    }
    int max=primackorisnost[0], maxp=0, jednako, jednakop;
    for(unsigned int i=1; i<timovi.size(); i++)
    {
        if(primackorisnost[i]>max)
        {
            max=primackorisnost[i];
            maxp=i;
        }
        if(primackorisnost[i]==max){
            jednako=primackorisnost[i];
            jednakop=i;
        }
    }
    if(jednakop!=maxp && jednako==max){
        cout<<"Ova dva igraca imaju istu korisnost: "<< endl;
        cout<<timovi[maxp]->getigraci()[1]->getIme()<<" "<<timovi[maxp]->getigraci()[1]->getPrezime()<<endl;
        cout<<timovi[jednakop]->getigraci()[1]->getIme()<<" "<<timovi[jednakop]->getigraci()[1]->getPrezime()<<endl;
        cout<<"Ukucajte ime igraca kojem zelite da povecate korisnost"<<endl;
        cin>>unos;
        if(unos==timovi[jednakop]->getigraci()[1]->getIme()){
            Primac* pri = new Primac(timovi[jednakop]->getigraci()[1]->getIme(), timovi[jednakop]->getigraci()[1]->getPrezime(),timovi[jednakop]->getigraci()[1]->getGodine());
            pri->PoentirajSmecp();
            return pri;
        }
        else if(unos==timovi[maxp]->getigraci()[1]->getIme()){
            Primac* prii = new Primac(timovi[maxp]->getigraci()[1]->getIme(), timovi[maxp]->getigraci()[1]->getPrezime(),timovi[maxp]->getigraci()[1]->getGodine());
            prii->PoentirajSmecp();
            return prii;
        }
    }
    return (Primac*)(timovi[maxp]->getigraci()[1]);

}
Tehnicar* izaberiTehnicara(const Turnir &t)
{
    vector<int> tehnicarkorisnost;
    vector<Tim*> timovi=t.getTimovi();
    unsigned int i;
    string unos;
    for(i=0; i<timovi.size() ; i++){
        tehnicarkorisnost.push_back(timovi[i]->getigraci()[2]->getKorisnost());
    }
    int max=tehnicarkorisnost[2], maxt=0, jednako, jednakot;
    for(unsigned int i=1; i<timovi.size(); i++)
    {
        if(tehnicarkorisnost[i]>max)
        {
            max=tehnicarkorisnost[i];
            maxt=i;
        }
        if(tehnicarkorisnost[i]==max){
            jednako=tehnicarkorisnost[i];
            jednakot=i;
        }
    }
    if(jednakot!=maxt && jednako==max){
        cout<<"Ova dva igraca imaju istu korisnost: "<< endl;
        cout<<timovi[maxt]->getigraci()[2]->getIme()<<" "<<timovi[maxt]->getigraci()[2]->getPrezime()<<endl;
        cout<<timovi[jednakot]->getigraci()[2]->getIme()<<" "<<timovi[jednakot]->getigraci()[2]->getPrezime()<<endl;
        cout<<"Ukucajte ime igraca kojem zelite da povecate korisnost"<<endl;
        cin>>unos;
        if(unos==timovi[jednakot]->getigraci()[2]->getIme()){
            Tehnicar* teh = new Tehnicar(timovi[jednakot]->getigraci()[2]->getIme(), timovi[jednakot]->getigraci()[2]->getPrezime(),timovi[jednakot]->getigraci()[2]->getGodine());
            teh->dizanje();
            return teh;
        }
        else if(unos==timovi[maxt]->getigraci()[2]->getIme()){
            Tehnicar* tehh= new Tehnicar(timovi[maxt]->getigraci()[2]->getIme(), timovi[maxt]->getigraci()[2]->getPrezime(),timovi[maxt]->getigraci()[2]->getGodine());
            tehh->dizanje();
            return tehh;
        }
    }
    return (Tehnicar*)timovi[maxt]->getigraci()[2];
}
SrednjiBloker* izaberisrednjaka(const Turnir &t)
{
    vector<int> srednjakkorisnost;
    vector<Tim*> timovi=t.getTimovi();
    unsigned int i;
    string unos;
    for(i=0; i<timovi.size() ; i++){
        srednjakkorisnost.push_back(timovi[i]->getigraci()[1]->getKorisnost());
    }
    int max=srednjakkorisnost[3], maxsb=0, jednako, jednakosb;
    for(unsigned int i=1; i<timovi.size(); i++)
    {
        if(srednjakkorisnost[i]>max)
        {
            max=srednjakkorisnost[i];
            maxsb=i;
        }
        if(srednjakkorisnost[i]==max){
            jednako=srednjakkorisnost[i];
            jednakosb=i;
        }
    }
    if(jednakosb!=maxsb && jednako==max){
        cout<<"Ova dva igraca imaju istu korisnost: "<< endl;
        cout<<timovi[maxsb]->getigraci()[3]->getIme()<<" "<<timovi[maxsb]->getigraci()[3]->getPrezime()<<endl;
        cout<<timovi[jednakosb]->getigraci()[3]->getIme()<<" "<<timovi[jednakosb]->getigraci()[3]->getPrezime()<<endl;
        cout<<"Ukucajte ime igraca kojem zelite da povecate korisnost"<<endl;
        cin>>unos;
        if(unos==timovi[jednakosb]->getigraci()[3]->getIme()){
            SrednjiBloker* sre = new SrednjiBloker(timovi[jednakosb]->getigraci()[3]->getIme(), timovi[jednakosb]->getigraci()[3]->getPrezime(),timovi[jednakosb]->getigraci()[3]->getGodine());
            sre->Blokiraj();
            return sre;
        }
        else if(unos==timovi[maxsb]->getigraci()[3]->getIme()){
            SrednjiBloker* sree = new SrednjiBloker(timovi[maxsb]->getigraci()[3]->getIme(), timovi[maxsb]->getigraci()[3]->getPrezime(),timovi[maxsb]->getigraci()[3]->getGodine());
            sree->Blokiraj();
            return sree;
        }
    }
    return (SrednjiBloker*)timovi[maxsb]->getigraci()[3];
}
Korektor* izaberikorektora(const Turnir &t)
{
    vector <int> korektorkorisnost;
    vector<Tim*> timovi=t.getTimovi();
    unsigned int i;
    string unos;
    for(i=0; i<timovi.size() ; i++){
        korektorkorisnost.push_back(timovi[i]->getigraci()[1]->getKorisnost());
    }
    int max=korektorkorisnost[4], maxk=0, jednako, jednakok;
    for(unsigned int i=1; i<timovi.size(); i++)
    {
        if(korektorkorisnost[i]>max)
        {
            max=korektorkorisnost[i];
            maxk=i;
        }
        if(korektorkorisnost[i]==max){
            jednako=korektorkorisnost[i];
            jednakok=i;
        }
    }
    if(jednakok!=maxk && jednako==max){
        cout<<"Ova dva igraca imaju istu korisnost: "<< endl;
        cout<<timovi[maxk]->getigraci()[4]->getIme()<<" "<<timovi[maxk]->getigraci()[4]->getPrezime()<<endl;
        cout<<timovi[jednakok]->getigraci()[4]->getIme()<<" "<<timovi[jednakok]->getigraci()[4]->getPrezime()<<endl;
        cout<<"Ukucajte ime igraca kojem zelite da povecate korisnost"<<endl;
        cin>>unos;
        if(unos==timovi[jednakok]->getigraci()[4]->getIme()){
            Korektor* kor = new Korektor(timovi[jednakok]->getigraci()[4]->getIme(), timovi[jednakok]->getigraci()[4]->getPrezime(),timovi[jednakok]->getigraci()[4]->getGodine());
            kor->PoentirajSmeck();
            return kor;
        }
        else if(unos==timovi[maxk]->getigraci()[4]->getIme()){
            Korektor* korr = new Korektor(timovi[maxk]->getigraci()[4]->getIme(), timovi[maxk]->getigraci()[4]->getPrezime(),timovi[maxk]->getigraci()[4]->getGodine());
            korr->PoentirajSmeck();
            return korr;
        }
    }
    return (Korektor*)timovi[maxk]->getigraci()[4];
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
