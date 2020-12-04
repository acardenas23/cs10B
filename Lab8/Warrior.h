#ifndef __WARRIOR_H__
#define __WARRIOR_H__

using namespace std;
#include "Character.h"

class Warrior: public Character{
    private:
        string allegiance;
    public:
        Warrior(const string& _name, double _health, double _attackStrength, string _allegiance);
        void attack(Character & opp);
};

#endif