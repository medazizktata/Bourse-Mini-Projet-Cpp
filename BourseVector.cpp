#include <iostream>
#include <vector>
#include "BourseVector.h"
//#include <xlnt/xlnt.hpp>

using namespace std;
/*
xlnt::workbook prices_simple;
fichierExcel.load('prices_simple');
xlnt::worksheet feuille = prices_simple.active_sheet();
*/
BourseVector::BourseVector(const vector<PrixJournalier>& prixJournaliers, const string& filepath){
    m_prixJournaliers = prixJournaliers;
}
vector<string> BourseVector::getActionsDisponiblesParDate(const Date& d) const{
    vector<string> actionsDisponibles;

    for(auto compteur : m_prixJournaliers){
        if(compteur.get_date()== d)
            actionsDisponibles.push_back(compteur.get_nom_action());
    }
    return actionsDisponibles;
}
vector<pair<string, double>> BourseVector::getPrixJournaliersParDate(const Date& date) const{
    vector<pair<string, double>> prixJournaliersParDate;
    for (auto compteur : m_prixJournaliers) {
        if (compteur.get_date() == date) {
            pair <string, double> p= make_pair(compteur.get_nom_action(),compteur.get_prix());
            prixJournaliersParDate.push_back(p);
        }
    }
    return prixJournaliersParDate;
}

