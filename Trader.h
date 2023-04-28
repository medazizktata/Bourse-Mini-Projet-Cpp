#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Trader {
    public:
    Trader();
    void lancer_simulation(Date d, int n, double p);
    virtual int prendre_decision()=0;
    virtual void acceder_a_archive_des_prix()=0;
    private:
    int id;
};
class Humain : public Trader {
    public:
    Humain();
    void lancer_simulation(Date d, int c, double p);
    int prendre_decision();
    void acceder_a_archive_des_prix(Date d, int n, string nom); 
};
