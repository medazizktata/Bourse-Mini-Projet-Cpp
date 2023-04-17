#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

class Date {
    private:
        int jour;
        int mois;
        int annee;
    public:
        Date();
        Date(int j, int m, int a);
        ~Date();
        int get_jour();
        int get_mois();
        int get_annee();
        bool cntrl_jour(int j) const;
        bool cntrl_mois(int m)const;
        bool cntrl_annee(int a) const;
        bool cntrl_format() const;
        bool date_valide();
        void set_jour(int nv_jour);
        void set_mois(int nv_mois);
        void set_annee(int nv_annee);
        Date incrementer(Date &d);
        Date decrementer(Date &d);
        friend ostream& operator<<(ostream& os, const Date& d);
        friend istream& operator>>(istream& is, Date& d);
        bool operator<(const Date& d) const;
        friend Date operator+(Date& d, Date& f);
        bool operator==(const Date& d);
        Date& operator=(const Date& d);
        void saisie_date();

};
Date::Date(int j, int m, int a){
    jour=j;
    mois= m;
    annee=a;
}
Date::Date(){
    jour=0;
    mois=0;
    annee=2000;
}
Date::~Date(){}
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
    //os<<d.jour<<'/'<<d.mois<<'/'<<d.annee;
    //return os;
    
    if (d.jour < 10 || d.jour > 31) {
        os << setfill('0') << setw(2) << d.jour;
    } else {
        os << d.jour;
    }
    os << '/';
    if (d.mois < 10 || d.mois > 12) {
        os << setfill('0') << setw(2) << d.mois;
    } else {
        os << d.mois;
    }
    os << '/' << d.annee;
    return os;
}

istream& operator>>(istream& is, Date& d){
    /*char slash;
    is >> d.jour >> slash >> d.mois >> slash >> d.annee;*/
    string input;
    getline(is, input, '/');
    if (input[0] == '0') {
        d.jour =0; 
        stringstream ss(input.substr(1));

        ss >> d.jour;
    } else {
        d.jour = stoi(input);
    }
    getline(is, input, '/');
    if (input[0] == '0') {
        d.mois = stoi(input.substr(1));
    } else {
        d.mois = stoi(input);
    }
    getline(is, input);

    d.annee = stoi(input);
    
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
Date& Date:: operator=(const Date& d){
    if (this!=&d){
        jour=d.jour;
        mois=d.mois;
        annee=d.annee;
    }
    return *this;
}


#endif // DATE_H_INCLUDED
