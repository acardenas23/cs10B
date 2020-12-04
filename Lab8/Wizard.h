#ifndef __WIZARD_H__
#define __WIZARD_H__

#include <iostream>
using namespace std;
#include "Character.h"

class Wizard : public Character{
    private:
        int rank;

    public:
        Wizard(const string& _name, double _health, double _attackStrength, int num);
        void attack(Character & opp);
};

#endif