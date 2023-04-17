#include "PersistancePrixJournaliers.h"
#include "Date.h"
#include "PrixJournalier.h"
#include<vector>
#include<string>
#include<iostream>
#include<fstream>
using namespace std;

int main(){
    string filepath = "C://Users//zizou//OneDrive//Documents//GitHub//Bourse-Mini-Projet-C--//prices_simple.csv";
    vector<PrixJournalier> historique = PersistancePrixJournaliers::lirePrixJournaliersDUnFichier(filepath);
    ifstream f(filepath);
    if (!f.is_open()) {
        cerr << "Failed to open file: " << filepath << endl;
    }
    else {
        cerr<< "Opened Succefullly"<<endl;
    }
    cout << "Number of records read: " << historique.size() << endl;

    /*for (auto pj : historique) {
        cout << pj <<endl;
    }*/
    return 0;
}