#include <iostream>
#include <string>
#include "Transaction.h"
#include "Titre.h"
using namespace std;

Transaction::Transaction(TypeTransaction t, Titre act)
{
    type = t;
    actionq = act;
}
TypeTransaction Transaction::GetType()
{
    return type;
}
Titre Transaction::GetTitre()
{
    return actionq;
}
void Transaction::SetType(TypeTransaction t)
{
    type = t;
}
void Transaction::SetTitre(string nom)
{
    actionq = nom;
}