#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Date.h"
using namespace std;


bool Date::cntrl_jour(int j) const{
   return (j<=31 && j>0);
};
bool Date::cntrl_mois(int m) const{
    return (m<=12 && m>0);
}
bool Date::cntrl_annee(int a) const{
    return (a<=2023 && a>2000);
}
bool Date::cntrl_format() const{
    return ((cntrl_jour(jour)) && (cntrl_mois(mois)) && (cntrl_annee(annee)));
}

void Date::set_jour(int nv_jour){
    if(cntrl_jour(nv_jour)){
        jour=nv_jour;
    }
}
void Date::set_mois(int nv_mois){
    if(cntrl_mois(nv_mois)){
        mois=nv_mois;
    }
}
void Date::set_annee(int nv_annee){
    if(cntrl_annee(nv_annee)){
        annee=nv_annee;
    }
}
bool annee_bissextile(int annee) {
    if (annee % 4 == 0) {
        if (annee % 100 == 0) {
            if (annee % 400 == 0) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return true;
        }
    }
    else {
        return false;
    }
}

bool Date::date_valide(){
    if (this->cntrl_format()==true){
        if (mois<8){
            if (mois%2==0){
                if (mois!=2){
                    return(jour<=30 && jour>0);
                }
                else {
                    if (annee_bissextile(annee)){
                        return (jour<=29 && jour>0);
                    }
                    else {
                        return (jour<=28 && jour>0);
                    }
                }
            }
            else {
                return(jour<=31 && jour>0);
            }
        }
        if (mois>=8) {
            if (mois%2==0){
                return(jour<=31 && jour>0);
            }
            else {
                return(jour<=30 && jour>0);
            }
        }
    }
    return false;
}

Date incrementer(Date &d){
    int jour=d.get_jour();
    int mois=d.get_mois();
    int annee=d.get_annee();
    int fev=28;
    if (mois<8){
        if (mois%2==0){
            if (mois!=2){
                if(jour<30){
                    ++jour;
                }
                else {
                    jour=1;
                    ++mois;
                }
            }
            if (mois==2){
                if (annee_bissextile(annee)){
                    fev=29;
                }
                if(jour<fev){
                    ++jour;
                }
                else {
                    jour=1;
                    ++mois;
                }
            }
        }
        else {
            if(jour<31){
                    ++jour;
                }
                else {
                    jour=1;
                    ++mois;
                }
        }
    }
    if (mois==12) {
        if(jour<31){
            ++jour;
        }
        else {
           jour=1;
            mois=1;
            ++annee;
        }
    }
    if ((mois>=8) && (mois<12)) {
        if (mois%2==0){
            if(jour<31){
                ++jour;
            }
            else {
                jour=1;
                ++mois;
            }
        }
        else {
            if(jour==30){
                ++mois; 
                jour=1;
            }
            else{
                ++jour;
            }
        }
    }

    d.set_jour(jour);
    d.set_mois(mois);
    d.set_annee(annee);
    return d;
}

Date decrementer(Date &d){
    int jour=d.get_jour();
    int mois=d.get_mois();
    int annee=d.get_annee();
    int fev=28;
    if (mois>1 && mois<8){
        if ((mois-1)%2==0){
            if ((mois-1)!=2){
                if(jour>1){
                    --jour;
                }
                else {
                    jour=30;
                    --mois;
                }
            }
            if ((mois-1)==2){
                if (annee_bissextile(annee)){
                    fev=29;
                }
                if(jour>1){
                    --jour;
                }
                else {
                    jour=fev;
                    --mois;
                }
            }
        }
        else {
            if(jour>1){
                    --jour;
                }
                else {
                    jour=31;
                    --mois;
                }
        }
    }
    if (mois==1) {
        if(jour>1){
            --jour;
        }
        else {
           jour=31;
            mois=12;
            --annee;
        }
    }
    if (mois>=8) {
        if ((mois-1)%2==0){
            if(jour>1){
                --jour;
            }
            else {
                jour=31;
                --mois;
            }
        }
        else {
            if(jour==1){        
                jour=30;        
                --mois;         
            }                  
            else{                
                --jour;         
            }                   
        }
    }
    
    d.set_jour(jour);
    d.set_mois(mois);
    d.set_annee(annee);
    return d;
}

Date operator+(Date& d, Date& f){
    int annee=d.get_annee();
    int som_mois=d.get_mois()+ f.get_mois();
    int i;
    int diff_m=12-som_mois;
    if (diff_m<0){
        d.set_mois(abs(diff_m));
        ++annee;
    }
    else {
        d.set_mois(som_mois);
    }
    i=0;
    do {
        d=incrementer(d);
        i++;
    }while(i!=f.get_jour());
    return d;
}


void Date::saisie_date(){
    bool date_valide=false;
    int c=0;
    
    cout<<"Entrer une date sous le format suivant (jj/mm/aaaa) : ";
    while (!date_valide){
        cin>>*this;
        if (this->date_valide()){
            date_valide=true;
        }
        else {
            c++;
            cout<<"Format Incorrect"<<endl;
            cout<<"Veuillez re-entrer une date valide sous le format suivant (jj/mm/aaaa) : ";
        }
    }
    if (c!=0){
        cout<<"Format Valide"<<endl;
    }
}
int main(){
    Date d1;
    Date d2;
    Date d;
    d1.saisie_date();
    
    cout<<"La date 1 est :"<<d1<<endl;
    cout<<"La jour 1 est :"<<d1.get_jour()<<endl;
    cout<<"Le mois 1 est :"<<d1.get_mois()<<endl;
    cout<<"L'annee 1 est :"<<d1.get_annee()<<endl;
    cout<<"La date 2 est :"<<d2<<endl;

    return 0;
}
