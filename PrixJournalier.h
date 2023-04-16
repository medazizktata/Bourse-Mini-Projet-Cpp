#ifndef PRIXJOURNALIER_H_INCLUDED
#define PRIXJOURNALIER_H_INCLUDED
#include <iostream>
#include <string>
#include "Date.h"
using namespace std;
class PrixJournalier {
    private:
        string nom_action;
        double prix;
        Date date;

    public:
        PrixJournalier();
        ~PrixJournalier();
        PrixJournalier(Date d, string na, double p);
        string get_nom_action();
        double get_prix();
        Date get_date();
        friend ostream& operator<<(ostream& os, const PrixJournalier& pj);
        friend istream& operator>>(istream& is, PrixJournalier& pj);
};

#endif