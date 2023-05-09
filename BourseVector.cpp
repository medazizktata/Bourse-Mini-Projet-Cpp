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
BourseVector::~BourseVector(){cout<<"Bourse a ete detruite"<<endl;}
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

PrixJournalier* BourseVector::getprixjournalier(Date d, string nom) const{
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

double BourseVector::get_prix_action(const Date d, string nom) const{
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

string get_name_file(string &chemin){
    size_t lastSlashPos = chemin.find_last_of("/\\");
    if (lastSlashPos != string::npos) {
        return chemin.substr(lastSlashPos + 1);
    }
    return chemin;
}
void loading_screen(string s) {
    cout << "Lecture du fichier "<<get_name_file(s);
    cout.flush(); 
    for (int i = 0; i < 3; i++) {
        cout << ".";
        cout.flush();
    }
    cout << endl;
}

int main (){
    string filepath = "C://Users//zizou//OneDrive//Documents//GitHub//Bourse-Mini-Projet-C--//prices_simple.csv";
    loading_screen(filepath);
    BourseVector B(filepath);
    double k, j, l;
    /*Date d(28,02,2014); //490
    Date d1(05,11,2015); //498
    Date dd(29,02,2010); //0
    int ii = 0;
    vector<string> pjjddate = B.getActionsDisponiblesParDate(dd);
    cout << "Prix journaliers pour le " << dd << ":" << endl;
    for (string pjj : pjjddate) {
        double prr=B.get_prix_action(d, pjj);
        if (pjj=="Match not found"){
            cout<< pjj << endl;
        }else {
            ii++;
            cout <<"Action "<<ii<<" : "<< pjj<< " : " << prr << endl;
        }
    }
    cout<<'\n'<<endl;
    cout<<'\n'<<endl;
    int i = 0;
    vector<string> pjdate = B.getActionsDisponiblesParDate(d);
    cout << "Prix journaliers pour le " << d << ":" << endl;
    for (string pj : pjdate) {
        double pr=B.get_prix_action(d, pj);
        if (pj=="Match not found"){
            cout<< pj << endl;
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
    for (string pj1 : pjdate1) {
        double pr1=B.get_prix_action(d1, pj1);
        if (pj1=="Match not found"){
            cout<< pj1 << endl;
        }else {
            l++;
            cout <<"Action "<<l<<" : "<< pj1 << " : " << pr1 << endl;
        }
    }*/
    PrixJournalier* dp;
    Date dtp(21,03,2012);
    dp=B.getprixjournalier(dtp, "DLTR");//94.730003
    cout<<"Prix de l'action DLTR a la date "<<dtp<<" est : "<<*dp<< endl;
    
    
    PrixJournalier* dp1;
    Date dtp1(06,07,2010);
    dp1=B.getprixjournalier(dtp1, "DE");//54.630001
    cout<<"Prix de l'action DE a la date "<<dtp1<<" est : "<<*dp1<< endl;


    PrixJournalier* dp2;
    Date dtp2(8,12,2014);
    dp2=B.getprixjournalier(dtp2, "IR");//62.57
    cout<<"Prix de l'action DE a la date "<<dtp2<<" est : "<<*dp2<< endl;

    string s="IR";
    double ds=B.get_dernier_prix_action(s);
    cout<<"Dernier prix de "<<s<<" est : "<<ds<<endl; //30/12/2015
    cout<<'\n';


    string s1="FLIR";
    double ds1=B.get_dernier_prix_action(s1);
    cout<<"Dernier prix de "<<s1<<" est : "<<ds1<<endl; //30/12/2016
    cout<<'\n';


    Date d2(1,1,2015); //Not found
    B.acces_archive(d2,5,"IR");
    Date d3(6,3,2013);  //06/03/2013;IRM;34.810006
    B.acces_archive(d3,10,"IRM"); 
    Date d4(5,3,2014);
    B.acces_archive(d4,10,"KKKK"); //Not found

    j=B.get_prix_action(d3, "IRM"); //06/03/2013;IRM;34.810006

    cout<<"Recherche de l'action IR a la date "<<d2<<" : "<<k<<endl;
    cout<<'\n';
    cout<<"Recherche de l'action IRM a la date "<<d3<<" : "<<j<<endl;
    cout<<'\n';
    cout<<"Recherche de l'action KKK a la date "<<d4<<" : "<<l<<endl;
    cout<<'\n';

    return 0;
}

