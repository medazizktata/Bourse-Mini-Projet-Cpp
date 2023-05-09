#include <iostream>
#include <string>
#include "Transaction.h"
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
Titre Transaction::GetNomAction()
{
    return actionq;
}
void Transaction::SetType(TypeTransaction t)
{
    type = t;
}
void Transaction::SetNomAction(string nom)
{
    actionq = nom;
}