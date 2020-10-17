#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

void readData(const string &filename, vector<double> &angles, vector<double> &lift);
double interpolation(double reqAngle, const vector<double> &angles, const vector<double> &lift);
bool isOrdered(const vector<double> &angles);
void reorder(vector<double> &angles, vector<double> &lift);

int main(int argc, char* argv[]){    //argc indicates the # of command line arguments, argv is short for argument vector
    string filename;
    double reqAngle;
    vector<double> angles;
    vector<double> lift;
    string answer;

    filename = argv[1];

    readData(filename, angles, lift);

    if(isOrdered(angles)){
        cout << "is already ordered" << endl;
    }
    else{
        cout << "Not ordered" << endl;
        reorder(angles, lift);
    }

    cout << "Enter flight path angle:" << endl;
    cin >> reqAngle;
    int last = angles.size()-1;
    while((reqAngle < angles.at(0)) || (reqAngle > last)){
        cout << "Out of bounds. Enter another flight angle:" << endl;
        cin >> reqAngle;
    }
    interpolation(reqAngle,angles,lift);

    cout << "Do you want to enter another flight path angle?" << endl;
    cin >> answer;

    while((answer  == "Yes") || (answer == "yes")){
        cout << "Enter flight path angle:" << endl;
        cin >> reqAngle;
        interpolation(reqAngle,angles,lift);

        cout << "Do you want to enter another flight path angle?" << endl;
        cin >> answer;
    }

    return 0;
}

void readData(const string&filename, vector<double> &angles, vector<double> &lift){
    ifstream inFS;
    double tempAngle;
    double tempLift;

    inFS.open(filename);
    if (!inFS.is_open()){
        cout << "Error opening " << filename << endl;
        exit (1);  
    }
    while (inFS >> tempAngle >> tempLift){
        angles.push_back(tempAngle);
        lift.push_back(tempLift);
    }   

    int vecsize = angles.size();
    for(int i = 0; i< vecsize; ++i){
        cout << angles.at(i) << " " ;
    }
    cout << endl;
    for(int i = 0; i< vecsize; ++i){
        cout << lift.at(i) << " " ;
    }
    cout << endl;
}

double interpolation(double reqAngle, const vector<double> &angles, const vector<double> &lift){
    //fa= coefficient of lift for flight path angle a, fc= coefficient of lift for flight path angle c
    //need to find angles a and c such that a<b<c (a<reqAngle<c)  
    double b = 0.0;
    double fb = 0.0; 
    int vecsize = angles.size();
    
    //check if b exists in the data set
    for(int i = 0; i < vecsize; ++i){
        if (angles.at(i) == reqAngle){   //if requested angle is already in the data
            b = angles.at(i);
            fb = lift.at(i);  
            return fb;  
        }
    }

    //if angle not in data loop b will remain unchanged
    if (b != reqAngle ){
        double a = 0.0;
        double c = 0.0;
        double fa = 0.0;
        double fc = 0.0;
        b = reqAngle;
        
        for (int i = 0; i < vecsize - 1; ++i){
            if((reqAngle > angles.at(i)) && reqAngle < angles.at(i+1)){
                a = angles.at(i);
                c = angles.at(i+1);
                fa = lift.at(i);
                fc = lift.at(i+1);
            }
        }
        cout << "a:" << a << ", fa:" <<fa << endl << " b:" << b << endl << "c: " << c  << ", fc:" << fc << endl;
        //f(b) = f(a) + ((b - a)/(c - a))(f(c) - f(a))
        fb = fa + ((b-a)/(c-a))*(fc-fa);
        return fb;
    }

    //cout << "fb: " << fb << endl;
    return fb;
}

bool isOrdered(const vector<double> &angles){
    int vecsize = angles.size();
    int a = 0;

    for (int i = 0; i < vecsize-1; ++i){
        for(int j = i+1; j<vecsize; ++j){
            if(angles.at(i) > angles.at(j)){
                ++a;
            }
        }
    }
    //cout << endl << "a: " << a << endl;

    if (a == 0){
        return true;
    }
    else{
        return false;
    } 
}

void reorder(vector<double> &angles, vector<double> &lift){
    int vecsize = angles.size();
    double tempVal1 = 0.0;
    double tempVal2 = 0.0;

    for (int i  = 0; i < vecsize-1; ++i){
        for(int j = 1+i; j < vecsize; ++j){
            if (angles.at(j) < angles.at(i)){
                tempVal1 = angles.at(j);
                angles.at(j) = angles.at(i);     //swap values;
                angles.at(i) = tempVal1;

                tempVal2 = lift.at(j);
                lift.at(j) = lift.at(i);
                lift.at(i) = tempVal2;
            }
        }
    }

    for (int i = 0; i < vecsize; ++i){
        cout << angles.at(i) << " ";
    }
    cout << endl;
}




