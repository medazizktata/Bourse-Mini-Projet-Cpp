#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
#include <iostream>
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

#endif 
