#ifndef __ELF_H__
#define __ELF_H__

using namespace std;
#include <iostream>
#include "Character.h"

class Elf: public Character{
    private:
        string family;

    public: 
        Elf(const string& _name, double _health, double _attackStrength, string fam);
        void attack(Character & opp);
};

#endif