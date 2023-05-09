#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Titre.h"
using namespace std;


Titre::Titre(string n="",double q=0){
    nom_action=n;
    qte=q;
}

string Titre::getNomAction() const{
    return nom_action;
}
double Titre::getQte() const{
    return qte;
}
void Titre::setNomAction(string nom){
    nom_action=nom;
}
void Titre::setQte(double q){
    qte=q;
}
void Titre::ajouterQte(double q){
    qte+=q;
}
void Titre::retirerQte(double q){
    qte-=q;
}

ostream& operator<<(ostream& os,const Titre& t){
    cout<<t.nom_action<<";"<<t.qte<<endl;
    return os;
}
bool operator==(const Titre& t1,const Titre& t2){
    return (t2.nom_action==t1.nom_action && t1.qte==t2.qte);
}
Titre::~Titre(){}
