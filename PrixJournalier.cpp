#include <iostream>
#include <string>
#include "Date.h"
#include "PrixJournalier.h"
using namespace std;
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
    os<<pj.date<<" "<<pj.nom_action<<" "<<pj.prix<<endl;
    return os;
}
istream& operator>>(istream& is, PrixJournalier& pj){
    is >> pj.date >> pj.nom_action >> pj.prix;
    return is;
}
int main (){
    Date d(1,6,2022);
    Date d1(10,12,2014);
    PrixJournalier p(d, "ETH", 50);
    PrixJournalier p1(d1, "BTC", 1000);
    cout<<p<<endl;
    cout<<p1<<endl;
    return 0;
}