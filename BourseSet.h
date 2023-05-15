#ifndef BOURSEVECTOR_H_INCLUDED
#define BOURSEVECTOR_H_INCLUDED
#include <iostream>
#include <vector>
#include<set>
#include "PrixJournalier.h"
#include "Bourse.h"
using namespace std;
class BourseSet : public Bourse<multiset<PrixJournalier>>
{

private:
    multiset<PrixJournalier> set_prixJournaliers;

public:
    BourseSet(const string &filepath);
    ~BourseSet();
    multiset<PrixJournalier> get_bourse();
    void acces_archive(const Date d, int i, const string nom);
    PrixJournalier *getprixjournalier(Date d, string nom) const;
    double get_dernier_prix_action(Date d, string nom) const;
    multiset<PrixJournalier> getActionsDisponiblesParDate(Date &d) const;
    double get_prix_action(Date d, string nom) const;
};

#endif // BOURSEVECTOR_H_INCLUDED
