#ifndef BOURSEMULTIMAP_H_INCLUDED
#define BOURSEMULTIMAP_H_INCLUDED
#include <iostream>
#include <vector>
#include<map>
#include "PrixJournalier.h"
#include "Bourse.h"
using namespace std;
class BourseMultimap : public Bourse<multimap<Date, PrixJournalier>>
{

private:
    multimap<Date, PrixJournalier> multimap_prixJournaliers;

public:
    BourseMultimap(const string &filepath);
    ~BourseMultimap();
    multimap<Date, PrixJournalier> get_bourse();
    void acces_archive(const Date d, int i, const string nom);
    PrixJournalier *getprixjournalier(Date d, string nom) const;
    double get_dernier_prix_action(Date d, string nom) const;
    multimap<Date, PrixJournalier> getActionsDisponiblesParDate(Date &d) const;
    double get_prix_action(Date d, string nom) const;
};

#endif // BOURSEMULTIMAP_H_INCLUDED
