#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function

using namespace std;

// Place fileSum prototype (declaration) here
int fileSum(string filename);

int main() {

   string filename;
   int sum = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   
   sum = fileSum(filename);

   cout << "Sum: " << sum << endl;
   
   return 0;
}


// Place fileSum implementation here
int fileSum(string filename){ 
   //fileSum opens file, adds all the integers within the file, closes the file, and returns the sum
   ifstream inFS; //input file stream
   int num = 0;
   int sum = 0;

   //cout << "Opening file " << filename << endl;

   inFS.open(filename);

   if(!inFS.is_open()){
      cout << "Error opening " << filename << endl;
      exit(1);
   }

   while (!inFS.eof() && inFS.good()){
      inFS >> num;

      if (!inFS.fail()){
         sum = sum + num;
      }
   }

   inFS.close();

   return sum;

} 
