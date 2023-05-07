#ifndef TRANSACTION_H_INCLUDED
#define TRANSACTION_H_INCLUDED

#include <string>

using namespace std;

enum TypeTransaction {RIEN,ACHAT,VENTE};

class Transaction
{
private:
    TypeTransaction type;
    string action;
public:
    Transaction(TypeTransaction t,string act);
    TypeTransaction GetType();
    string GetNomAction();
};

#endif // TRANSACTION_H_INCLUDED
