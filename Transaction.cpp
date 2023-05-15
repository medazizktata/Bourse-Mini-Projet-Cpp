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
string Transaction::GetstringTypeTransaction()
{
    switch (type)
    {
    case RIEN:
        return "RIEN";
    case ACHAT:
        return "ACHAT";
    case VENTE:
        return "VENTE";
    default:
        return "UNKNOWN";
    }
}
string Transaction::TypeTostring(TypeTransaction t)
{
    switch (t)
    {
    case RIEN:
        return "RIEN";
    case ACHAT:
        return "ACHAT";
    case VENTE:
        return "VENTE";
    default:
        return "UNKNOWN";
    }
}