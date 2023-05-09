#include <iostream>
#include <string>
#include "Bourse.h"
#include "Portefeuille.h"
#include "Transaction.h"
using namespace std;
class Trader
{
public:
    Trader();
    virtual Transaction choisir_transaction(const Bourse &B, const Portefeuille &P) = 0;
    virtual ~Trader()
    {
        cout << "Trader detruit" << endl;
    }
    string get_nom_trader();

private:
    string nom_tr;
};

class Trader_aleatoire : public Trader {
    public: 
    Transaction choisir_transaction(const Bourse &B, const Portefeuille &P);
    ~Trader_aleatoire()
    {
        cout << "Trader Aleatoire detruit" << endl;
    }
};
