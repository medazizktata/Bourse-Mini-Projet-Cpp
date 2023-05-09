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
        void set_date(Date d);
        void set_nom_action(string nom);
        void set_prix(double p);
        friend ostream& operator<<(ostream& os, const PrixJournalier& pj);
        friend istream& operator>>(istream& is, PrixJournalier& pj);
};
PrixJournalier::PrixJournalier(){
    Date d(4,1,2010);
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
void PrixJournalier::set_date(Date d){
    date=d;
}
void PrixJournalier::set_nom_action(string nom){
    nom_action=nom;
}
void PrixJournalier::set_prix(double p){
    prix=p;
}
ostream& operator<<(ostream& os, const PrixJournalier& pj){
    int dec = 0;
    string prix_str = to_string(pj.prix);
        size_t pos = prix_str.find(".");
        if (pos != string::npos) {
            dec = prix_str.size() - pos;
            os<<pj.date<<" "<<pj.nom_action<<" "<< fixed << setprecision(dec) <<pj.prix<<endl;
        } 
        if (pos==0){
            os<<pj.date<<" "<<pj.nom_action<<" "<<pj.prix<<endl;
        }
    
    return os;
}
bool is_float(const string& str) {
    bool has_dot = false;
    for (char c : str) {
        if (!std::isdigit(c)) {
            if (c == '.' && !has_dot) {
                has_dot = true;
            } else {
                return false;
            }
        }
    }
    return has_dot;
}

istream& operator>>(istream& is, PrixJournalier& pj){
    string input;
    getline(is, input, ';');
    stringstream ss(input);
    ss >> pj.date;
    getline(is, pj.nom_action, ';');
    getline(is, input);
    
    if (!pj.date.date_valide() && !is_float(input) ){
        cerr << "Format incorrect. Veuillez re-entrer un prix et une date valide sous le format suivant (jj/mm/aaaa): ";
        is>>pj;
        return is;
    }
    if (!is_float(input)){
        cerr << "Format incorrect. Veuillez re-entrer un prix valide: ";
        is>>pj;
        return is;
    }
    pj.prix = stod(input);
    if (!pj.date.date_valide()){
        cerr << "Format incorrect. Veuillez re-entrer une date valide sous le format suivant (jj/mm/aaaa): ";
        is>>pj;
        return is;
    }
    return is;
}
#endif
