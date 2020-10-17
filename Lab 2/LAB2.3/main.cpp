#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>


using namespace std;

int main(int argc, char *argv[]) {
   
   string inputFile;
   string outputFile;
   
   // Assign to inputFile value of 2nd command line argument
   inputFile = argv[1];
   // Assign to outputFile value of 3rd command line argument
   outputFile = argv[2];
   // Create input stream and open input csv file.
   ifstream inFS; 
   inFS.open(inputFile);

   // Verify file opened correctly.
   // Output error message and return 1 if file stream did not open correctly.
   if (!inFS.is_open()){
      cout << "Error opening " << inputFile << endl;
      return 1;
   }
   // else {
   //    cout << inputFile << " opened correctly" << endl;
      
   // }
   
   // Read in integers from input file to vector.
   vector<int> vec;
   int num;
   char com;

   while (inFS >> num){
      inFS >> com; //to get the comma
      vec.push_back(num);
      
   }
   int vecsize = vec.size();
   // for(int i =0; i<vecsize; ++i){
   //    cout << vec.at(i);
   // }
   // cout << endl;
   
   // Close input stream.
   inFS.close();
   
   // Get integer average of all values read in.
   int sum = 0;
   int den = 0;
   double avg = 0.0;
   
   for(int i = 0; i < vecsize; ++i){
      sum = sum + vec.at(i);
      ++ den;
   }
   avg = sum/den;
   
   // Convert each value within vector to be the difference between the original value and the average.
   for (int i = 0; i < vecsize; ++i){
      vec.at(i) = vec.at(i) - avg;
   }
   
   // Create output stream and open/create output csv file.
   ofstream oFS;
   oFS.open(outputFile);

   // Verify file opened or was created correctly.
   // Output error message and return 1 if file stream did not open correctly.
   if (!oFS.is_open()){
      cout << "Error opening " << outputFile << endl;
      return 1;
   }
   // else{
   //    cout << outputFile << "opened correctly" << endl;
   // }
   
   // Write converted values into ouptut csv file, each integer separated by a comma.
   
   for (int i = 0; i < vecsize-1 ; ++i){
      oFS << vec.at(i) << ",";
   }
   oFS << vec.at(vecsize-1);  

   // Close output stream.
   oFS.close();
   
   return 0;
}