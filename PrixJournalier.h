#ifndef PRIXJOURNALIER_H_INCLUDED
#define PRIXJOURNALIER_H_INCLUDED
#include <iostream>
#include <string>
#include <iomanip>
#include "Date.h"
using namespace std;
class PrixJournalier
{
private:
    string nom_action;
    double prix;
    Date date;

public:
    PrixJournalier();
    ~PrixJournalier();
    PrixJournalier(Date d, string na, double p);
    string get_nom_action() const;
    double get_prix() const;
    Date get_date() const;
    void set_date(Date d);
    void set_nom_action(string nom);
    void set_prix(double p);
    friend ostream &operator<<(ostream &os, const PrixJournalier &pj);
    friend istream &operator>>(istream &is, PrixJournalier &pj);

    bool operator<(const PrixJournalier &pj) const
    {
        return date < pj.get_date();
    }
};

#endif