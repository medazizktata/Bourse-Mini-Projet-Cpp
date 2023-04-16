#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Date {
    private:
        int jour;
        int mois;
        int annee;
    public:
        Date(int j, int m, int a);
        int get_jour();
        int get_mois();
        int get_annee();
        bool cntrl_jour(int j) const;
        bool cntrl_mois(int m)const;
        bool cntrl_annee(int a) const;
        bool cntrl_format() const;
        void set_jour(int nv_jour);
        void set_mois(int nv_mois);
        void set_annee(int nv_annee);
        Date incrementer(Date &d);
        Date decrementer(Date &d);
        friend ostream& operator<<(ostream& os, const Date& d);
        friend istream& operator>>(istream& os, Date& d);
        bool operator<(const Date& d) const;
        Date operator+(const Date& d);
        bool operator==(const Date& d);
        void saisie_date(const Date d);

};
Date::Date(int j=0, int m=0, int a=0){
    jour=j;
    mois= m;
    annee=a;
}
int Date::get_jour(){
    return jour;
}
int Date::get_mois(){
    return mois;
}
int Date::get_annee(){
    return annee;
}
ostream& operator<<(ostream& os, const Date& d){
    os<<d.jour<<'/'<<d.mois<<'/'<<d.annee;
    return os;
}
istream& operator>>(istream& is, Date& d){
    char slash;
    is >> d.jour >> slash >> d.mois >> slash >> d.annee;
    return is;
}
bool Date::operator==(const Date& d){
    return ((jour== d.jour) && (mois==d.mois) && (annee==d.annee));
}
bool Date::operator<(const Date& d)const{
    if(annee!=d.annee){
        return annee<d.annee;
    }
    else if (mois!=d.mois){
        return mois<d.mois;
    }
    else {
        return jour<d.jour;
    }
}
bool Date::cntrl_jour(int j) const{
   return (j<=31 && j>0);
}
bool Date::cntrl_mois(int m) const{
    return (m<=12 && m>0);
}
bool Date::cntrl_annee(int a) const{
    return (a<=2023 && a>2000);
}
bool Date::cntrl_format() const{
    return ((cntrl_jour(jour)) && (cntrl_mois(mois)) && (cntrl_annee(annee)));
}
void Date::set_jour(int nv_jour){
    if(cntrl_jour(nv_jour)){
        jour=nv_jour;
    }
}
void Date::set_mois(int nv_mois){
    if(cntrl_mois(nv_mois)){
        mois=nv_mois;
    }
}
void Date::set_annee(int nv_annee){
    if(cntrl_annee(nv_annee)){
        annee=nv_annee;
    }
}
bool annee_bissextile(int annee) {
    if (annee % 4 == 0) {
        if (annee % 100 == 0) {
            if (annee % 400 == 0) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return true;
        }
    }
    else {
        return false;
    }
}

