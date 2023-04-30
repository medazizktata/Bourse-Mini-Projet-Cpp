#define _GLIBCXX_USE_CXX11_ABI 1
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <chrono>
#include <thread>
#include "BourseVector.h"
#include "PersistancePrixJournaliers.h"
#include "PrixJournalier.h"

using namespace std;

BourseVector::BourseVector(const string& filepath){
    m_prixJournaliers = PersistancePrixJournaliers::lirePrixJournaliersDUnFichier(filepath);
}
BourseVector::~BourseVector(){}
vector<PrixJournalier> BourseVector::get_bourse(){
    return m_prixJournaliers;
}


/*void BourseVector::acces_archive(const Date d, int n, const string nom){
    bool compare_date(const pair<Date, double>& a, const pair<Date, double>& b) {
        return b.first < a.first;
    };
    vector<PrixJournalier>::iterator c;
    vector<pair<Date, double>> getaction_dates;
    int i=0;
    for (c = m_prixJournaliers.begin(); c<m_prixJournaliers.end(); ++c){
        if (c->get_nom_action()==nom && c->get_date()<d){
            pair<Date, double> cp=make_pair(c->get_date(),c->get_prix());
            getaction_dates.push_back(cp);
            i++;
        }
        if (i==n){
            break;
        }
    }
    if (getaction_dates.size() == 0) {
        cout << "Action "<<nom<<" pas trouvee avant le "<<d<<endl;
    } else {
        sort(getaction_dates.begin(), getaction_dates.end(), compare_date);
        cout<<"Nom de l'action : "<<nom<<endl;
        cout<<"Date limite de recherche : "<<d<<endl;
        cout<<"Nombre d'actions trouvees : "<<i<<endl;
        for (auto j : getaction_dates){
            cout<<"Date :"<<j.first;
            cout<<" "<<"Prix : "<<j.second<<endl;
        }
    }
    
}*/

bool compare_date(PrixJournalier a, PrixJournalier b){
    return (a.get_date() < b.get_date());
}; 

void BourseVector::acces_archive(const Date d, int n, const string nom){
    vector<PrixJournalier> getaction_dates;
    int i=0;
    for (PrixJournalier& c: m_prixJournaliers){
        if (c.get_nom_action()==nom && c.get_date()<d){
            getaction_dates.push_back(c);
            i++;
        }
        if (i == n) {
            break;
        }
    }
    if (getaction_dates.size() == 0) {
        cout << "Action "<<nom<<" pas trouvee avant le "<<d<<endl;
    } else {
        sort(getaction_dates.begin(), getaction_dates.end(), compare_date);
        cout<<"Nom de l'action : "<<nom<<endl;
        cout<<"Date limite de recherche : "<<d<<endl;
        cout<<"Nombre d'actions trouvees : "<<i<<endl;
        for (auto j : getaction_dates){
            cout<<"Date :"<<j.get_date();
            cout<<" "<<"Prix : "<<j.get_prix()<<endl;
        }
    }
    
}

PrixJournalier* BourseVector::getprix_action_date(Date d, string nom) const{
    PrixJournalier* resultat=nullptr;
    for (auto compteur : m_prixJournaliers) {
        if (compteur.get_date() == d && compteur.get_nom_action()==nom) {
            resultat = new PrixJournalier(compteur);
            break;
        }
    }
    return resultat;
}


double BourseVector::get_dernier_prix_action(string nom) const{
    double prixaction=0.0;
    for (auto compteur : m_prixJournaliers) {
        if (compteur.get_nom_action()==nom) {
            prixaction=compteur.get_prix();
        }
    }
    return prixaction;
}


vector<string> BourseVector::getActionsDisponiblesParDate(Date& d) const{
    vector<string> actionsDisponibles;
    bool found = false;
    for(auto compteur : m_prixJournaliers){
        if(compteur.get_date()== d){
            actionsDisponibles.push_back(compteur.get_nom_action());
            found=true;
        }
    }
    if (!found){
        actionsDisponibles.push_back("Match not found");
    }
    return actionsDisponibles;
}

double BourseVector::get_prix_action(const Date d, string nom){
    double prix;
    bool found = false;
    for (auto compteur : m_prixJournaliers) {
        if (compteur.get_date() == d && compteur.get_nom_action()==nom) {
            prix=compteur.get_prix();
            found=true;
        }
    }
    if(!found){ 
        prix=0.0; 
    }
    return prix;
}

int main (){
    string filepath = "C://Users//zizou//OneDrive//Documents//GitHub//Bourse-Mini-Projet-C--//prices_simple.csv";
    BourseVector B(filepath);
    double k, j;
    Date d(24,1,2011);
    Date d1(4,1,2010);
    int i = 0;
    vector<string> pjdate = B.getActionsDisponiblesParDate(d);
    cout << "Prix journaliers pour le " << d << ":" << endl;
    for (string pj : pjdate) {
        double pr=B.get_prix_action(d, pj);
        if (pj=="Match not found"){
            cout<< pj << " : " << pr << endl;
        }else {
            i++;
            cout <<"Action "<<i<<" : "<< pj<< " : " << pr << endl;
        }
    }
    cout<<'\n'<<endl;
    cout<<'\n'<<endl;
    int l=0;
    vector<string> pjdate1 = B.getActionsDisponiblesParDate(d1);
    cout << "Prix journaliers pour le " << d1 << ":" << endl;
    for (string pj1 : pjdate) {
        double pr1=B.get_prix_action(d1, pj1);
        if (pj1=="Match not found"){
            cout<< pj1 << " : " << pr1 << endl;
        }else {
            l++;
            cout <<"Action "<<l<<" : "<< pj1 << " : " << pr1 << endl;
        }
    }
    Date d2(1,1,2015);
    B.acces_archive(d2,5,"IR");
    Date d3(6,3,2013);
    B.acces_archive(d3,10,"IRM");
    Date d4(5,3,2014);
    B.acces_archive(d4,10,"KKKK");
    k=B.get_prix_action(d2, "IR");
    j=B.get_prix_action(d3, "IRM");
    cout<<"Recherche de l'action IR a la date "<<d2<<" : "<<k<<endl;
    cout<<"Recherche de l'action IRM a la date "<<d3<<" : "<<j<<endl;

    return 0;
}

