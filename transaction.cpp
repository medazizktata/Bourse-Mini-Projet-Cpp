#include "Transaction.h"

using namespace std ;

Transaction ::Transaction(TypeTransaction ty,string acti)
{
    Type=ty;
    Action=acti;

}
TypeTransaction Transaction ::GetType()
{
    return Type;
}
string Transaction ::GetNomAction()
{
    return Action;
}

