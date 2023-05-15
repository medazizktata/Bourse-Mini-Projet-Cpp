#include <iostream>
#include <string>
#include <map>
#include <chrono>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <iterator>
#include <thread>
#include <set>
#include "Date.h"
#include "PrixJournalier.h"
#include "Titre.h"
#include "Transaction.h"
#include "Trader.h"
#include "Bourse.h"
#include "BourseVector.h"
#include "BourseSet.h"
#include "BourseMultimap.h"
#include "Portefeuille.h"
#include "PersistancePrixJournaliers.h"
#include "Simulation.h"

using namespace std;
using namespace chrono;

int main()
{

    string filepath = "C://Users//zizou//OneDrive//Documents//GitHub//Bourse-Mini-Projet-C--//prices_simple.csv";
    int c = 0;
    Date date_deb;
    Date date_fin;
    Date df;
    double solde;
    int count = -1;
    while (c != 4)
    {
        date_deb = df;
        date_fin = df;
        cout << "\n\nBienvenue dans le programme de simulation de bourse\n"
             << endl;
        do
        {

            cout << "Choississez la date d'aujourd'hui sous la forme (JJ/MM/AAAA): ";
            date_deb.saisie_date();
            cout << "\nAujourd'hui C'est le : " << date_deb << endl;
            cout << "Choississez la date de fin de la simulation sous la forme (JJ/MM/AAAA): ";
            date_fin.saisie_date();
        } while (date_fin < date_deb);
        cout << "Fin de Simulation prevue le : " << date_fin << endl;
        cout << "Donner le solde de départ pour alimenter le portefeuille (en DT) : ";
        cin >> solde;
        Portefeuille P1;
        P1.Alimenter_portefeuille(solde);
        cout << "Creation et alimentation du portefeuille reussite" << endl;
        cout << "Choississez le type de bourse : " << endl;
        cout << "1) VECTOR" << endl;
        cout << "2) SET" << endl;
        cout << "3) MAPA" << endl;
        cout << "\nChoix : ";
        cin >> c;
        switch (c)
        {
        case 1:
        {
            BourseVector B1(filepath);
            B1.set_auj(date_deb);
            Trader_aleatoire<BourseVector> t1;
            auto stats1 = Simulation<BourseVector>::lancer_simulation(B1, t1, date_deb, date_fin, solde);
            for (auto it : stats1)
            {
                cout << it.first << "\t" << it.second << endl;
            }
            cout << "\nSimulation terminee!" << endl;
            break;
        }
        case 2:
        {
            BourseSet B2(filepath);
            B2.set_auj(date_deb);
            Trader_aleatoire<BourseSet> t2;
            auto stats2 = Simulation<BourseSet>::lancer_simulation(B2, t2, date_deb, date_fin, solde);
            for (auto it : stats2)
            {
                cout << it.first << "\t" << it.second << endl;
            }
            cout << "\nSimulation terminee!" << endl;
            break;
        }
        case 3:
        {
            BourseMultimap B3(filepath);
            B3.set_auj(date_deb);
            Trader_aleatoire<BourseMultimap> t3;
            auto stats3 = Simulation<BourseMultimap>::lancer_simulation(B3, t3, date_deb, date_fin, solde);
            for (auto it : stats3)
            {
                cout << it.first << "\t" << it.second << endl;
            }
            cout << "\nSimulation terminee!" << endl;
            break;
        }
        case 4:
        {
            cout << "\nSimulation terminee!" << endl;
            cout << "Fermeture du programme...\n";
        }
        default:
            cout << "Choix Invalide, Veuillez ressayer..." << endl;
            break;
        }
    }
    return 0;
}