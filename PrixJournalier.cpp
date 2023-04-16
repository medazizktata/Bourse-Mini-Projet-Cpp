#include <iostream>
#include <string>
#include <cstring>
#include "Date.h"
#include "PrixJournalier.h"
using namespace std;

PrixJournalier::PrixJournalier(Date d, string na, double p){
    nom_action=na;
    prix=p;
    date=d;
}
string PrixJournalier:: get_nom_action(){
    return nom_action;
}
int PrixJournalier :: get_prix(){
    return prix;
}
Date PrixJournalier::get_date(){
    return date;
}
ostream& operator<<(ostream& os, const PrixJournalier& pj){
    cout<<pj.date<<" "<<pj.nom_action<<" "<<pj.prix<<endl;
    return os;
}
istream& operator>>(istream& is, PrixJournalier& pj){
    is>>pj.date>>pj.nom_action>>pj.prix;
    return is;
}
int main (){
    return 0;
}