#include <iostream>
#include "Date.h"
#include "PrixJournalier.h"
using namespace std;
class Bourse{
    private:
        Date auj;
    public:
        Bourse(){}
        Date get_auj(){
            return auj;
        }
        Date set_auj(Date j){
            auj=j;
        }
        virtual ~Bourse(){}
        virtual double get_prix_action(Date d, string nom)=0;
        virtual double get_dernier_prix_action(string nom) const=0;
        virtual PrixJournalier* getprixjournalier(Date d, string nom) const = 0;
        PrixJournalier* get_prix_action_auj(string nom){
            return getprixjournalier(auj, nom);
        }
        virtual void acces_archive(const Date d, int n, const string nom)=0;
};

    
