#include "minFunc.h"
#include <iostream>
using namespace std;
const int * min(const int arr[], int arrSize) {
    //cout << "arrSize: " << arrSize << endl;
    if(arrSize == 0){
        return nullptr;
    }
    else if(arrSize == 1){
        return &arr[0];
    }
    else{
        const int * minf = min(arr,arrSize-1);
        if((arr[arrSize-1]) < *minf){
            return &arr[arrSize-1];
        }
        else{
            return minf;
        }
    }
}