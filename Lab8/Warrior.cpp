#include "Warrior.h"
#include <iostream>
using namespace std;

Warrior::Warrior(const string& _name, double _health, double _attackStrength, string _allegiance)
    :Character(WARRIOR, _name, _health , _attackStrength){
    allegiance = _allegiance;
}

void Warrior::attack(Character & opp){
    if(opp.getType() == WARRIOR){
        Warrior& opponent = dynamic_cast<Warrior &>(opp);

        if(opponent.allegiance == this-> allegiance){
            cout << "Warrior " << this->name << " does not attack Warrior " << opp.getName() << "." << endl;
            cout << "They share an allegiance with " << this->allegiance <<"." << endl;
        }
        else{
            double damage = (this->health / MAX_HEALTH) * (this->attackStrength);
            opp.damage(damage);
            cout << "Warrior " << this->getName()<< " attacks " << opp.getName() << " --- SLASH!!" << endl;
            cout << opp.getName() << " takes " << damage << " damage." << endl;
        }
    }
    else{
        double damage = (this->health / MAX_HEALTH) * (this->attackStrength);
        opp.damage(damage);
        cout << "Warrior " << this->getName()<< " attacks " << opp.getName() << " --- SLASH!!" << endl;
        cout << opp.getName() << " takes " << damage << " damage." << endl;
    }
}
