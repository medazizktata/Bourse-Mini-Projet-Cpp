#include "bourse.h"
#include "BourseVector.h"

using namespace std;



Bourse::Bourse(int a){
    ab=a; // à enlever just pour verifier qlq chose
}


bool Bourse::estBourseFerme(BourseVector b,Date d){
    if(b.getActionsDisponiblesParDate(d).empty())
        return false;
    else
        return true;


}
