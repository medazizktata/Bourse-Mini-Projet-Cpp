#ifndef SIMULATION_H_INCLUDED
#define SIMULATION_H_INCLUDED

using namespace std;

class Simulation{

private:

public:
    void executer(Bourse& bourse, Trader& trader, Date dateDebut, Date dateFin, double solde);

};

#endif // SIMULATION_H_INCLUDED
