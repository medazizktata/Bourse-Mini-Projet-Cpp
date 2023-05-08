#ifndef TITRE_H_INCLUDED
#define TITRE_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Titre{
private:
    string nom_action;
    double qte;
public:
    Titre(string n="",double q=0);
    string getNomAction() const;
    double getQte() const;
    void setNomAction(string nom);
    void ajouterQte(double q);
    void retirerQte(double q);
    friend ostream& operator<<(ostream& flux,const Titre& t);
    friend bool operator==(const Titre& t1,const Titre& t2);
    ~Titre(){}
};


#endif // TITRE_H_INCLUDED
