#ifndef PORTFEUIL_H_INCLUDED
#define PORTFEUIL_H_INCLUDED

#include <string>
#include<vector>
#include "Trader.h"


using namespace std;

class Portefeuille
{
public:
    Portefeuille(double Soldedebut);
    ~Portefeuille();
    double Get_Solde_Initial() const;
    double Get_Montant_Restant();
    double Get_Solde_Totale();
    vector<string> get_actions_possede();
    void SetMontantRestant(double m);
    void SetSoldeTotale(double m);
    void Acheteraction(string nom,double prix);
    void Vendreraction(string nom,double prix);


private:

    double Solde_Initial,Montant_Restant,Solde_Totale;
    vector<string> actionspossed;

};


#endif // PORTFEUIL_H_INCLUDED
