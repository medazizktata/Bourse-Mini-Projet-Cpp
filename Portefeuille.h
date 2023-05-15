#ifndef PORTFEUILLE_H_INCLUDED
#define PORTFEUILLE_H_INCLUDED
#include <string>
#include <vector>
#include "Trader.h"
#include "PrixJournalier.h"
#include "Titre.h"
#include "Bourse.h"

using namespace std;

class Portefeuille
{
private:
    double solde;
    vector<Titre> actionspossed;

public:
    Portefeuille(double Soldedebut, vector<Titre> act);
    double Get_solde() const;
    vector<Titre> get_actions_possede() const;
    void Alimenter_portefeuille(double somme);
    void Acheteraction(Titre t, double prix);
    void Vendreaction(Titre t, double prix);
    template <typename typebourse>
    void effectuerTransaction(typebourse &B, Transaction tt)
    {
        Titre tl = tt.GetTitre();
        string s = tt.GetstringTypeTransaction();
        if (s == "ACHAT")
        {
            Acheteraction(tl, B.get_prix_action_auj(tl.getNomAction())->get_prix());
        }
        else if (s == "VENTE")
        {
            Vendreaction(tl, B.get_prix_action_auj(tl.getNomAction())->get_prix());
        }

        else if (s == "RIEN")
        {
            return;
        }
    }
};

#endif // PORTFEUILLE_H_INCLUDED
