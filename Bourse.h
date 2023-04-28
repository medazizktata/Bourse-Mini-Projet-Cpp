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
        vector<PrixJournalier> get_bourse();
        virtual vector<string> getActionsDisponiblesParDate(const Date& d) const =0;
        vector<pair<string, double>> getPrixJournaliersParDate(const Date& d) const;
        virtual double* get_prix_action(Date d, string nom) const = 0;
        double* get_prix_action_today(string nom){
            return get_prix_action(auj, nom);
        }
        void acces_archive(const Date d, int i, const string nom);
};