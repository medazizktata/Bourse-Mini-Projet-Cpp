#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <chrono>
#include <thread>
#include "BourseVector.h"
#include "Bourse.h"
#include "PersistancePrixJournaliers.h"
#include "PrixJournalier.h"

using namespace std;

BourseVector::BourseVector(const string &filepath)
{
    m_prixJournaliers = PersistancePrixJournaliers::lirePrixJournaliersDUnFichiervector(filepath);
    cout << "Creation de Bourse de type Bourse Vecteur" << endl;
}
BourseVector::~BourseVector() { cout << "Bourse de type Vecteur a ete detruite" << endl; }
vector<PrixJournalier> BourseVector::get_bourse()
{
    return m_prixJournaliers;
}

bool compare_date(PrixJournalier a, PrixJournalier b)
{
    return (a.get_date() < b.get_date());
}

void BourseVector::acces_archive(const Date d, int n, const string nom)
{
    vector<PrixJournalier> getaction_dates;
    int i = 0;
    for (PrixJournalier &c : m_prixJournaliers)
    {
        if (c.get_nom_action() == nom && c.get_date() < d)
        {
            getaction_dates.push_back(c);
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
        sort(getaction_dates.begin(), getaction_dates.end(), compare_date);
        cout << "Nom de l'action : " << nom << endl;
        cout << "Date limite de recherche : " << d << endl;
        cout << "Nombre d'actions trouvees : " << i << endl;
        for (auto j : getaction_dates)
        {
            cout << "Date :" << j.get_date();
            cout << " "
                 << "Prix : " << j.get_prix() << endl;
        }
    }
}

PrixJournalier *BourseVector::getprixjournalier(Date d, string nom) const
{
    PrixJournalier *resultat = nullptr;
    for (auto compteur : m_prixJournaliers)
    {
        if (compteur.get_date() == d && compteur.get_nom_action() == nom)
        {
            resultat = new PrixJournalier(compteur);
            break;
        }
    }
    return resultat;
}

double BourseVector::get_prix_action(Date d, string nom) const
{
    double prixaction = 0.0;

    auto compteur = m_prixJournaliers.begin();
    while (compteur->get_date() < d && compteur != m_prixJournaliers.end())
    {
        if (compteur->get_nom_action() == nom)
        {
            prixaction = compteur->get_prix();
        }
        ++compteur;
    }

    return prixaction;
}

vector<string> BourseVector::getActionsDisponiblesParDate(Date &d) const
{
    vector<string> actionsDisponibles;
    bool found = false;
    for (auto compteur : m_prixJournaliers)
    {
        if (compteur.get_date() == d)
        {
            actionsDisponibles.push_back(compteur.get_nom_action());
            found = true;
        }
    }
    if (!found)
    {
        actionsDisponibles = {};
    }
    return actionsDisponibles;
}

double BourseVector::get_prix_action(const Date d, string nom) const
{
    double prix;
    bool found = false;
    for (auto compteur : m_prixJournaliers)
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