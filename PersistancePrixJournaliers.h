#ifndef PERSISTANCEPRIXJOURNALIERS_H
#define PERSISTANCEPRIXJOURNALIERS_H
#include<vector>
#include<fstream>
#include<iostream>
#include <map>
#include <string>
#include<set>
#include "PrixJournalier.h"
using namespace std;
class PersistancePrixJournaliers
{
public:
    static vector<PrixJournalier> lirePrixJournaliersDUnFichiervector(string chemin)
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
    static multimap<Date, PrixJournalier> lirePrixJournaliersDUnFichiermultimap(string chemin)
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
    static multiset<PrixJournalier> lirePrixJournaliersDUnFichierset(string chemin)
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
};

#endif // PERSISTANCEPRIXJOURNALIERS_H
