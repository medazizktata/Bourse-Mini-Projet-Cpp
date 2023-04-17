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
    BourseVector(const vector<PrixJournalier>& prixJournaliers/*,const string& nomFichierExcel*/);

    vector<string> getActionsDisponiblesParDate(const Date& date) const ;
    vector<PrixJournalier> getPrixJournaliersParDate(const Date& date) const;


};
#endif // BOURSEVECTOR_H_INCLUDED
