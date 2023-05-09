#include "portfeuil.h"

#include<vector>
#include <string>
#include "Trader.h"


using namespace std;

Portefeuille::Portefeuille(double Soldedebut)
{
    Solde_Initial=Soldedebut;
    Montant_Restant=Soldedebut;
    Solde_Totale=Soldedebut;
    vector<string> actionspossed;

}


Portefeuille::~Portefeuille(){};

double Portefeuille::Get_Solde_Initial() const
{
    return Solde_Initial;
}


double Portefeuille::Get_Montant_Restant(){
    return Montant_Restant;
}


double Portefeuille::Get_Solde_Totale(){
        return Solde_Totale;

}

void Portefeuille::SetMontantRestant(double m)
{
    Montant_Restant=m;
}
void Portefeuille::SetSoldeTotale(double m)
{
    Solde_Totale=m;
}
vector<string> Portefeuille::get_actions_possede(){
    return actionspossed;
}


void Portefeuille::Acheteraction(string nom,double prix){

    //il faut verifier si le montant restant est > au prix de l'action
    //n'oublier pas de modifier le solde restant et le montant totale

}
void Portefeuille::Vendreraction(string nom,double prix){

    //il faut afficher les actions posedé et choisir le quel on veut le vendre
    //n'oublier pas de modifier le solde restant et le montant totale
}
