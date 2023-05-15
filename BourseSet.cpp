#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <thread>
#include <set>
#include "Bourse.h"
#include "BourseSet.h"
#include "PersistancePrixJournaliers.h"
#include "PrixJournalier.h"

using namespace std;

BourseSet::BourseSet(const string &filepath)
{
    set_prixJournaliers = PersistancePrixJournaliers::lirePrixJournaliersDUnFichierset(filepath);
    cout << "Creation de Bourse de type Bourse SET" << endl;
}
BourseSet::~BourseSet() { cout << "Bourse de type SET a ete detruite" << endl; }

multiset<PrixJournalier> BourseSet::get_bourse()
{
    return set_prixJournaliers;
}

void BourseSet::acces_archive(const Date d, int n, const string nom)
{
    multiset<PrixJournalier> getaction_dates;
    int i = 0;
    for (const PrixJournalier &c : set_prixJournaliers)
    {
        if (c.get_nom_action() == nom && c.get_date() < d)
        {
            getaction_dates.insert(c);
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
            cout << "Date :" << j.get_date();
            cout << "Nom Action : " << j.get_nom_action() << endl;
            cout << "Prix : " << j.get_prix() << endl;
        }
    }
}

PrixJournalier *BourseSet::getprixjournalier(Date d, string nom) const
{
    PrixJournalier *resultat = nullptr;
    for (auto compteur : set_prixJournaliers)
    {
        if (compteur.get_date() == d && compteur.get_nom_action() == nom)
        {
            resultat = new PrixJournalier(compteur);
            break;
        }
    }
    return resultat;
}

double BourseSet::get_dernier_prix_action(Date d, string nom) const
{
    double prixaction = 0.0;

    auto compteur = set_prixJournaliers.begin();
    while (compteur->get_date() < d && compteur != set_prixJournaliers.end())
    {
        if (compteur->get_nom_action() == nom)
        {
            prixaction = compteur->get_prix();
        }
        ++compteur;
    }

    return prixaction;
}

multiset<PrixJournalier> BourseSet::getActionsDisponiblesParDate(Date &d) const
{
    multiset<PrixJournalier> actionsDisponibles;
    for (auto compteur : set_prixJournaliers)
    {
        if (compteur.get_date() == d)
        {
            actionsDisponibles.emplace(compteur);
        }
    }
    return actionsDisponibles;
}

double BourseSet::get_prix_action(const Date d, string nom) const
{
    double prix;
    bool found = false;
    for (auto compteur : set_prixJournaliers)
    {
        if (compteur.get_date() == d && compteur.get_nom_action() == nom)
        {
            prix = compteur.get_prix();
            found = true;
        }
    }
    if (!found)
    {
        prix = 0.0;
    }
    return prix;
}