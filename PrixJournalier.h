#ifndef PRIXJOURNALIER_H_INCLUDED
#define PRIXJOURNALIER_H_INCLUDED
#include <iostream>
#include <string>
#include <iomanip>
#include "Date.h"
#include "Date.cpp"
using namespace std;
class PrixJournalier {
    private:
        string nom_action;
        double prix;
        Date date;

    public:
        PrixJournalier();
        ~PrixJournalier();
        PrixJournalier(Date d, string na, double p);
        string get_nom_action();
        double get_prix();
        Date get_date();
        friend ostream& operator<<(ostream& os, const PrixJournalier& pj);
        friend istream& operator>>(istream& is, PrixJournalier& pj);
};
PrixJournalier::PrixJournalier(){
    Date d(1,1,2000);
    nom_action="XXX";
    prix=0;
    date= d;
}
PrixJournalier::~PrixJournalier(){}
PrixJournalier::PrixJournalier(Date d, string na, double p){
    nom_action=na;
    prix=p;
    date=d;
}
string PrixJournalier::get_nom_action(){
    return nom_action;
}
double PrixJournalier::get_prix(){
    return prix;
}
Date PrixJournalier::get_date(){
    return date;
}
ostream& operator<<(ostream& os, const PrixJournalier& pj){
    int dec = 0;
    string prix_str = to_string(pj.prix);
        size_t pos = prix_str.find(".");
        if (pos != string::npos) {
            dec = prix_str.size() - pos;
        }
    os<<pj.date<<" "<<pj.nom_action<<" "<<prix_str<<" "<<pos<<" "<<dec<<" "<< fixed << setprecision(dec) <<pj.prix<<endl;
    return os;
}
istream& operator>>(istream& is, PrixJournalier& pj){
    /*is >> pj.date >> pj.nom_action >> pj.prix;
    cout<<"Donner la date :";
    is>>pj.date;
    cout<<"Donner le nom de l'action : ";
    is>>pj.nom_action;
    cout<<"Donner le prix : ";
    is>>pj.prix;*/
   string line;
    if (getline(is, line)) {
        stringstream ss(line);
        string date_str;
        getline(ss, date_str, ';');
        Date date;
        stringstream(date_str)>>date;
        string nom_action;
        getline(ss, nom_action, ';');
        string prix_str;
        getline(ss, prix_str);
        long double prix = stod(prix_str);
        pj = PrixJournalier(date, nom_action, prix);
    }
    return is;
}
#endif