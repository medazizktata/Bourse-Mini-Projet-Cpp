#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Trader.h"
#include "Bourse.h"
#include "BourseVector.h"
#include "Date.h"
#include "PrixJournalier.h"
#include "Portefeuille.h"
#include "Transaction.h"
#include "Titre.h"
using namespace std;
Trader::Trader() {}

string Trader::get_nom_trader()
{
    return nom_tr;
}

Transaction Trader_aleatoire::choisir_transaction(const Bourse &B, const Portefeuille &P)
{
    PrixJournalier *pj;
    Date d = B.get_auj();
    TypeTransaction type;
    Titre actionqut;
    vector<Titre> actions_achetes = P.get_actions_possede();
    vector<string> nom_actions = B.getActionsDisponiblesParDate(d);
    if (actions_achetes.empty())
    {
        type = ACHAT;
    }

    if (nom_actions.size() == 0)
    {
        type = RIEN; // Bourse fermée
    }
    else
    {
        type = static_cast<TypeTransaction>(rand() % 3);
    }
    if (type == RIEN)
    {
        actionqut.setNomAction(" ");
        actionqut.setQte(0);
        Transaction t(type, actionqut);
        return t;
    }
    else if (type == VENTE)
    {
        // choisir action aleatoire de portefuille
        // choisir quantite aleatoire de la quantite possedée
        srand(time(NULL));
        int index_alea = rand() % actions_achetes.size();
        // choisir quantite aleatoire (quantite * prix < solde)
        int c = actions_achetes[index_alea].getQte();
        int qut_alea = rand() % c;
        actionqut.setQte(qut_alea);
        actionqut.setNomAction(actions_achetes[index_alea].getNomAction());
        Transaction t(type, actionqut);
        return t;
    }
    else if (type == ACHAT)
    {
        // choisir action aleatoire mel bourse (prix 1Q < solde)

        srand(time(NULL));
        do
        {
            int index_alea = rand() % nom_actions.size();
            pj = B.get_prix_action_auj(nom_actions[index_alea]);
            pj->set_nom_action(nom_actions[index_alea]);

        } while (pj->get_prix() > P.Get_solde());
        actionqut.setNomAction(pj->get_nom_action());
        // choisir quantite aleatoire (quantite * prix < solde)
        int i = 0;
        do
        {
            i++;
        } while (pj->get_prix() * i < P.Get_solde());
        int qut_alea = rand() % i;
        actionqut.setQte(qut_alea);
        Transaction t(type, actionqut);
        return t;
    }
}