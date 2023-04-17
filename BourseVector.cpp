#include <iostream>
#include <vector>
#include "PrixJournalier.h"
#include "BourseVector.h"
//#include <xlnt/xlnt.hpp>


using namespace std;
BourseVector::BourseVector(const vector<PrixJournalier>& prixJournaliers) {
    m_prixJournaliers = prixJournaliers;
}
/*
xlnt::workbook prices_simple;
fichierExcel.load('prices_simple');
xlnt::worksheet feuille = prices_simple.active_sheet();
*/

vector<string> BourseVector::getActionsDisponiblesParDate(const Date& date) const{
    vector<string> actionsDisponibles;

    for(const PrixJournalier& compteur : m_prixJournaliers){
        if(compteur.get_date()== date)
            actionsDisponibles.push_back(compteur.get_nom_action());
    }
    return actionsDisponibles;
}

vector<PrixJournalier> BourseVector::getPrixJournaliersParDate(const Date& date) const{
    vector<PrixJournalier> prixJournaliersParDate;
    for (const PrixJournalier& compteur : m_prixJournaliers) {
        if (compteur.get_date() == date) {
            prixJournaliersParDate.push_back(compteur.get_prix());
        }
    }
    return prixJournaliersParDate;
}