Date decrementer(Date &d){
    int jour=d.get_jour();
    int mois=d.get_mois();
    int annee=d.get_annee();
    int fev=28;
    if (mois >1 && mois<8){
        if ((mois-1)%2==0){
            if ((mois-1)!=2){
                if(jour>1){
                    --jour;
                }
                else {
                    jour=30;
                    --mois;
                }
            }
            if ((mois-1)==2){
                if (annee_bissextile(annee)){
                    fev=29;
                }
                if(jour>1){
                    --jour;
                }
                else {
                    jour=fev;
                    --mois;
                }
            }
        }
        else {
            if(jour>1){
                    --jour;
                }
                else {
                    jour=31;
                    --mois;
                }
        }
    }
    if (mois==1) {
        if(jour>1){
            --jour;
        }
        else {
           jour=31;
            mois=12;
            --annee;
        }
    }
    if (mois>=8) {
        if ((mois-1)%2==0){
            if(jour>1){
                --jour;
            }
            else {
                jour=31;
                --mois;
            }
        }
        else {
            if(jour==1){        
                jour=30;        
                --mois;         
            }                  
            else{                
                --jour;         
            }                   
        }
    }
    
    d.set_jour(jour);
    d.set_mois(mois);
    d.set_annee(annee);
    return d;
}
Date incrementer(Date &d){
    int jour=d.get_jour();
    int mois=d.get_mois();
    int annee=d.get_annee();
    int fev=28;
    if (mois<8){
        if (mois%2==0){
            if (mois!=2){
                if(jour<30){
                    ++jour;
                }
                else {
                    jour=1;
                    ++mois;
                }
            }
            if (mois==2){
                if (annee_bissextile(annee)){
                    fev=29;
                }
                if(jour<fev){
                    ++jour;
                }
                else {
                    jour=1;
                    ++mois;
                }
            }
        }
        else {
            if(jour<31){
                    ++jour;
                }
                else {
                    jour=1;
                    ++mois;
                }
        }
    }
    if (mois==12) {
        if(jour<31){
            ++jour;
        }
        else {
           jour=1;
            mois=1;
            ++annee;
        }
    }
    if ((mois>=8) && (mois<12)) {
        if (mois%2==0){
            if(jour<31){
                ++jour;
            }
            else {
                jour=1;
                ++mois;
            }
        }
        else {
            if(jour==30){
                ++mois; 
                jour=1;
                         /////// A CONSULTER
            }
            else{
                ++jour;
            }
        }
    }
    
    d.set_jour(jour);
    d.set_mois(mois);
    d.set_annee(annee);
    return d;
}
void Date::saisie_date(Date d){
    bool date_valide=false;
    int c=0;
    cout<<"Entrer une date sous le format suivant (jj/mm/aaaa) : ";
    while (!date_valide){
        cin>>d;
        if (d.cntrl_format()){
            date_valide=true;
        }
        else {
            c++;
            cout<<"Format incorrect"<<endl;
            cout<<"Veuillez re-entrer une date valide sous le format suivant (jj/mm/aaaa) : ";
        }
    }
    if (c!=0){
        cout<<"Format Valide"<<endl;
    }
    
}
int main(){
    vector <Date> tableau;
    vector <string> description;
    int i;
    Date d1(1,3,2022); //date valide
    string s1="date valide";
    /*Date d2(32,5,2018); //jour invalide
    string s2="jour invalide";
    Date d3(4,15,2006); //mois invalide
    string s3="mois invalide";
    Date d4(9,8,3090); //annee invalide
    string s4="annee invalide";*/
    Date d5(9,5,2021); //(mois<8)jour++
    string s5="(mois<8)jour++";
    Date d5_1(7,9,2012); //(mois>8)jour++
    string s5_1="(mois>8)jour++";
    Date d6(31,3,2014); //(mois<8)mois31++
    string s6="(mois<8)mois31++";
    Date d6_1(31,10,2023); //(mois<8)mois31++
    string s6_1="(mois<8)mois31++";
    Date d7(30,6,2016); //(mois<8)mois30++
    string s7="(mois<8)mois30++";
    Date d7_1(30,11,2011); //(mois>8)mois30++
    string s7_1="(mois>8)mois30++";
    Date d8(30,8,2010); //aout++
    string s8="aout1++";
    Date d8_1(31,8,2010); //aout++
    string s8_1="aout2++";
    Date d9(31,12,2017); //annee++
    string s9="annee++";
    Date d10(28,2,2000); //anneebisexitile1ON
    string s10="anneebisexitile1ON";
    Date d10_1(29,2,2020); //anneebisexitile2ON
    string s10_1="anneebisexitile2ON";
    Date d11(28,2,2019); //anneebisexitileOFF
    string s11="anneebisexitileOFF";
    tableau.push_back(d1);
    /*tableau.push_back(d2);
    tableau.push_back(d3);
    tableau.push_back(d4);*/
    tableau.push_back(d5);
    tableau.push_back(d5_1);
    tableau.push_back(d6);
    tableau.push_back(d6_1);
    tableau.push_back(d7);
    tableau.push_back(d7_1);
    tableau.push_back(d8);
    tableau.push_back(d8_1);
    tableau.push_back(d9);
    tableau.push_back(d10);
    tableau.push_back(d10_1);
    tableau.push_back(d11);
    description.push_back(s1);
    /*description.push_back(s2);
    description.push_back(s3);
    description.push_back(s4);*/
    description.push_back(s5);
    description.push_back(s5_1);
    description.push_back(s6);
    description.push_back(s6_1);
    description.push_back(s7);
    description.push_back(s7_1);
    description.push_back(s8);
    description.push_back(s8_1);
    description.push_back(s9);
    description.push_back(s10);
    description.push_back(s10_1);
    description.push_back(s11);

    for (i=0; i<13; i++){
        cout<<"La date avant modif est:"<<tableau[i]<<endl;
        cout<<"Incrementation: "<<description[i]<<": "<<endl;
        tableau[i]=incrementer(tableau[i]);
        cout<<"La date incrementee est:"<<tableau[i]<<endl;
        tableau[i]=decrementer(tableau[i]);
        cout<<"La date decrementee est:"<<tableau[i]<<endl;
        cout<<'\n'<<endl;
    }

    /*cout<<"Le jour est:"<<d1.get_jour()<<endl;
    cout<<"Le mois est:"<<d1.get_mois()<<endl;
    cout<<"L'annee est:"<<d1.get_annee()<<endl;*/
    return 0;
}