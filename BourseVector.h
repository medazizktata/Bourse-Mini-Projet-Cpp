#ifndef BOURSEVECTOR_H_INCLUDED
#define BOURSEVECTOR_H_INCLUDED
#include <iostream>
#include <vector>
#include "PrixJournalier.h"
using namespace std;
class BourseVector {

private:
    vector<PrixJournalier> m_prixJournaliers;

public:
    BourseVector(const string& filepath);
    ~BourseVector();
    vector<PrixJournalier> get_bourse();
    void acces_archive(const Date d, int i, const string nom);
    PrixJournalier* getprix_action_date(Date d, string nom) const;
    double get_dernier_prix_action(string nom) const;
    vector<string> getActionsDisponiblesParDate(Date& d) const;
    double get_prix_action(Date d, string nom);
};

#endif // BOURSEVECTOR_H_INCLUDED
