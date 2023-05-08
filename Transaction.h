#ifndef TRANSACTION_H_INCLUDED
#define TRANSACTION_H_INCLUDED

#include <string>
#include "Titre.h"

using namespace std;

enum TypeTransaction {RIEN,ACHAT,VENTE};

class Transaction
{
private:
    TypeTransaction type;
    Titre actionq;
public:
    Transaction(TypeTransaction t, Titre act);
    TypeTransaction GetType();
    Titre GetNomAction();
    void SetType(TypeTransaction t);
    void SetNomAction(string nom);
};

#endif // TRANSACTION_H_INCLUDED
