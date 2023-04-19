#include <iostream>
#include <string>

#include "Date.h"
#include "PrixJournalier.h"
using namespace std;

int main (){
    PrixJournalier p3, p4;
    string s="13/3/2020;efaehfbe;3242";
    
    cout<<"Action :";
    cin>>p3;
    cout<<"Date:"<<p3.get_date()<<endl;
    cout<<"Nom:"<<p3.get_nom_action()<<endl;
    cout<<"Prix:"<<p3.get_prix()<<endl;
    return 0;
}