#include <iostream>
#include <string>
using namespace std;
#include "Character.h"

Character::Character(HeroType _type, const string &_name, double _health, double _attackStrength){
    type = _type;
    name = _name;
    health = _health;
    attackStrength = _attackStrength;
}

HeroType Character:: getType()const{
    return type;
}

const string& Character::getName() const{
    return name;
}

int Character::getHealth() const{
    return health;
}

void Character::damage(double d){
    if(this->health-d >0){
        this->health = this->health - d;
    }
    else{
        this->health = 0;
    }
}

bool Character::isAlive() const{
    if(this->health > 0){
        return true;
    }
    else{
        return false;
    }
}
