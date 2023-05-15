#include <iostream>
#include <string>
#include <chrono>
#include <map>
#include "Date.h"
#include "Portefeuille.h"
#include "Trader.h"
#include "Bourse.h"
#include "BourseVector.h"
using namespace std;
using namespace chrono;
class Simulation
{
private:
    static Portefeuille portefeuilleTrader;

public:
    Simulation(Portefeuille p)
    {
        portefeuilleTrader = p;
    }
    Portefeuille get_portfeuille()
    {
        return portefeuilleTrader;
    }
    static map<string, long> lancer_simulation(Bourse &B, Trader &T, Date date_deb, Date date_fin, double solde=0)
    {
        map<string, long> stats, prix_vente;
        Titre nth;
        Transaction tr(RIEN, nth);
        Date dateact(date_deb.get_jour(), date_deb.get_mois(), date_deb.get_annee());
        B.set_auj(dateact);
        double solded_init = solde;
        double gain;
        int i = 0, nb_achats = 0, nb_ventes = 0, nb_rien = 0;
        auto start = high_resolution_clock::now();
        while (dateact < date_fin)
        {
            if (B.getActionsDisponiblesParDate(dateact).size() > 0)
            {
                cout << "Aujourd'hui le : " << dateact << endl;
                do
                {
                    tr = T.choisir_transaction(B, portefeuilleTrader);
                    portefeuilleTrader.effectuerTransaction(B, tr);
                    if (tr.GetType() == ACHAT)
                    {
                        nb_achats++;
                        prix_vente[tr.GetTitre().getNomAction()] = B.get_prix_action_auj(tr.GetTitre().getNomAction())->get_prix();
                    }
                    else if (tr.GetType() == VENTE)
                    {
                        nb_ventes++;
                        prix_vente[tr.GetTitre().getNomAction()] = B.get_prix_action_auj(tr.GetTitre().getNomAction())->get_prix();
                    }
                    else
                        if (tr.GetType() == RIEN)
                        {
                            nb_rien++;
                        }
                    else
                    {
                        cout << "Transaction échouée" << endl;
                    }
                    i++;
                } while (tr.GetType() != RIEN && i < 100);
            }
        }
        dateact.incrementer();
        B.set_auj(dateact);
        auto end = high_resolution_clock::now();
        auto duree = duration_cast<microseconds>(end - start);

        for (Titre tr : portefeuilleTrader.get_actions_possede())
        {
            for (auto pv : prix_vente)
            {
                if (tr.getNomAction() == pv.first)
                {
                    gain += pv.second * tr.getQte();
                }
            }
        }
        auto start1 = high_resolution_clock::now();
        B.getActionsDisponiblesParDate(dateact);
        auto end1 = high_resolution_clock::now();
        auto duree1 = duration_cast<microseconds>(end1 - start1);
        stats["nombre d'achats"] = nb_achats;
        stats["nombres de ventes"] = nb_ventes;
        stats["nombres total de transaction"] = nb_achats + nb_rien + nb_ventes;
        stats["nombres d'actions"] = portefeuilleTrader.get_actions_possede().size();
        stats["solde final"] = portefeuilleTrader.Get_solde();
        stats["profit"] = gain - solded_init;
        stats["profit %"] = (100 * (gain - solded_init) / solded_init);
        stats["Temps d'execution de programme (µs)"] = duree.count();
        stats["Temps moyen get actions disponible aujoud'hui (µs)"] = duree1.count();

        return stats;
    }
};

int main()
{
    string filepath = "C://Users//zizou//OneDrive//Documents//GitHub//Bourse-Mini-Projet-C--//prices_simple.csv";
    BourseVector B(filepath);
    Trader_aleatoire T1;
    Portefeuille P1;
    int solde;
    Date dateDebut(1, 5, 2014);
    Date datefin(30, 11, 2014);
    auto stats = Simulation::lancer_simulation(B, T1, dateDebut, datefin, solde);
    for (auto it : stats)
    {
        cout << it.first << "\t" << it.second << endl;
    }
    return 0;
}
