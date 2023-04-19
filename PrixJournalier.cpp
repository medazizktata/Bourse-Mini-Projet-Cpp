#include <iostream>
#include <string>

#include "Date.h"
#include "Date.cpp"
#include "PrixJournalier.h"
using namespace std;

int main (){
    Date d(1,6,2022);
    Date d1(10,12,2014);
    Date d2;
    PrixJournalier p2, p3;
    cout<<d<<endl;
    cout<<d1<<endl;
    PrixJournalier p(d, "ETH", 50);
    cout<<p2<<endl;
    cout<<p<<endl;
    cout<<"Action"<<endl;
    cin>>p3;
    cout<<p3<<endl;
    return 0;
}