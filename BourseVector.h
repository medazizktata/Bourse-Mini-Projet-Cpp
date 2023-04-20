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
    vector<PrixJournalier> get_bourse();
    vector<string> getActionsDisponiblesParDate(const Date& d) const ;
    vector<pair<string, double>> getPrixJournaliersParDate(const Date& d) const;
    void acces_archive(const Date d, int i, const string nom);
};

#endif // BOURSEVECTOR_H_INCLUDED
