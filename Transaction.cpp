#include <iostream>
#include <string>
#include "Transaction.h"
using namespace std;

Transaction::Transaction(TypeTransaction t,string act){
    type=t;
    action=act;
}
TypeTransaction Transaction:: GetType(){
    return type;
}
string Transaction::GetNomAction(){
    return action;
}