#include <iostream>
#include <string>
#include "Trader.h"
#include "Portefeuille.h"
#include "PrixJournalier.h"
#include "Titre.h"
using namespace std;

Portefeuille::Portefeuille(double soldedebut = 0, vector<Titre> act = {})
{
    solde = soldedebut;
    actionspossed = act;
}
double Portefeuille::Get_solde() const
{
    return solde;
}

void Portefeuille::Alimenter_portefeuille(double somme)
{
    solde += somme;
}

vector<Titre> Portefeuille::get_actions_possede() const
{
    return actionspossed;
}

void Portefeuille::Acheteraction(Titre t, double prix)
{
    unsigned int i = 0;
    if (solde < prix * t.getQte())
    {
        cout << "Solde insuffisant pour effectuer cette transaction" << endl;
        cout << "Achat echoue" << endl;
    }
    else
    {
        while (i < actionspossed.size())
        {
            if (actionspossed[i].getNomAction() == t.getNomAction())
            {
                actionspossed[i].ajouterQte(t.getQte());
                break;
            }
            i++;
        }
        if (i >= actionspossed.size())
        {
            actionspossed.push_back(t); // Nouvelle action possedee
        }
        solde -= prix * t.getQte();
        cout << "\nAchat effectue avec Suceess  " << endl;
        cout << "Solde mis a jour apres ACHAT : " << solde << endl;
    }
}
void Portefeuille::Vendreaction(Titre t, double prix)
{
    unsigned int i = 0;
    while (i < actionspossed.size())
    {
        if (actionspossed[i].getNomAction() == t.getNomAction())
        {
            if (actionspossed[i].getQte() == t.getQte())
            {
                actionspossed.erase(actionspossed.begin() + i);
            }
            else
            {
                actionspossed[i].retirerQte(t.getQte());
            }
            break;
        }
        i++;
    }
    solde += prix * t.getQte();
    cout << "\nVente effectuee avec Suceess  " << endl;
    cout << "Solde mis a jour apres VENTE : " << solde << endl;
    if (i >= actionspossed.size())
    {
        cout << "\nVente echouee" << endl;
    }
}