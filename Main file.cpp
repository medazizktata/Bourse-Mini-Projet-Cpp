#include <iostream>
#include <string>
using namespace std;
class Date {
    private:
        int jour;
        int mois;
        int annee;
    public:
        Date();
        Date(int j, int m, int a);
        int get_jour();
        int get_mois();
        int get_annee();
        Date incrementer(Date &d);
        Date decrementer(Date &d);
        friend ostream& operator<<(ostream& os, const Date& d);
        friend istream& operator>>(istream& os, Date& d);
        Date operator <(const Date& d);
        Date operator +(const Date& d);
        Date operator ==(const Date& d);
};
Date::Date(int j, int m, int a){
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
    string input;
    getline(is, input);
    char slash;
    is >> d.jour >> slash >> d.mois >> slash >> d.annee;
    return is;
}
int main(){
    Date d;
    cout<<"Entrer une date: (jj/mm/aaaa)";
    cin>>d;
    cout<<"La date est:"<<d;
    return 0;
}
