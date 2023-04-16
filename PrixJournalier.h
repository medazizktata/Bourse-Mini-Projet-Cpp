#ifndef PRIXJOURNALIER_H_INCLUDED
#define PRIXJOURNALIER_H_INCLUDED
#include <iostream>
#include <string>
#include "Date.h"
using namespace std;
class Prixjournalier {
    private:
    string nom_action;
    int prix;
    Date date;

    public:
    Prixjournalier(string na, int p, Date d);
    string get_nom_action();
    int get_prix();
    Date get_date();
    friend ostream& operator<<(ostream& os, const Prixjournalier& pj);
    friend istream& operator>>(ostream& is, const Prixjournalier& pj);
};
#endif