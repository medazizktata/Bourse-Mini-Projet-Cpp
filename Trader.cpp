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
    PrixJournalier* pj;
    string nom;
    Date d = B.get_auj();
    TypeTransaction type;
    Titre actionqut;
    vector<Titre> actions_achetes = P.get_actions_possede();
    if (actions_achetes.empty())
    {
        type = ACHAT;
    }
}
    if (/* pas de titres*/)
    {
        type = RIEN;
    }
    else
    {
        type = static_cast<TypeTransaction>(rand() % 3);
    }
    if (type == RIEN)
    {
        actionqut.getNomAction() ="";
        Transaction t(type, actionqut);
        return t;
    }
    else if (type == VENTE)
    {
        // choisir action aleatoire de portefuille
        // choisir quantite aleatoire de la quantite possedée
        Transaction t(type, actionqut);
        return t;
    }
    else if (type == ACHAT)
    {
        // choisir action aleatoire mel bourse (prix 1Q < solde)
        vector<string> nom_actions = B.getActionsDisponiblesParDate(d);
        srand(time(NULL));
        int index_alea = rand() % nom_actions.size();
        pj=B.getprixjournalier(d, nom_actions[index_alea]);
        if(pj->get_prix()<P.Get_solde()){
            pj->set_nom_action(nom_actions[index_alea]);
            actionqut.setNomAction(pj->get_nom_action()) ;
        }
        //choisir quantite aleatoire (quantite * prix < solde)
        int i=0;
        do {
            i++;
        }while(pj->get_prix()*i<P.Get_solde());
        int qut_alea = rand() % i;
        actionqut.ajouterQte(qut_alea);
        Transaction t(type, actionqut);
        return t;
    }

    
}