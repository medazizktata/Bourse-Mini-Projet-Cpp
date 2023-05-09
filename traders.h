#ifndef TRADERS_H_INCLUDED
#define TRADERS_H_INCLUDED

#include "transaction.h"
#include "portfeuil.h"
#include "bourse.h"
#include "PrixJournalier.h"

using namespace std;

class Trader{

private:
    Portefeuille portefeuilleTrader;

public:
    Transaction choisirTransaction(const Bourse& bourse, const Portefeuille &portefeuille);
    void effectuerTransaction(Transaction tt);
};



class TraderAléatoire{

private:

public:

};
#endif // TRADERS_H_INCLUDED
