#include <iostream>

using namespace std;

#include "Distance.h"

Distance::Distance(){
    feet  = 0;
    inches = 0.0;
}

Distance::Distance(unsigned ft, double in){
    //cout << "hello from Distance(a,b)\n";
    feet = ft;
    inches  = in;

    if(inches<0){
        inches = inches*(-1);
    }

    if(feet<0){
        feet = feet*(-1);
    }

    while (inches>=12){
        ++feet;
        inches = inches - 12;
    }
}

Distance::Distance(double in){
    inches  = in;
    feet = 0;

    if(inches<0){
        inches = inches*(-1);
    }

    if(feet<0){
        feet = feet*(-1);
    }

    while (inches>=12){
        ++feet;
        inches = inches - 12;
    }
}

unsigned Distance::getFeet() const{
    return feet;
}

double Distance::getInches() const{
    return inches;
}

double Distance::distanceInInches() const{

    return inches + feet*12; 
}

double Distance::distanceInFeet() const{

    return feet + (inches/12);
}

double Distance::distanceInMeters() const{
    //1 in = 0.0254 m

    return ((feet*12)+inches)*0.0254;
}

Distance Distance::operator+(const Distance &rhs) const{
 
    Distance sum;
    sum.feet = feet + rhs.feet;
    sum.inches = inches + rhs.inches;   

    sum.init();

    return sum;
}

Distance Distance::operator-(const Distance &rhs) const{
    Distance sub;

    sub.inches = ((feet*12)+inches) - ((rhs.feet*12)+rhs.inches);
    //cout << "-operator sub.inches: " << sub.inches << endl;

    sub.init();

    return sub;
}



ostream& operator<<(ostream &out, const Distance &rhs){
   
    //cout <<"hello from operator<<\n";
    out << rhs.getFeet() << "' " << rhs.getInches() << "\"";

    return out;
} 

void Distance::init(){
    //cout << "hello from init()\n";
    if(feet<0){
        feet = feet*(-1);
        cout << "feet in init: " << feet << endl;
    }

    if(inches<0){
        inches = inches*(-1);
        cout << "inches in init: " << inches << endl;
    }


    while(inches>=12){
        ++feet;
        inches = inches-12;
    }
}




