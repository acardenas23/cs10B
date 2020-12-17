#include <iostream>
#include <string>

using namespace std;


void flipString(string &s);

int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}

//Implement the flipString function here
void flipString(string &s){

   if(s.size() <= 1){ //base case
      return;
   }
   else{
      string newstr = s.substr(1,s.size()-2); //newstr excludes first and last values
      //cout << "newstr: " << newstr << endl;
      flipString(newstr);
      s = s.at(s.size()-1) + newstr + s.at(0); //flips first and last values
      
   }
 
}


