#ifndef BOURSEVECTOR_H_INCLUDED
#define BOURSEVECTOR_H_INCLUDED
#include <iostream>
#include <vector>
#include "PrixJournalier.h"
#include "Bourse.h"
using namespace std;
class BourseVector : public Bourse<vector<string>>
{

private:
    vector<PrixJournalier> m_prixJournaliers;

public:
    BourseVector(const string &filepath);
    ~BourseVector();
    vector<PrixJournalier> get_bourse();
    void acces_archive(const Date d, int i, const string nom);
    PrixJournalier *getprixjournalier(Date d, string nom) const;
    double get_dernier_prix_action(string nom) const;
    vector<string> getActionsDisponiblesParDate(Date &d) const override;
    double get_prix_action(Date d, string nom) const;
};

#endif // BOURSEVECTOR_H_INCLUDED
