#include <iostream>
#include "Date.h"
#include "PrixJournalier.h"
using namespace std;
class Bourse
{
protected:
    Date auj;

public:
    Bourse(){}
    Date get_auj() const
    {
        return auj;
    }
    Date set_auj(Date j)
    {
        auj = j;
    }
    virtual ~Bourse() {}
    virtual double get_prix_action(Date d, string nom) const = 0;
    virtual double get_dernier_prix_action(string nom) const = 0;
    virtual PrixJournalier *getprixjournalier(Date d, string nom) const = 0;
    PrixJournalier *get_prix_action_auj(string nom) const
    {
        return getprixjournalier(auj, nom);
    }
    virtual void acces_archive(const Date d, int n, const string nom) = 0;

    virtual vector<string> getActionsDisponiblesParDate(Date &d) const = 0;
};
