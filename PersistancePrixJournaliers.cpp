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


    /*for (auto pj : historique) {
        cout << pj <<endl;
    }*/
    return 0;
}