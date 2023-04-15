#include <iostream>
#include <string>
#include <cstring>
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
        Date incrementer(Date &d);
        Date decrementer(Date &d);
        friend ostream& operator<<(ostream& os, const Date& d);
        friend istream& operator>>(istream& os, Date& d);
        Date operator <(const Date& d);
        Date operator +(const Date& d);
        Date operator ==(const Date& d);
};
Date::Date(int j, int m, int a){
    int jour=j;
    int mois= m;
    int annee=a;
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

