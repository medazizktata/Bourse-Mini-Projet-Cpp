#include <iostream>
#include <string>
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
        Date incrementer(Date &d);
        Date decrementer(Date &d);
        friend ostream& operator<<(ostream& os, const Date& d);
        friend istream& operator>>(istream& os, Date& d);
        bool operator<(const Date& d) const;
        Date operator+(const Date& d);
        bool operator==(const Date& d);
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
int main(){
    Date d;
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
    cout<<"Le jour est:"<<d.get_jour()<<endl;
    cout<<"Le mois est:"<<d.get_mois()<<endl;
    cout<<"L'annee est:"<<d.get_annee()<<endl;
    cout<<"La date est:"<<d;
    return 0;
}