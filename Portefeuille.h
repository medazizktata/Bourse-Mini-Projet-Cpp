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
    double solde;
    vector<Titre> actionspossed;
public:
    Portefeuille(double Soldedebut, vector<Titre> act={});
    ~Portefeuille();
    double Get_solde() const;
    vector<Titre> get_actions_possede();
    void Acheteraction(Titre t, double prix);
    void Vendreaction(Titre t, double prix);
};


#endif // PORTFEUIL_H_INCLUDED
