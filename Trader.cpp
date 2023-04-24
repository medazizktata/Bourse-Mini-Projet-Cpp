#include <iostream>
#include <string>
#include <vector>
#include "Trader.h"
#include "BourseVector.h"
#include "Date.h"
#include "PrixJournalier.h"
using namespace std;

    Trader::Trader(){}
    void Trader::lancer_simulation(Date d, int c, double p ){
        

    }
    int Trader::prendre_decision(){}
    void Trader::acceder_a_archive_des_prix(){}


    Humain::Humain(){}
    void Humain::lancer_simulation(Date d, int n, double p){}
    int Humain::prendre_decision(){
        int c;
        do {
            cout<<"Menu : "<<endl;
            cout<<"1) Acheter une action "<<endl;
            cout<<"2) Vendre une action "<<endl;
            cout<<"3) Quitter "<<endl;
            cout<<"Choisir option : ";
            cin>> c;
        }while(c<0 || c>3);
        return c;
    }
    void Humain::acceder_a_archive_des_prix(Date d, int n, string nom){}
    