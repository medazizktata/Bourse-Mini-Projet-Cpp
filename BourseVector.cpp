#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include "BourseVector.h"
#include "PersistancePrixJournaliers.h"
#include "PrixJournalier.h"

using namespace std;

BourseVector::BourseVector(const string& filepath){
    m_prixJournaliers = PersistancePrixJournaliers::lirePrixJournaliersDUnFichier(filepath);
}
vector<PrixJournalier> BourseVector::get_bourse(){
    return m_prixJournaliers;
}
vector<string> BourseVector::getActionsDisponiblesParDate(Date& d) const{
    vector<string> actionsDisponibles;
    bool found = false;
    for(auto compteur : m_prixJournaliers){
        if(compteur.get_date()== d){
            actionsDisponibles.push_back(compteur.get_nom_action());
        }
    }
    if (!found){
        actionsDisponibles.push_back("Match not found");
    }
    return actionsDisponibles;
}

/*vector<pair<string, double>> BourseVector::getPrixJournaliersParDate(const Date& date) const{
    vector<pair<string, double>> prixJournaliersParDate;
    bool found = false;
    for (auto compteur : m_prixJournaliers) {
        if (compteur.get_date() == date) {
            pair <string, double> p= make_pair(compteur.get_nom_action(),compteur.get_prix());
            prixJournaliersParDate.push_back(p);
            found=true;
        }
    }
    if(!found){ 
        pair<string, double> p = make_pair("unavailable", 0.0); // Create a pair with "unavailable" and 0.0
        prixJournaliersParDate.push_back(p); 
    }
    return prixJournaliersParDate;
}*/

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

PrixJournalier* BourseVector::getprix_action_date(Date d, string nom){
    PrixJournalier* resultat;
    bool found = false;
    for (auto compteur : m_prixJournaliers) {
        if (compteur.get_date() == d && compteur.get_nom_action()==nom) {
            *resultat=compteur;
            found=true;
        }
    }
    if(!found){ 
        resultat=NULL; 
    }
    return resultat;
}

bool compare_date(const pair<Date, double>& a, const pair<Date, double>& b) {
    return b.first < a.first;
}

void BourseVector::acces_archive(const Date d, int n, const string nom){

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
    
}


int main (){
    string filepath = "C://Users//zizou//OneDrive//Documents//GitHub//Bourse-Mini-Projet-C--//prices_simple.csv";
    
    BourseVector B(filepath);
    double k, j;
    Date d(24,1,2010);
    Date d1(4,1,2010);
    int i = 0;
    /*cout << "Actions disponibles pour le " << d << ":" << endl;
    for (auto ad : adispo) {
        i++;
        cout<<"Action "<<i<<" : "<<ad<<endl;
    }*/
    
    vector<string> pjdate = B.getActionsDisponiblesParDate(d);
    cout << "Prix journaliers pour le " << d << ":" << endl;
    for (auto pj : pjdate) {
        if (pj=="Match not found"){
            cout<< pj.first << " : " << pj.second << endl;
        }else {
            i++;
            cout <<"Action "<<i<<" : "<< pj.first << " : " << pj.second << endl;
        }
    }

    vector<pair<string, double>> pjdate1 = B.getPrixJournaliersParDate(d1);
    cout << "Prix journaliers pour le " << d1 << ":" << endl;
    for (auto pj : pjdate1) {
        if (pj==nulpair){
            cout<< pj.first << " : " << pj.second << endl;
        }else {
            i++;
            cout <<"Action "<<i<<" : "<< pj.first << " : " << pj.second << endl;
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

