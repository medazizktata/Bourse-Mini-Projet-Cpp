#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <set>
#include <map>
#include "Trader.h"
#include "Bourse.h"
#include "BourseVector.h"
#include "BourseSet.h"
#include "BourseMultimap.h"
#include "PrixJournalier.h"
#include "Portefeuille.h"
#include "Transaction.h"
#include "Titre.h"
using namespace std;

template <typename typebourse>

Transaction Trader_aleatoire<typebourse>::choisir_transaction(const typebourse &B, const Portefeuille &P)
{
    int hard_limit = 500;
    PrixJournalier *pj;
    Date d = B.get_auj();
    TypeTransaction type;
    Titre actionqut;
    vector<Titre> actions_achetes = P.get_actions_possede();
    auto nom_actions = B.getActionsDisponiblesParDate(d);
    string s = Transaction::TypeTostring(type);
    if (nom_actions.size() == 0)
    {
        s = "RIEN"; // Bourse fermée
        type = RIEN;
    }
    else if (actions_achetes.empty())
    {
        s = "ACHAT";
        type = ACHAT;
    }
    else
    {
        type = static_cast<TypeTransaction>(rand() % 3);
        s = Transaction::TypeTostring(type);
    }
switch_to_vente:
    if (s == "RIEN")
    {
        type = RIEN;
        actionqut.setNomAction("");
        actionqut.setQte(0);
        Transaction t(type, actionqut);
        return t;
    }
    else if (s == "VENTE")
    {
        type = VENTE;
        // choisir action aleatoire de portefuille
        // choisir quantite aleatoire de la quantite possedée
        srand(time(NULL));
        int index_alea = rand() % actions_achetes.size();
        // choisir quantite aleatoire (quantite * prix < solde)
        int c = actions_achetes[index_alea].getQte();

        int qut_alea;

        if (c == 1)
        {
            qut_alea = c;
        }
        else
        {
            qut_alea = rand() % c;
            while (qut_alea == 0)
            {
                qut_alea = rand() % c;
            }
        }
        actionqut.setQte(qut_alea);
        actionqut.setNomAction(actions_achetes[index_alea].getNomAction());

        Transaction t(type, actionqut);
        return t;
    }
    else if (s == "ACHAT")
    {
        type = ACHAT;
        // choisir action aleatoire mel bourse (prix 1Q < solde)
        srand(time(NULL));
        int ct = 0;
        do
        {
            int index_alea;
            index_alea = rand() % nom_actions.size();
            pj = B.get_prix_action_auj(nom_actions[index_alea]);
            pj->set_nom_action(nom_actions[index_alea]);
            ct++;
        } while (pj->get_prix() > P.Get_solde() && ct < hard_limit);
        if (ct == hard_limit)
        {
            s = "VENTE";
            type = VENTE;
            cout << "Limite de recherche depassee : " << s << endl;
            cout << "Switching to : " << s << endl;
            goto switch_to_vente;
        }
        actionqut.setNomAction(pj->get_nom_action());
        // choisir quantite aleatoire (quantite * prix < solde)
        int q = P.Get_solde() / pj->get_prix();
        int qut_alea;
        if (q == 1)
        {
            qut_alea = q;
        }
        else
        {
            qut_alea = rand() % q;
            while (qut_alea == 0)
            {
                qut_alea = rand() % q;
            }
        }

        actionqut.setQte(qut_alea);
        Transaction t(type, actionqut);
        return t;
    }
    else
    {
        Transaction t(type, actionqut);
        return t;
    }
}

template <>

