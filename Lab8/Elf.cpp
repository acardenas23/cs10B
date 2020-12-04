#include "Elf.h"
#include <iostream>
using namespace std;

Elf::Elf(const string& _name, double _health, double _attackStrength, string fam)
    :Character(ELF, _name, _health, _attackStrength){
    family = fam;
    //Stores the elf's family name as a string.
}

void Elf::attack(Character & opp){
    if(opp.getType() == ELF){
        Elf &opponent = dynamic_cast<Elf &>(opp);

        if(opponent.family == this->family){
            cout << "Elf " << this->name << " does not attack Elf " << opp.getName() << "." << endl;
            cout << "They are both members of the " << family << " family." << endl;
        }
        //from different family
        else{
            double damage = (this->health / MAX_HEALTH) * (this->attackStrength);
            opp.damage(damage);
            cout << "Elf " << this->name << " shoots an arrow at " << opp.getName() << " --- TWANG!!" << endl;
            cout << opp.getName() << " takes " << damage << " damage." << endl;
        }
    }
    else{
        double damage = (this->health / MAX_HEALTH) * (this->attackStrength);
        opp.damage(damage);
        cout << "Elf " << this->name << " shoots an arrow at " << opp.getName() << " --- TWANG!!" << endl;
        cout << opp.getName() << " takes " << damage << " damage." << endl;
    }

}