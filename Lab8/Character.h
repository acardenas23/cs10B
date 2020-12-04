#include <string>

using namespace std;

#ifndef __CHARACTER_H__
#define __CHARACTER_H__

enum HeroType {WARRIOR, ELF, WIZARD};

const double MAX_HEALTH = 100.0;

class Character {
 protected:
	HeroType type;
	string name;
	double health;
	double attackStrength;

 public:
 	Character(HeroType _type, const string &_name, double _health, double _atttackStrength);
 	HeroType getType() const;
 	const string & getName() const;
 	int getHealth() const;
 	void damage(double d);
 	bool isAlive() const;
 	virtual void attack(Character &) = 0;
 };

#endif