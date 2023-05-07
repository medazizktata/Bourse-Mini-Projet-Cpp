#include <iostream>
#include <string>
#include "Trader.h"
#include "Portefeuille.h"
#include "PrixJournalier.h"
#include "Titre.h"
using namespace std;

Portefeuille::Portefeuille(double soldedebut, vector<Titre> act={}){
    solde_initial=soldedebut;
    actionspossed=act;
}
double Portefeuille::Get_solde_initial() const {
    return solde_initial;
}
double Portefeuille::Get_montant_restant(){
    return montant_restant;
}
double Portefeuille::Get_solde_total(){
    return solde_total;
}
vector<Titre> Portefeuille::get_actions_possede(){
    return actionspossed;
}
void Portefeuille::Setmontantrestant(double m){
    montant_restant=m;
}
void Portefeuille::Setsoldetotale(double m){
    solde_total=m;
}
void Portefeuille::Acheteraction(string nom,double prix){
    if (solde_initial<prix) {
        cout<<"Solde insuffisant pour effectuer cette transaction"<<endl;
    }
    else {
        actionspossed.push_back(nom);
        solde_initial-=prix;
    }
}
void Portefeuille::Vendreaction(string nom,double prix){
    int i=0;
    while(i<actionspossed.size() && actionspossed[i]!=nom){
        i++;
    }
    if (i<actionspossed.size()){
        actionspossed.erase(actionspossed.begin()+i);
        solde_initial-=prix;
    } else {
        cout<<"Action introuvable"<<endl;
    }
    
    
    
}