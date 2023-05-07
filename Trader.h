#include <iostream>
#include <string>
#include <vector>
#include "Bourse.h"
#include "PrixJournalier.h"
#include "Portefeuille.h"
#include "Transaction.h"
using namespace std;
class Trader {
    public:
    Trader();
    Transaction choisir_transaction(const Bourse& B, const Portefeuille& P);
    string get_nom_trader();
    private:
    string nom_tr;
};
