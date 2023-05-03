#include "traders.h"
#include<iostream>
using namespace std;


Trader::Trader(Portefeuille p): portefeuilleTrader(p){}



Transaction Trader::choisirTransaction(const Bourse& bourse, const Portefeuille &portefeuille){

    ////////////////////
}



void Trader::effectuerTransaction(Transaction tt,PrixJournalier pp){

le_type=tt.GetType()

switch(le_type) {
  case ACHAT:

    portefeuilleTrader.Acheteraction(tt.GetNomAction(),pp.get_prix())
    break;
  case VENTE:
        portefeuilleTrader.Vendreraction(tt.GetNomAction(),pp.get_prix())
    break;

  case RIEN:

    //incrementer la date

    break;

  default:
    // code block
}
}
