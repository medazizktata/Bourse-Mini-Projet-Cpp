#ifndef PORTFEUIL_H_INCLUDED
#define PORTFEUIL_H_INCLUDED

#include <string>
#include <vector>
#include "Trader.h"
#include "PrixJournalier.h"
#include "Titre.h"



using namespace std;

class Portefeuille
{
private:
    double solde_initial, montant_restant, solde_total;
    vector<Titre> actionspossed;
public:
    Portefeuille(double Soldedebut, vector<Titre> act={});
    ~Portefeuille();
    double Get_solde_initial() const;
    double Get_montant_restant();
    double Get_solde_total();
    vector<Titre> get_actions_possede();
    void Setmontantrestant(double m);
    void Setsoldetotale(double m);
    void Acheteraction(Titre t, double prix);
    void Vendreaction(Titre t, double prix);
};


#endif // PORTFEUIL_H_INCLUDED
