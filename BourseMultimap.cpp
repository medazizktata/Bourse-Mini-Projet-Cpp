#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <thread>
#include <map>
#include "Bourse.h"
#include "BourseMultimap.h"
#include "PersistancePrixJournaliers.h"
#include "PrixJournalier.h"

using namespace std;

BourseMultimap::BourseMultimap(const string &filepath)
{
    multimap_prixJournaliers = PersistancePrixJournaliers::lirePrixJournaliersDUnFichiermultimap(filepath);
    cout << "Creation de Bourse de type Bourse MULTIMAP" << endl;
}
BourseMultimap::~BourseMultimap() { cout << "Bourse de type MULTIMAP a ete detruite" << endl; }

multimap<Date, PrixJournalier> BourseMultimap::get_bourse()
{
    return multimap_prixJournaliers;
}

void BourseMultimap::acces_archive(const Date d, int n, const string nom)
{
    multimap<Date, PrixJournalier> getaction_dates;
    int i = 0;
    for (auto &c : multimap_prixJournaliers)
    {
        if (c.second.get_nom_action() == nom && c.first < d)
        {
            getaction_dates.emplace(c.first, c.second);
            i++;
        }
        if (i == n)
        {
            break;
        }
    }
    if (getaction_dates.size() == 0)
    {
        cout << "Action " << nom << " pas trouvee avant le " << d << endl;
    }
    else
    {
        // sort(getaction_dates.begin(), getaction_dates.end(), compare_date); Insertion avec sorting automatique (surcharge < Prixjournalier)
        cout << "Nom de l'action : " << nom << endl;
        cout << "Date limite de recherche : " << d << endl;
        cout << "Nombre d'actions trouvees : " << i << endl;
        for (auto j : getaction_dates)
        {
            cout << "Date :" << j.first << endl;
            cout << "Nom Action : " << j.second.get_nom_action() << endl;
            cout << "Prix : " << j.second.get_prix() << endl;
        }
    }
}

PrixJournalier *BourseMultimap::getprixjournalier(Date d, string nom) const
{
    PrixJournalier *resultat = nullptr;
    for (auto compteur : multimap_prixJournaliers)
    {
        Date dd = compteur.first;
        if (dd == d && compteur.second.get_nom_action() == nom)
        {
            resultat = new PrixJournalier(compteur.second);
            break;
        }
    }
    return resultat;
}

double BourseMultimap::get_dernier_prix_action(Date d, string nom) const
{
    double prixaction = 0.0;

    auto compteur = multimap_prixJournaliers.begin();
    while (compteur->first < d && compteur != multimap_prixJournaliers.end())
    {
        if (compteur->second.get_nom_action() == nom)
        {
            prixaction = compteur->second.get_prix();
        }
        ++compteur;
    }

    return prixaction;
}

multimap<Date, PrixJournalier> BourseMultimap::getActionsDisponiblesParDate(Date &d) const
{
    multimap<Date, PrixJournalier> actionsDisponibles;
    for (auto compteur : multimap_prixJournaliers)
    {
        Date dd = compteur.first;
        if (dd == d)
        {
            actionsDisponibles.emplace(compteur.first, compteur.second);
        }
    }
    return actionsDisponibles;
}

double BourseMultimap::get_prix_action(const Date d, string nom) const
{
    double prix;
    bool found = false;
    for (auto compteur : multimap_prixJournaliers)
    {
        Date dd = compteur.first;
        if (dd == d && compteur.second.get_nom_action() == nom)
        {
            prix = compteur.second.get_prix();
            found = true;
        }
    }
    if (!found)
    {
        prix = 0.0;
    }
    return prix;
}
