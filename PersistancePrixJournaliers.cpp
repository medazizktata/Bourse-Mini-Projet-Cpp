#include "PersistancePrixJournaliers.h"
#include "Date.h"
#include<vector>
#include<string>
#include<iostream>
#include<fstream>
using namespace std;

int main(){
    string filepath="prices_simple.csv";
    vector<PrixJournalier> historique = PersistancePrixJournaliers::lirePrixJournaliersDUnFichier(filepath);
    for (int i=0; i<20;i++){
        cout<<historique[i]<<endl;
    }
    return 0;
}
