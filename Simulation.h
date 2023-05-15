#include <iostream>
#include <string>
#include <chrono>
#include <map>
#include <set>
#include "Portefeuille.h"
#include "Trader.h"
#include "Bourse.h"
#include "BourseVector.h"
#include "BourseSet.h"
#include "BourseMultimap.h"
using namespace std;
using namespace chrono;
template <typename typebourse>
class Simulation
{

public:
    Simulation() {}
    static map<string, long> lancer_simulation(typebourse &B, Trader<typebourse> &T, Date date_deb, Date date_fin, double solde = 0)
    {
        map<string, long> stats, prix_vente;
        Titre nth;
        Transaction tr(RIEN, nth);
        Date dateact(date_deb.get_jour(), date_deb.get_mois(), date_deb.get_annee());
        B.set_auj(dateact);
        Portefeuille portefeuilleT;
        portefeuilleT.Alimenter_portefeuille(solde);

        double solded_init = portefeuilleT.Get_solde();
        cout << "Trader aleatoire " << T.get_nom_trader() << endl;
        cout << "Solde initial: " << solded_init << endl;
        double gain = 0;
        int i = 0, nb_achats = 0, nb_ventes = 0, nb_rien = 0;
        auto start = high_resolution_clock::now();
        while (dateact < date_fin)
        {
            if (B.getActionsDisponiblesParDate(dateact).size() > 0)
            {
                if (i == 100)
                {
                    cout << "Limite journaliere de transaction atteinte pour " << dateact << endl;
                }
                cout << "Actions Disponibles pour aujourd'hui le : " << dateact << endl;
                do
                {
                    tr = T.choisir_transaction(B, portefeuilleT);
                    string st = tr.GetstringTypeTransaction();
                    portefeuilleT.effectuerTransaction(B, tr);
                    if (st == "ACHAT")
                    {
                        nb_achats++;
                        prix_vente[tr.GetTitre().getNomAction()] = B.get_prix_action_auj(tr.GetTitre().getNomAction())->get_prix();
                    }
                    else if (st == "VENTE")
                    {
                        double recent_price;
                        if (B.get_prix_action_auj(tr.GetTitre().getNomAction()) == nullptr)
                        {
                            cout << "Pas de prix disponible pour la vente de cette action aujourd'hui" << endl;
                            cout << "Searching for most recent price" << endl;
                            recent_price = B.get_dernier_prix_action(dateact, tr.GetTitre().getNomAction());
                        }
                        else
                        {
                            recent_price = B.get_prix_action_auj(tr.GetTitre().getNomAction())->get_prix();
                        }
                        prix_vente[tr.GetTitre().getNomAction()] = recent_price;
                        nb_ventes++;
                    }
                    else if (st == "RIEN")
                    {
                        cout << "Pas de Transaction pour aujourd'hui" << endl;
                        nb_rien++;
                        break;
                    }
                    else
                    {
                        cout << "Transaction echouee" << endl;
                    }
                    i++;
                } while (i < 200);
            }
            else
            {
                cout << "Bourse est fermeee pour le : " << dateact << " Incrementation de jour en cours" << endl;
            }
            dateact.incrementer();
            B.set_auj(dateact);
        }

        auto end = high_resolution_clock::now();
        auto duree = duration_cast<microseconds>(end - start);
        cout << "Simulation has ended" << endl;

        gain += portefeuilleT.Get_solde();
        cout << "Vente de toutes les actions" << endl;
        for (Titre tr : portefeuilleT.get_actions_possede())
        {

            for (auto pv : prix_vente)
            {
                if (tr.getNomAction() == pv.first)
                {
                    gain += pv.second * tr.getQte();
                }
            }
        }
        portefeuilleT.Alimenter_portefeuille(gain);
        cout << "Solde initial : " << solded_init << endl;
        cout << "Solde final = " << gain << endl;
        auto start1 = high_resolution_clock::now();
        B.getActionsDisponiblesParDate(dateact);
        auto end1 = high_resolution_clock::now();
        auto duree1 = duration_cast<microseconds>(end1 - start1);
        stats["nombre d'achats"] = nb_achats;
        stats["nombres de ventes"] = nb_ventes;
        stats["nombres de Rien"] = nb_rien;
        stats["nombres total de transaction"] = nb_achats + nb_rien + nb_ventes;
        stats["nombres d'actions"] = portefeuilleT.get_actions_possede().size();
        stats["solde final"] = portefeuilleT.Get_solde();
        stats["profit"] = gain - solded_init;
        stats["profit %"] = (100 * (gain - solded_init) / solded_init);
        stats["Temps d'execution de programme"] = duree.count();
        stats["Temps moyen get actions disponible aujoud'hui"] = duree1.count();

        return stats;
    }
};