Transaction Trader_aleatoire<BourseSet>::choisir_transaction(const BourseSet &B, const Portefeuille &P)
{
    int hard_limit = 500;
    PrixJournalier *pj;
    Date d = B.get_auj();
    TypeTransaction type;
    Titre actionqut;
    vector<Titre> actions_achetes = P.get_actions_possede();
    auto nom_actions = B.getActionsDisponiblesParDate(d);
    string s = Transaction::TypeTostring(type);
    if (nom_actions.size() == 0)
    {
        s = "RIEN"; // Bourse fermée
        type = RIEN;
    }
    else if (actions_achetes.empty())
    {
        s = "ACHAT";
        type = ACHAT;
    }
    else
    {
        type = static_cast<TypeTransaction>(rand() % 3);
        s = Transaction::TypeTostring(type);
    }
switch_to_vente:
    if (s == "RIEN")
    {
        type = RIEN;
        actionqut.setNomAction("");
        actionqut.setQte(0);
        Transaction t(type, actionqut);
        return t;
    }
    else if (s == "VENTE")
    {
        type = VENTE;
        // choisir action aleatoire de portefuille
        // choisir quantite aleatoire de la quantite possedée
        srand(time(NULL));
        int index_alea = rand() % actions_achetes.size();
        // choisir quantite aleatoire (quantite * prix < solde)
        int c = actions_achetes[index_alea].getQte();
        int qut_alea;
        if (c == 1)
        {
            qut_alea = c;
        }
        else
        {
            qut_alea = rand() % c;
            while (qut_alea == 0)
            {
                qut_alea = rand() % c;
            }
        }
        actionqut.setQte(qut_alea);
        actionqut.setNomAction(actions_achetes[index_alea].getNomAction());

        Transaction t(type, actionqut);
        return t;
    }
    else if (s == "ACHAT")
    {
        type = ACHAT;
        // choisir action aleatoire mel bourse (prix 1Q < solde)
        srand(time(NULL));

        int ct = 0;
        do
        {
            int index_alea = rand() % nom_actions.size();
            auto it = nom_actions.begin();
            for (int i = 0; i < index_alea; i++)
            {
                it++;
            }
            pj = B.get_prix_action_auj(it->get_nom_action());
            ct++;
        } while (pj->get_prix() > P.Get_solde() && ct < hard_limit);
        if (ct == hard_limit)
        {
            type = VENTE;
            s = "VENTE";
            cout << "Limite de recherche est depassee : " << s << endl;
            cout << "Switching to : " << s << endl;
            goto switch_to_vente;
        }
        actionqut.setNomAction(pj->get_nom_action());
        // choisir quantite aleatoire (quantite * prix < solde)
        int q = P.Get_solde() / pj->get_prix();
        int qut_alea;
        if (q == 1)
        {
            qut_alea = q;
        }
        else
        {
            qut_alea = rand() % q;
            while (qut_alea == 0)
            {
                qut_alea = rand() % q;
            }
        }

        actionqut.setQte(qut_alea);
        Transaction t(type, actionqut);
        return t;
    }
    else
    {
        Transaction t(type, actionqut);
        return t;
    }
}

template <>

Transaction Trader_aleatoire<BourseMultimap>::choisir_transaction(const BourseMultimap &B, const Portefeuille &P)
{
    int hard_limit = 500;
    PrixJournalier *pj;
    Date d = B.get_auj();
    TypeTransaction type;
    Titre actionqut;
    vector<Titre> actions_achetes = P.get_actions_possede();
    auto nom_actions = B.getActionsDisponiblesParDate(d);

    string s = Transaction::TypeTostring(type);
    if (nom_actions.size() == 0)
    {
        s = "RIEN"; // Bourse fermée
        type = RIEN;
    }
    else if (actions_achetes.empty())
    {
        s = "ACHAT";
        type = ACHAT;
    }
    else
    {
        type = static_cast<TypeTransaction>(rand() % 3);
        s = Transaction::TypeTostring(type);
    }

switch_to_vente:
    if (s == "RIEN")
    {
        type = RIEN;
        actionqut.setNomAction("");
        actionqut.setQte(0);
        Transaction t(type, actionqut);
        return t;
    }

    else if (s == "VENTE")
    {
        type = VENTE;
        // choisir action aleatoire de portefuille
        // choisir quantite aleatoire de la quantite possedée
        srand(time(NULL));
        int index_alea = rand() % actions_achetes.size();
        // choisir quantite aleatoire (quantite * prix < solde)
        int c = actions_achetes[index_alea].getQte();
        int qut_alea;
        if (c == 1)
        {
            qut_alea = c;
        }
        else
        {
            qut_alea = rand() % c;
            while (qut_alea == 0)
            {
                qut_alea = rand() % c;
            }
        }
        actionqut.setQte(qut_alea);
        actionqut.setNomAction(actions_achetes[index_alea].getNomAction());

        Transaction t(type, actionqut);
        return t;
    }
    else if (s == "ACHAT")
    {
        type = ACHAT;
        // choisir action aleatoire mel bourse (prix 1Q < solde)
        srand(time(NULL));
        int ct = 0;
        do
        {
            Date rand_key;
            auto range = nom_actions.equal_range(d);
            auto itb = range.first;
            auto ite = range.second;
            size_t rangesize = distance(itb, ite);
            size_t index_alea = rand() % rangesize;
            advance(itb, index_alea);
            auto key_alea = itb->first;
            auto value_alea = itb->second;
            pj = B.get_prix_action_auj(value_alea.get_nom_action());
            ct++;
        } while (pj->get_prix() > P.Get_solde() && ct < hard_limit);
        if (ct == hard_limit)
        {
            type = VENTE;
            s = "VENTE";
            cout << "Limite de recherche est depassee : " << s << endl;
            cout << "Switching to : " << s << endl;
            goto switch_to_vente;
        }
        actionqut.setNomAction(pj->get_nom_action());
        // choisir quantite aleatoire (quantite * prix < solde)
        int q = P.Get_solde() / pj->get_prix();
        int qut_alea;
        if (q == 1)
        {
            qut_alea = q;
        }
        else
        {
            qut_alea = rand() % q;
            while (qut_alea == 0)
            {
                qut_alea = rand() % q;
            }
        }

        actionqut.setQte(qut_alea);
        Transaction t(type, actionqut);
        return t;
    }
    else
    {
        Transaction t(type, actionqut);
        return t;
    }
}
