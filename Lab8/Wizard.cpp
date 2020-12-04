#include "Wizard.h"
#include <iostream>
using namespace std;

Wizard::Wizard(const string& _name, double _health, double _attackStrength, int num)
    :Character(WIZARD, _name, _health, _attackStrength){
        rank = num;
}

void Wizard::attack(Character & opp){
    if(opp.getType() == WIZARD){
        Wizard& opponent = dynamic_cast<Wizard &> (opp);

        double damage = (attackStrength) * ((this->rank*1.0)/opponent.rank);
        opponent.damage(damage);

        cout << "Wizard " << this->name << " attacks " << opponent.name << " --- POOF!!" << endl;
        cout << opponent.name << " takes " << damage << " damage." << endl;
    }else{
        double damage = attackStrength;
        opp.damage(damage);
        cout << "Wizard " << this->name << " attacks " << opp.getName() << " --- POOF!!" << endl;
        cout << opp.getName() << " takes " << damage << " damage." << endl;
    }
}