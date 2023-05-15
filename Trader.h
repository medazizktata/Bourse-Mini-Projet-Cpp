#ifndef TRADER_H_INCLUDED
#define TRADER_H_INCLUDED
#include <iostream>
#include <typeinfo>
#include <string>
#include "BourseVector.h"
#include "BourseSet.h"
#include "BourseMultimap.h"
#include "Bourse.h"
#include "Portefeuille.h"
#include "Transaction.h"
using namespace std;
template <typename typebourse>

class Trader
{
public:
    Trader() {}
    virtual Transaction choisir_transaction(const typebourse &B, const Portefeuille &P) = 0;
    virtual ~Trader()
    {
        cout << "Trader detruit" << endl;
    }
    string get_nom_trader()
    {
        return nom_tr;
    }

private:
    string nom_tr;
};

template <typename typebourse>

class Trader_aleatoire : public Trader<typebourse>
{
public:
    Trader_aleatoire()
    {
        cout << "Creation de Trader de type Aleatoire pour  " << typeid(typebourse).name() << endl;
    }

    Transaction choisir_transaction(const typebourse &B, const Portefeuille &P) override;
    ~Trader_aleatoire()
    {
        cout << "Trader Aleatoire pour  " << typeid(typebourse).name() << "est detruit" << endl;
    }
};
#endif
