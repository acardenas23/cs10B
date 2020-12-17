#include <iostream>

using namespace std;

#include "minFunc.h"

int main() {
   int arrSize;
   cout << "Enter size: " << endl;
   cin >> arrSize;
   cout << "Enter values:" << endl;
   if (arrSize > 0) {
      int arr[arrSize];
      for (int i = 0; i < arrSize; ++i) {
         cin >> arr[i];
      }
      const int *minLoc = min(arr, arrSize);
      cout << "minLoc: " << *minLoc << endl;
   }   
   return 0;
}
