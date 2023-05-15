#include "PersistancePrixJournaliers.h"
#include "Date.h"
#include "PrixJournalier.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

vector<PrixJournalier> PersistancePrixJournaliers::lirePrixJournaliersDUnFichiervector(string chemin)
{
    vector<PrixJournalier> historique;
    ifstream f(chemin);
    int nbLignes = 0;
    string entete;
    if (f.is_open())
    {
        getline(f, entete);
        while (getline(f, entete))
        {
            PrixJournalier pj;
            istringstream ss(entete);
            ss >> pj;
            historique.push_back(pj);
            nbLignes++;
        }
    }
    return historique;
}
multimap<Date, PrixJournalier> PersistancePrixJournaliers::lirePrixJournaliersDUnFichiermultimap(string chemin)
{
    multimap<Date, PrixJournalier> historique;

    ifstream f(chemin);
    int nbLignes = 0;
    string entete;
    if (f.is_open())
    {
        getline(f, entete);
        while (getline(f, entete))
        {
            PrixJournalier pj;

            istringstream ss(entete);
            ss >> pj;
            historique.emplace(pj.get_date(), pj);
            nbLignes++;
        }
    }
    return historique;
}
multiset<PrixJournalier> PersistancePrixJournaliers::lirePrixJournaliersDUnFichierset(string chemin)
{
    multiset<PrixJournalier> historique;

    ifstream f(chemin);
    int nbLignes = 0;
    string entete;
    if (f.is_open())
    {
        getline(f, entete);
        while (getline(f, entete))
        {
            PrixJournalier pj;

            istringstream ss(entete);
            ss >> pj;
            historique.emplace(pj);
            nbLignes++;
        }
    }
    return historique;
}