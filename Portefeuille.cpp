#include <iostream>
#include <string>
#include "Trader.h"
#include "Portefeuille.h"
#include "PrixJournalier.h"
#include "Titre.h"
using namespace std;

Portefeuille::Portefeuille(double soldedebut, vector<Titre> act = {})
{
    solde = soldedebut;
    actionspossed = act;
}
double Portefeuille::Get_solde() const
{
    return solde;
}

vector<Titre> Portefeuille::get_actions_possede()
{
    return actionspossed;
}

void Portefeuille::Acheteraction(Titre t, double prix)
{
    int i = 0;
    if (solde < prix * t.getQte())
    {
        cout << "Solde insuffisant pour effectuer cette transaction" << endl;
    }
    else
    {
        while (i < actionspossed.size() && actionspossed[i].getNomAction() != t.getNomAction())
        {
            i++;
        }
        if (i < actionspossed.size())
        {
            actionspossed[i].ajouterQte(t.getQte());
        }
        else
        {
            actionspossed.push_back(t);
        }
        solde -= prix * t.getQte();
    }
}
void Portefeuille::Vendreaction(Titre t, double prix)
{
    int i = 0;
    while (i < actionspossed.size() && actionspossed[i].getNomAction() != t.getNomAction())
    {
        i++;
    }
    if ((i < actionspossed.size())){
        if(actionspossed[i].getQte()==t.getQte()){
            actionspossed.erase(actionspossed.begin() + i);
        }
        else {
            actionspossed[i].retirerQte(t.getQte());
        }
        solde += prix * t.getQte();
    }
    else {
        cout<<"Action echouée"<<endl;
    }
}