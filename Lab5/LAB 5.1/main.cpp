//include any standard libraries needed
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;


//  - Passes in an array along with the size of the array.
//  - Returns the mean of all values stored in the array.
double mean(const double array[], int arraySize);

//  - Passes in an array, the size of the array by reference, and the index of a value to be removed from the array.
//  - Removes the value at this index by shifting all of the values after this value up, keeping the same relative order of all values not removed.
//  - Reduces arraySize by 1.
void remove(double array[], int &arraySize, int index);


// - Passes in an array and the size of the array.
// - Outputs each value in the array separated by a comma and space, with no comma, space or newline at the end.
void display(const double array[], int arraySize);


const int ARR_CAP = 100;

int main(int argc, char *argv[]) {
   
   // verify file name provided on command line
   string filename;
   ifstream inFS;

   filename = argv[1]; //assign file from command line

   // open file and verify it opened
   inFS.open(filename);

   if(!inFS.is_open()){
      cout << "Error opening " << filename << endl;
   }

   // Declare an array of doubles of size ARR_CAP.
   double array[ARR_CAP];
    
   // Fill the array with up to ARR_CAP doubles from the file entered at the command line.
   double num;
   int size;

   for(size = 0; inFS >> num; size++){
         array[size] = num;
   }

   inFS.close();
   
   // Call the mean function passing it this array and output the 
   // value returned.
   cout << "Mean: " << mean(array,size) << endl;
    
   // Ask the user for the index (0 to size - 1) of the value they want to remove.
   int index;
   cout << "enter index of value to be removed (0 to " << size-1 << "):" << endl;
   cin >> index;

   cout << "Before removing value: ";
	
   // Call the display function to output the array.
   display(array,size);
   
   // Call the remove function to remove the value at the index
   // provided by the user.
   remove(array, size, index);
     
   // Call the display function again to output the array
   // with the value removed.
   cout << "After removing value: ";
   display(array,size);
   
   // Call the mean function again to get the new mean
   cout << "Mean: " << mean(array,size) << endl;

   
	return 0;
}

double mean(const double array[], int arraySize){
   double mean = 0;
   double sum = 0;
   int i;

   for(i=0; i<arraySize; ++i){
      sum = sum + array[i];
   }

   mean = sum/arraySize;

   return mean;
}

void remove(double array[], int &arraySize, int index){
   int i;
   --arraySize;
   for(i = index; i < arraySize; ++i){
      array[i] = array[i+1];
   }

   
}

void display(const double array[], int arraySize){
   int i;
   for(i = 0; i < arraySize-1; ++i){
      cout << array[i] << ", ";
   }
   cout << array[arraySize-1] << endl;
}
