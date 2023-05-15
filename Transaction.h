#ifndef TRANSACTION_H_INCLUDED
#define TRANSACTION_H_INCLUDED
#include <iostream>
#include <string>
#include "Titre.h"

using namespace std;

enum TypeTransaction
{
    RIEN,
    ACHAT,
    VENTE
};

class Transaction
{
private:
    TypeTransaction type;
    Titre actionq;

public:
    Transaction(TypeTransaction t, Titre act);
    TypeTransaction GetType();
    Titre GetTitre();
    void SetType(TypeTransaction t);
    void SetTitre(string nom);
    string GetstringTypeTransaction();
    static string TypeTostring(TypeTransaction type);
};

#endif // TRANSACTION_H_INCLUDED
